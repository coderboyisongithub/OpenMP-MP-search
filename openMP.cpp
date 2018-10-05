#include "stdafx.h"
#include <conio.h>
#include <omp.h>

struct Location
{
	int x,y;
};

#include "Nody.h" //https://github.com/coderboyisongithub/linkedList-Nody/blob/master/Nody.h---->Get From here..

STACK_CHILD stack;
void foo()
{
	return;
}

void main()
{
	int key=50;

int arr[][3]=
{
	1,2,3,
	4,10,6,
	7,8,9,
	10,50,12,
	13,14,15,
	16,10,50,
	19,50,10,
	22,10,24
};
bool exit=false;

int r,c;

printf("Searching for %d in following matrix:..\n\n",key);
for(int row=0;row<8;row++)
{
	for(int col=0;col<3;col++)
	{
		printf(" %d ",arr[row][col]);
	}
	printf("\n");

}
	printf("\n");

printf("Using Multi-processing:\nTotal CPU:Thread(s) %d\nThread Scheduling:Dynamic  \nChunkSize:2",omp_get_max_threads());

#pragma omp parallel for schedule(dynamic,2) private(r,c)
for(r=0;r<8;r++)
{

	for(c=0;c<3;c++)
	{
	if(key==arr[r][c])
	{
		Location *ptr=(Location*)malloc(sizeof(Location*));
		ptr->x=r;
		ptr->y=c;
		stack.push((void*)ptr);

		break;
	}
	}
	
}
while(!stack.isEmpty())
{
	Location *data=(Location*)stack.pop();
	printf("\n Key found at location : %d %d",data->x,data->y);
}


_getch();
}
