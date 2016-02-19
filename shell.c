#include  <stdio.h>
#include  <sys/types.h>

void  split(char *commandline, char **splitter)
{
     while (*commandline != '\0') {       
          while (*commandline == ' ' || *commandline == '\t' || *commandline == '\n')
               *commandline++ = '\0';     
          *splitter++ = commandline;          
          while (*commandline != '\0' && *commandline != ' ') 
               commandline++;             
     }
     *splitter = '\0';                 
}

void  execute(char **splitter)
{
     execvp(*splitter, splitter);
}

void  main(void)
{
     char  commandline[500];             
     char  *splitter[50];              

     while (1) {                   
          printf("Shell -> ");     
          gets(commandline);              
          printf("\n");
          split(commandline, splitter);       
          if (strcmp(splitter[0], "exit") == 0)  
               exit(0);                            
          execute(splitter);           
     }
}
//