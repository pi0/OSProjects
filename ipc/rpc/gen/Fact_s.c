

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Oct 16 23:28:56 2015
 */
/* Compiler settings for src\Fact.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>
#include "Fact_h.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   37                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _Fact_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } Fact_MIDL_TYPE_FORMAT_STRING;

typedef struct _Fact_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } Fact_MIDL_PROC_FORMAT_STRING;

typedef struct _Fact_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } Fact_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

extern const Fact_MIDL_TYPE_FORMAT_STRING Fact__MIDL_TypeFormatString;
extern const Fact_MIDL_PROC_FORMAT_STRING Fact__MIDL_ProcFormatString;
extern const Fact_MIDL_EXPR_FORMAT_STRING Fact__MIDL_ExprFormatString;

/* Standard interface: Server, ver. 1.0,
   GUID={0x00000001,0xEAF3,0x4A7A,{0xA0,0xF2,0xBC,0xE4,0xC3,0x0D,0xA7,0x7E}} */


extern const MIDL_SERVER_INFO Server_ServerInfo;

extern const RPC_DISPATCH_TABLE Server_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE Server___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x00000001,0xEAF3,0x4A7A,{0xA0,0xF2,0xBC,0xE4,0xC3,0x0D,0xA7,0x7E}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&Server_v1_0_DispatchTable,
    0,
    0,
    0,
    &Server_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE Server_v1_0_s_ifspec = (RPC_IF_HANDLE)& Server___RpcServerInterface;

extern const MIDL_STUB_DESC Server_StubDesc;


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const Fact_MIDL_PROC_FORMAT_STRING Fact__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Fact */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter n */

/* 24 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 26 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const Fact_MIDL_TYPE_FORMAT_STRING Fact__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const unsigned short Server_FormatStringOffsetTable[] =
    {
    0
    };


static const MIDL_STUB_DESC Server_StubDesc = 
    {
    (void *)& Server___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    0,
    0,
    0,
    0,
    Fact__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

static const RPC_DISPATCH_FUNCTION Server_table[] =
    {
    NdrServerCall2,
    0
    };
static const RPC_DISPATCH_TABLE Server_v1_0_DispatchTable = 
    {
    1,
    (RPC_DISPATCH_FUNCTION*)Server_table
    };

static const SERVER_ROUTINE Server_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)Fact
    };

static const MIDL_SERVER_INFO Server_ServerInfo = 
    {
    &Server_StubDesc,
    Server_ServerRoutineTable,
    Fact__MIDL_ProcFormatString.Format,
    Server_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

