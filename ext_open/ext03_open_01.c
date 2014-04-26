/*
 * =====================================================================================
 *
 *       Filename:  ext03_open_01.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年04月25日 22时21分41秒
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

int main(int argc,char *argv[]){
	int fd = -1;
	char filename[] = "test.txt";
	/*创建文件*/
	fd = open(filename, O_RDWR|O_CREAT|O_EXCL,S_IRWXU);	
	/*文件已存在*/
	if (-1 ==  fd){
		printf("Open file %s failure!,fd:%d\n",filename,fd);
		/*打开文件*/
		fd = open(filename, O_RDWR);
		printf("fd:%d\n",fd);
	}else{
		printf("Open file %s success,fd:%d\n",filename,fd);
	}

	/*关闭文件*/
	close(fd);
	
	return 0;
} 
