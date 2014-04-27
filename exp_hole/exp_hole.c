/*
 * =====================================================================================
 *
 *       Filename:  exp_hole.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年04月26日 20时26分15秒
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
#include <stdio.h>
int main(int argc, char *argv[]){
	int fd = -1, i;
	ssize_t size = -1;
	off_t offset = -1;
	char buf1[] = "01234567890";
	char buf2[] = "ABCDEFGHIJKLMN";
	char filename[] = "hole.txt";
	
	int len1 = sizeof(buf1) - 1;
	int len2 = sizeof(buf2) - 1;
 	printf("sizeof(buf1) = %d ,sizeof(buf2) = %d\n",sizeof(buf1),sizeof(buf2));	
	fd = open(filename, O_RDWR|O_CREAT, S_IRWXU);
	if (-1 == fd){
		return -1;
	}
	
	size =  write(fd, buf1, len1);
	if (size != len1){
		close(fd);
		return -1;
	}
	
	offset = lseek(fd, 32, SEEK_SET);
	if (-1 == offset){
		close(fd);
		return -1;
	}
	
	size = write(fd, buf2, len2);
	if (size != len2){
		close(fd);
		return -1;
	}
	
	close(fd);
	return 0;
}

