#include "Pipe.h"


void WriteToPipe(HANDLE hndl,char* _msg) {

    char msg[PIPE_BUFF_SIZE];
    strcpy(msg, _msg);

    DWORD w_b;
	bool ok = WriteFile(hndl, msg, PIPE_BUFF_SIZE, &w_b, NULL);

    if (ok)
        printf("Parent:: Sent\n");

}


char* ReadFromPipe(HANDLE hndl) {

	char *msg=new char[PIPE_BUFF_SIZE];
	ZeroMemory(msg,PIPE_BUFF_SIZE);
	
	DWORD read;
	bool ok;

	do
		ok = ReadFile(hndl,msg,PIPE_BUFF_SIZE,&read,NULL);
	while(!ok || read==0);

	return msg;

}