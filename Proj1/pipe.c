#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
   
    char *argv[] = {"./pre", (char *)0};
    char *argc[] = {"./sort", (char *)0};
    
    int p[2];
    

    if(pipe(p) == -1)
        perror("Pipe Failed.");
    
    pid = fork();

    if(pid < 0)
    {
        printf("%sFork Failed.");
	return 1;
    }
    else if (pid == 0)
    { 
	close(p[0]);
	execvp(argv[0], argv);
    }
    else
    {
    	close(p[1]);
	dup2(p[1], 0);
	close(p[0]);
	execvp(argc[0], argc);
    }


 /*
    if(pid < 0)
	perror("Fork Fail");
    else if(pid == 0)
    {
	execl("/bin/", "./pre", (char *)0);
	perror("Exec Fail");
    }
    else
    {
	wait((int *)0);
	printf("%sPre Completed\n");
	return 0;
    }*/

    return 0;
}
