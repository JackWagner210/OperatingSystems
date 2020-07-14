#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *const argv[])
{
    //char *const av[] = {"ls", "-l", "-t", (char *)0};
    pid_t pid;

    switch(pid = fork())
    {
	case -1: perror("Fork Failed");
	         break;
	case 0:
		execvp("/bin/ls", argv);
		perror("Exec failed");
		break;
	default: wait((int *)0);
		 printf("%sCommand Completed\n");
		 return 0;
    }
    return 0;
}


