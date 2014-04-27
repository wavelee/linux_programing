/*
 * =====================================================================================
 *
 *       Filename:  ext_seek.c
 *
 *    Description:   use lseek function to test std I/O is support seek operator or not 
 *
 *        Version:  1.0
 *        Created:  2014年04月26日 13时22分14秒
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
	off_t offset = -1;
	offset = lseek(stdin, 0, SEEK_CUR);

	if (-1 == offset){
		printf("STDIN can not seek!\n");
		return -1;
	}else{
		printf("STDIN can seek!\n");
	}
	return 0;
}

