/*
 * =====================================================================================
 *
 *       Filename:  ext_write.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年04月26日 10时53分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiYB (), 
 *   Organization:  
 *
 * =====================================================================================
 */
/*write 函数使用*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int fd = -1, i;
	ssize_t size = -1;
	int input = 0;
	
	/*存放数据的缓冲区*/
	char buf[] = "quick brown fox jumps over the lazy dog\n";
	
	char filename[] = "test.txt";
	
	/*打开文件*/	
	fd = open(filename,O_RDWR);
	/*如果文件不存在，则报错*/
	if (-1 == fd){
		printf("Open file %s failure,fd:%d\n",filename,fd);
		close(fd);
		return -1;
	}else{
		printf("Open file %s success,fd:%d\n",filename,fd);
	}
	
	/*将数据写入文件*/
	size = write(fd,buf,strlen(buf));
	printf("write %d bytes to file %s\n",size,filename);
	close(fd);
	
	return 0;

}

