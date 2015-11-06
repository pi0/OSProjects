#ifndef CHILD_H
#define CHILD_H

#include "common.h"

class Child{

public:
	Child();

private:
	HANDLE h_stdin,h_stdout;

	void DO(char* input);

};


#endif //CHILD_H
