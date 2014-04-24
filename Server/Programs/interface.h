/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _INTERFACE_H_RPCGEN
#define _INTERFACE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct filewrite64k_1_argument {
	char *filename;
	long offset;
	char *data;
};
typedef struct filewrite64k_1_argument filewrite64k_1_argument;

struct fileread64k_1_argument {
	char *filename;
	long offset;
};
typedef struct fileread64k_1_argument fileread64k_1_argument;

#define RPC 0x20134088
#define INTERFACE 1

#if defined(__STDC__) || defined(__cplusplus)
#define FILEWRITE64K 1
extern  int * filewrite64k_1(char *, long , char *, CLIENT *);
extern  int * filewrite64k_1_svc(char *, long , char *, struct svc_req *);
#define NUMFILECHUNKS 2
extern  long * numfilechunks_1(char *, CLIENT *);
extern  long * numfilechunks_1_svc(char *, struct svc_req *);
#define FILEREAD64K 3
extern  char ** fileread64k_1(char *, long , CLIENT *);
extern  char ** fileread64k_1_svc(char *, long , struct svc_req *);
extern int rpc_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define FILEWRITE64K 1
extern  int * filewrite64k_1();
extern  int * filewrite64k_1_svc();
#define NUMFILECHUNKS 2
extern  long * numfilechunks_1();
extern  long * numfilechunks_1_svc();
#define FILEREAD64K 3
extern  char ** fileread64k_1();
extern  char ** fileread64k_1_svc();
extern int rpc_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_filewrite64k_1_argument (XDR *, filewrite64k_1_argument*);
extern  bool_t xdr_fileread64k_1_argument (XDR *, fileread64k_1_argument*);

#else /* K&R C */
extern bool_t xdr_filewrite64k_1_argument ();
extern bool_t xdr_fileread64k_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_INTERFACE_H_RPCGEN */
