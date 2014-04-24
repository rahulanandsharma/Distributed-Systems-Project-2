/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include<sys/stat.h>
#include<unistd.h>
#include<libgen.h>
#include "interface.h"
#define BUFFER_SIZE 65536
int *
filewrite64k_1_svc(char *filename, long offset, char *data,  struct svc_req *rqstp)
{


char *bname;
    char *path2 = strdup(filename);
    bname = basename(path2);
strcpy(filename,bname);
	static int  result;
	char  temp[1010];
	strcpy(temp,filename);
	//printf("%ld\n",offset);
	
	char * fullname;
	fullname=strcat(filename,"/chunk");
char str[1500];
sprintf(str, "%ld", offset);
fullname=strcat(fullname,str);
//printf("%s\n",fullname);
//printf("%s\n",temp);

char  gob[1010]="mkdir -p ";
char*g1=temp;
char*g2=gob;
g1=strcat(g2,g1);
//printf("%s\n",g1);
//printf("%s\n",data);
//if(offset==1)
printf("Client sent the file %s with offset %ld\n",filename,offset);
system(g1);
  // fwrite(str , 1 , sizeof(str) , fp );

FILE *fp;
     fp = fopen( fullname, "w" );
   fwrite(data , 1 , BUFFER_SIZE , fp );
   fclose(fp);
  data=NULL;


result=1;

	return &result;
}

long *
numfilechunks_1_svc(char *filename,  struct svc_req *rqstp)
{
	static long  result;
char  gob[1010]="ls -l ";
filename=strcat((char *)gob,filename);
filename=strcat(filename," | wc -l > /tmp/numchunks.txt");
system(filename);
//printf("%s\n",filename);
  FILE* file = fopen ("/tmp/numchunks.txt", "r");
long *i;
long l;
  fscanf (file, "%ld", &l);
l--;
if(l<=0)
l=0;
printf("Client Queried for Number of Chunks => %ld\n",l);
    
result=l;



	/*
	 * insert server code here
	 */

	return &result;
}

char **
fileread64k_1_svc(char *filename, long offset,  struct svc_req *rqstp)
{
	static char * result;
char * output;

char * fullname;
	fullname=strcat(filename,"/chunk");
char str[1500];
sprintf(str, "%ld", offset);
fullname=strcat(fullname,str);
	

printf("Client received the file %s with offset %ld\n",filename,offset);


FILE *fp;
   fp = fopen(fullname , "r");
result=(char *)malloc(sizeof(char*)*65536);
fread(result, BUFFER_SIZE, 1, fp);
//printf("%ld",sizeof(result));

fclose(fp);
	/*
	 * insert server code here
	 */

	return &result;
}
