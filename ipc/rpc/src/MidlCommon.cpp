#include "MidlCommon.h"

void* __RPC_USER midl_user_allocate(size_t size)
{
	return malloc(size);
}

void __RPC_USER midl_user_free(void* p)
{
	free(p);
}

RPC_STATUS CALLBACK SecurityCallbackOK(RPC_IF_HANDLE hInterface, void* pBindingHandle)
{
	return RPC_S_OK;
}