// THE HEADER FILES WE NEED
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
// THIS BUFFER HAS A CONSTANT SIZE, NEED TO CHANGE IT LATER
char buffer[1024];

void gcopy(int old, int new)
{
	int count;
	while((count = read(old,buffer,sizeof(buffer))) > 0)
	{
		write(new,buffer,count);
	}
}

int main(int argc, char **argv)
{
	// THE OLD AND NEW FILES
	int fold, fnew;
	if(argc!=3)
	{
		// THIS MEANS THE COPY FUNCTION CANNOT WORK.
		printf("ERROR\n 3 ARGS REQUIRED ONLY %d FOUND\n",argc-1);
		return -1;
	}
	fold = open(argv[1], O_RDONLY);
	if(fold == -1)
	{
		printf("ERROR READING OLD FILE : %s\nTRY AGAIN\n",argv[1]);
		return -1;
	}
	fnew = open(argv[2], O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);
	if(fnew == -1)
	{
		printf("ERROR READING NEW FILE : %s\nTRY AGAIN\n",argv[2]);
		close(fold);
		return -1;
	}
	gcopy(fold,fnew);
	return 0;
}
