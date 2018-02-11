#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	struct stat stat;

	int fd = open("hello.txt", O_WRONLY);

	printf("About to open file.\n");

	if(fd > 0)
	{
		fstat(fd, &stat);
	}
	else
	{
		printf("File failed to open!\n");
		return EXIT_FAILURE;
	}

	printf("File opened with descriptor %d\n", fd);

	char *text;
	
	printf("Stats for mmap are as follows:\nsize:%ld\nfd:%d\n", stat.st_size, fd);

	text = mmap(NULL, stat.st_size, PROT_WRITE, MAP_SHARED, fd, 0);

	if(text)
	{
		printf("About to attempt letter change...\n");
		text[0] = 'J';
	}
	else
	{
		printf("mmap failed!\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
