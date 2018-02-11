#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	struct stat *stat;
	int fd = open("hello.txt", O_RDWR);

	fstat(fd, &stat);

	char *text;
	
	text = mmap(NULL, stat->st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if(text)
	{
		text[0] = 'J';
	}
	else
	{
		printf("mmap failed!\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
