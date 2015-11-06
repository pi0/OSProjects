#include <iostream>
#include "MidlCommon.h"
#include "..\gen\Fact_h.h"
#include <conio.h>

int main()
{

	// Get Server URL
	char host[255] = { 0 };
	std::cout << "Please Enter Host Address: ";
	std::cin >> host;

	// Create Binding String
	unsigned char* szStringBinding = NULL;
	RpcStringBindingComposeA(NULL,RPC_CSTR("ncacn_ip_tcp"),RPC_CSTR(host),RPC_CSTR("8080"),NULL,&szStringBinding);
	
	// Set Bindings
	RpcBindingFromStringBindingA(szStringBinding,&ServerBinding);
	
	// Ask User For input
	int n = 0;
	std::cout << "Please enter a number: ";
	std::cin >> n;

	// Call Remote Method
	RpcTryExcept
	{
		int r=Fact(n);
		std::cout<< "Server Response: " << r << std::endl;
	}
	RpcExcept(1)
	{
		std::cerr << "RPC Error: " << RpcExceptionCode() << std::endl;
	}
	RpcEndExcept
	
	RpcStringFreeA(&szStringBinding);

	RpcBindingFree(&ServerBinding); 

	getch();
	
}
