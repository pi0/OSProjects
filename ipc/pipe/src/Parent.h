#ifndef PARENT_H
#define PARENT_H

#include "common.h"
#include "Child.h"

class Parent {

public:
    Parent(char* commandline);

private:
    
	char* commandline;

	PROCESS_INFORMATION pi;

	HANDLE child_in_r,child_in_w;//Child's STDIN
	HANDLE child_out_r,child_out_w;//Child's STDOUT

    void createChild();
    void createPipe();

};

#endif //PARENT_H
