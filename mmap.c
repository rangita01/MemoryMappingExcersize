#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
	struct stat stat;

	int fd = open("hello.txt", O_RDWR);

	if(fd > 0)
	{
		fstat(fd, &stat);
	}
	else
	{
		printf("File failed to open!\n");
		return EXIT_FAILURE;
	}

	char *text;
	
	text = mmap(NULL, stat.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

	text[0] = 'J';

	return EXIT_SUCCESS;
}
