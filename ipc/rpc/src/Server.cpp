#include <iostream>
#include "MidlCommon.h"
#include "..\gen\Fact_h.h"


int main()
{
	
	// Create Handle
	RpcServerUseProtseqEpA(RPC_CSTR("ncacn_ip_tcp"),10, RPC_CSTR("8080"),NULL);

	// Register Server Inrerface
	RpcServerRegisterIf2(
		Server_v1_0_s_ifspec,
		NULL, NULL, RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,10,(unsigned)-1,SecurityCallbackOK
	);

	// Start Listening
	std::cout << "Listening on port 8080 ..." << std::endl;
	RpcServerListen(1,10,FALSE);

}

// Server Executable Methods
int Fact(int n) {
	std::cout << "Responsing to Fact(" << n << ")" << std::endl;
	int r = 1;
	for (int i = 1; i <= n; i++)
		r *= i;
	return r;
}
