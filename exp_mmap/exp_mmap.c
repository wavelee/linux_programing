/*
 * =====================================================================================
 *
 *       Filename:  exp_mmap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年04月27日 11时13分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiYB (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>/*mmap*/
#include <string.h>/*memset warning*/
#include <stdio.h>

#define FILELENGTH 80

int main(int argc, char *argv[]){
	
	int fd = -1;
	char buf[] = "quick brown fox jumps over the lazy dog";
	
	char *ptr = NULL;
	/*open mmap.txt,*/
	fd = open("mmap.txt",O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
	if (-1 == fd){
		return -1;
	}
	
	lseek(fd, FILELENGTH, SEEK_SET);	

	write(fd, " ", 1);

	ptr = (char *)mmap(NULL, FILELENGTH, PROT_READ|PROT_WRITE, MAP_SHARED,
				fd, 0);
	
	if ((char *)-1 == ptr){
		printf("mmap failure!\n");
		close(fd);
		return -1;
	}

//	close(fd);	
	memcpy(ptr+16, buf, strlen(buf));

	munmap(ptr, FILELENGTH);
	
	close(fd);
	return 0;
}

