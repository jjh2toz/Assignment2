#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm time1, time2;
struct tm * temp;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
	stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
	stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	temp = localtime(&stat1.st_mtime);
	time1 = *temp;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	temp = localtime(&stat2.st_mtime);
	time2 = *temp;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	printf("text size: ");
	if ( stat1.st_size > stat2.st_size )
		printf("text1's size is bigger than text2's\n");
	else if ( stat1.st_size == stat2.st_size )
   		printf("text sizes are equal\n");
	else if ( stat1.st_size < stat2.st_size )
   		printf("text2's size is bigger than text1's\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	printf("blocks number: ");
	if ( stat1.st_blocks > stat2.st_blocks )
		printf("text1 is bigger\n");
	else if ( stat1.st_blocks == stat2.st_blocks )
		printf("number of blocks are equal\n");
	else if ( stat1.st_blocks < stat2.st_blocks )
		printf("text2 is bigger\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	printf("date: ");
	if (time1.tm_mon+1 > time2.tm_mon+1)
                printf("text2 is early\n");
        else if (time1.tm_mon+1 < time2.tm_mon+1)
                printf("text1 is early\n");
        else
	{
          if(time1.tm_mday > time2.tm_mday)
		printf("text2 is early\n");
          else  if(time1.tm_mday < time2.tm_mday)
		printf("text1 is early\n");
          else
		printf("same date\n");
        }
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{	
  printf("time: );
	if (time1.tm_hour > time2.tm_hour)
		printf("text2 is early\n");
	else if (time1.tm_hour < time2.tm_hour)
		printf("text1 is early\n");
	else
	{
		if(time1.tm_min > time2.tm_min)
			printf("text2 is early\n");
		else if(time1.tm_min < time2.tm_min)
			printf("text1 is early\n");
		else
			printf("same time\n");
	}
}
