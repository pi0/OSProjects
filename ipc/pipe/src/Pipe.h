#ifndef PIPE_H
#define PIPE_H

#include "common.h"

#define PIPE_BUFF_SIZE 512

void WriteToPipe(HANDLE hndl,char* _msg);

char* ReadFromPipe(HANDLE hndl);


#endif // !PIPE_H


