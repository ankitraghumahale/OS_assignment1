#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	char c = '\0';
        char c1[20];
        char command[20];
        char complete_command[50];
	int len=0,i=0;
        strcpy(c1,"/bin/");
	printf("\nminish >");
	while(c != EOF) {
	       	
                
                scanf("%s",command);
                strcpy(complete_command,strcat(c1,command));              
               // strcpy(complete_command,command);
	       // printf("%s",complete_command);
		execve(complete_command, argv, envp);
		c=getchar();
		if(c == '\n')
	        printf("\nminish >");
	}
	printf("\n");
	return 0;
}

