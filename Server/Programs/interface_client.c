/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "interface.h"
#define BUFFER_SIZE 65536

void
rpc_1(char *host,char* fname)
{


	CLIENT *clnt;
	int  *result_1;
	char *filewrite64k_1_filename;
	long filewrite64k_1_offset;
	char *filewrite64k_1_data;
	long  *result_2;
	char *numfilechunks_1_filename;
	char * *result_3;
	char *fileread64k_1_filename;
	long fileread64k_1_offset;
	char *fileread64k_1_dataRead;

#ifndef	DEBUG
	clnt = clnt_create (host, RPC, INTERFACE, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

FILE *fp;
   fp = fopen(fname , "r");

  char buffer[BUFFER_SIZE];
 fseek(fp, 0L, SEEK_END);
int size = ftell(fp);
fseek(fp, SEEK_SET,0);
int chunks=size/BUFFER_SIZE;
long i;
for(i=1;i<=chunks;i++)
{
if (fread(buffer, sizeof buffer, 1, fp) == 1)
{
 //printf("%ld %s",i,buffer);
filewrite64k_1_filename=fname;
filewrite64k_1_offset=i;
filewrite64k_1_data=buffer;
result_1 = filewrite64k_1(filewrite64k_1_filename, filewrite64k_1_offset, filewrite64k_1_data, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}

}
else
break;
}
fclose(fp);



	numfilechunks_1_filename=fname;
	result_2 = numfilechunks_1(numfilechunks_1_filename, clnt);
	if (result_2 == (long *) NULL) {
		clnt_perror (clnt, "call failed");
	}
printf("%ld\n",*result_2);
fileread64k_1_filename=fname;
fileread64k_1_offset=1;
fileread64k_1_dataRead=""	;
	result_3 = fileread64k_1(fileread64k_1_filename, fileread64k_1_offset, clnt);
	if (result_3 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
	}
printf("%s\n",*result_3);

#ifndef	DEBUG




	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	char *fname;
//printf("testing\n");
	if (argc < 3) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
//printf("testing\n");
	host = argv[1];
//printf("%s\n",host);
	fname=argv[2];
//printf("%s\n",fname);
	rpc_1(host,fname);
exit (0);
}
