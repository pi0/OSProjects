#include "common.h"
#include "Parent.h"
#include <conio.h>

int main(int argc, char *argv[]) {

	//Check if running as Parent Or Child

	if(argc==1) {
		Parent parent(argv[0]);
		getch();
	}else {
		Child();
	}

	return 0;
}