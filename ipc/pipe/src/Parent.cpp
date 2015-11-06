#include "Parent.h"
#include <conio.h>
#include "Pipe.h"

Parent::Parent(char *commandline) {
    this->commandline = commandline;

    printf("Parent:: Started\n");

	// Create A Pipe For Commonucation
    createPipe();

	// Read User input
	char n[255];
	printf("Enter a number: ");
	scanf("%s",&n);
	WriteToPipe(child_in_w,n);

	// Create A Child Process 
	createChild();
    
	// Read From Pipe Channel For Results
	while(true){
		char* r = ReadFromPipe(child_out_r);
		printf("Parent Read From Pipe:: %s\n",r);
	}

}

void Parent::createPipe() {

    // Security Attributes
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    bool ok;

    // Child's STDOUT
    ok = CreatePipe(&child_out_r, &child_out_w, &saAttr, 0);
    ok &= SetHandleInformation(child_out_r, HANDLE_FLAG_INHERIT, 0);// Child chan't Read it's STDOUT!

    // Child's STDIN
    ok &= CreatePipe(&child_in_r, &child_in_w, &saAttr, 0);
    ok &= SetHandleInformation(child_in_w, HANDLE_FLAG_INHERIT, 0);//Child can't Write to it's STDIN!

    if (!ok)
        printf("Parent:: There was an error on creating Pipe\n");

}


void Parent::createChild() {

    // Process Information
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

    // Startup Info
    STARTUPINFOA si;
    ZeroMemory(&si, sizeof(STARTUPINFOA));
    si.cb = sizeof(STARTUPINFOA);
    si.dwFlags |= STARTF_USESTDHANDLES;
    si.hStdInput = this->child_in_r;
    si.hStdOutput = this->child_out_w;
    si.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    // Command Line
	char cmd[255]={0};
	sprintf(cmd,"%s child",this->commandline);
	
    // Start the child process.
	bool ok = CreateProcessA(NULL,cmd, NULL, NULL, TRUE/*inherit handles*/, 0, NULL, NULL, &si, &pi);
    if (!ok) {
        printf("Parent:: Error Creating Process (%d)", GetLastError());
        return;
    }

    // Wait until child process exits.
    //WaitForSingleObject(pi.hProcess, INFINITE);
}
