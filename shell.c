#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <sys/types.h>
#include  <fcntl.h>
#include  <unistd.h>

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

void  ChildProcess(char **splitter)
{
     
     execvp(*splitter, splitter);
     
     
}

void  ParentProcess(char **splitter)
{
     //execvp(*splitter, splitter);
     
}



void execute_parent(char **splitter)
{
}    

int main(int argc, char **argv)
{
     char  commandline[500];             
     char  *splitter[50]; 
     pid_t  pid;
     int status;             
     
      while(1)              
      {    printf("\nShell -> ");     
          gets(commandline);              
          printf("\n");
          
          split(commandline, splitter); 
          if (strcmp(splitter[0], "exit") == 0)  
               exit(0); 
            
                  
                  
                  pid = fork();
                  if (pid == -1)
                  {
                      // error, failed to fork()
                  } 
                  
                   if (pid == 0)
                  { 

                      if (splitter[1]!=NULL && !strcmp(splitter[1], "&"))
                      {
                        execvp(splitter[0],splitter);
                      }



                      if (strcmp(splitter[0], "ls") == 0)  
                      {
                        //int file=open(splitter[2],O_WRONLY);
                        //dup2(file,1);
                        execvp("ls", splitter);
                      }
                       
                      if(!strcmp(splitter[0],"clear") || !strcmp(splitter[0],"cc") || !strcmp(splitter[0],"mkdir") || !strcmp(splitter[0],"rmdir") || !strcmp(splitter[0],"rm"))
                      {
                        execvp(splitter[0],splitter);
                      }
                      
                      else
                      {
                        execvp(splitter[0],splitter);
                        
                      }
                    _exit(EXIT_FAILURE); 

                  
                }
                  else 
                  {
                      int status;
                     if (splitter[1]!=NULL && !strcmp(splitter[1], "&"))  
                      {
                      
                      }
                      else
                      {
                        waitpid(pid, &status, 0);
                      }  
                         
                  } 

          


           
      }       
                                     
                     
     
    
}
//