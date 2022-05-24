#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	setuid(0);
	char cmd[1024];
	int count = 0; 
	while(argv[++count] != NULL);
	strcpy(cmd,"");
       // strcat(cmd,"/usr/bin/bash -c '");
	if (count>1){strcat(cmd,"echo");strcat(cmd," ");}
	if (count>2){
	strcat(cmd,argv[1]);strcat(cmd,":");
	strcat(cmd,argv[2]);strcat(cmd,"|/usr/sbin/chpasswd");
	}
        ///strcat(cmd,"'");
        //printf(cmd);
	return system(cmd);
	//return system("echo etapadmin:1|/usr/sbin/chpasswd");

}
