#include "Child.h"
#include "Pipe.h"

Child::Child() {

	fprintf(stderr,"Child:: Started\n");

	//Get STDIN and STDOUT Handles for Piping
	h_stdin = GetStdHandle(STD_INPUT_HANDLE); 
	h_stdout = GetStdHandle(STD_OUTPUT_HANDLE); 

	while(true){
		char* r = ReadFromPipe(h_stdin);
		DO(r);//Main Function!
	}

}


void Child::DO(char* input) {

	fprintf(stderr,"Child:: Proccessing: %s\n",input);

	//Convert input to number
	int a = atoi(input);

	//Calculate Factorial
	int r=1;
	for(int i=1;i<=a;i++)
		r*=i;

	//Convert Result to String
	char result[255]={0};
	sprintf(result,"%d",r);

	//Write To Pipe
	WriteToPipe(h_stdout,result);

}