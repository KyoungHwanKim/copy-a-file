#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int i = argc;
	printf("ARGC : %d\n", argc);
	
	if ( argc < 3 ) {
		printf("Usage : %s <filename1> <filename2> ... <directory name>\n", argv[0]);
		return 0;
	}
	
	int j;
	char *path[] = {};
	strcpy(path, argv[i - 1]);

	for (j = 1; j <= i - 2; j++) {
		
		FILE *fd, *dest;
		char buf[257];
		int len;
		
		fd = fopen(argv[j], "r");
		
		char *p[] = {};
		strcpy(p, path);
		strcat(p, "/");
		//printf("%s\n", p);
		
		dest = fopen(strcat(p, argv[j]), "w");
		
		while (len = fread(buf, 1, 256, fd)) {
			buf[len] = '\0';
			fwrite(buf, 1, len, dest);
			printf("Length : %d\n", len);
			printf("%s\n", buf);
		}
		
		fclose(dest);
		fclose(fd);
	}
	

	return 0;
}
