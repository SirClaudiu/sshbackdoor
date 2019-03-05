/*
 * Sil v1.0 Tiny banner grabber by sacrine(C)
 * http://www.netric.org // sacrine@netric.org
 * irc.netric.org // #netric
 *
 * Greets: all members of Netric, my girlfriend ;)
 * Mon Apr 29 00:49:06 2002
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>

 int main(int argc, char *argv[])
 {
	 char grab[911];
	 int port,sock;
	 struct hostent *aap;
	 struct sockaddr_in addr;
	 
	 if(argc<2) { fprintf(stderr,"%s <host> <port>\n",argv[0]);
		 exit(1); }
	 if(argc>2) { port=atoi(argv[2]); }
	 if((aap=(struct hostent *)gethostbyname(argv[1]))==NULL) {
		 perror("gethostbyname()");
		 exit(1); }
         if((sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))<0)  {
		 perror("socket()");
		 exit(1); }             addr.sin_family=AF_INET;
					addr.sin_port=htons(port);
					
	 	 memcpy((char *)&addr.sin_addr,(char *)aap->h_addr,aap->h_length);
		 if(connect(sock,(struct sockaddr *)&addr,sizeof(addr))!=0) {
	         perror("connect()");
		 exit(0); }			fflush(stdin);
		 				read(sock,&grab,910);
		 				printf("%s",grab);
		 				return(0);
  }

