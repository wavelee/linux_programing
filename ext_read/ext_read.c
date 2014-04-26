/*
 * =====================================================================================
 *
 *       Filename:  ext_read.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年04月26日 09时49分46秒
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

#define BUFSIZE	1024
int main(int argc, char *argv[]){
	int fd = -1,i;
	ssize_t size = -1;
	char buf[BUFSIZE + 1];
	char filename[] = "test.txt";
	
	fd = open(filename,O_RDONLY);
	if (-1 == fd){
		printf("Open file %s failure,fd:%d\n",filename,fd);
		close(fd);
		return -1;
	}else{
		printf("open file %s success,fd:%d",filename,fd);
		do{
			size = read(fd,buf,BUFSIZE);
			if (-1 == size){
				close(fd);	
				printf("read file error occurs!\n");
				return -1;
			}else if (0 < size){
				printf("read %d bytes:",size);	
				printf("\"");
				for (i = 0;i < size;i++){
					printf("%c",*(buf+i));
				}
				printf("\"");
			}else{
				printf("reach the end of file!\n");
			}
		}while(size);
		close(fd);
	}
	
	return 0;
}
