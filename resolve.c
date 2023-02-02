#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int isResolved()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(cube[1]->colors[i][j]!='W') return 0;
		}
	}
	return 1;
}


void firstCrown()
{
   if(isResolved())
   return;
    float t1=clock();
    Face* face=cube[0];
    int i=0, hasChanged=1;
    while(hasChanged || i!=0)
    {
        if(i==0)hasChanged=0;
        if (*cameraAddapt(cube[3],0,1,i)=='W')
        {
            while(*cameraAddapt(cube[1],2,1,-i)=='W' ) rotateGlobalFace(1,1,1);
            rotateGlobalFace(1,face->idx,2);
            hasChanged=1;
        }
        if(*cameraAddapt(face,2,1,0)=='W')
        {
            while(*cameraAddapt(cube[1],2,1,-i)=='W' ) rotateGlobalFace(1,1,1);
            rotateGlobalFace(1,face->idx,1);
            rotateGlobalFace(1,1,1);
            rotateGlobalFace(-1,face->neighbours[LEFT]->idx,1);
            rotateGlobalFace(-1,1,1);
            hasChanged=1;
        }
        if(*cameraAddapt(face,0,1,0)=='W')
        {
            rotateGlobalFace(-1,face->idx,1);
            rotateGlobalFace(1,1,1);
            rotateGlobalFace(-1,face->neighbours[LEFT]->idx,1);
            rotateGlobalFace(-1,1,1);
            hasChanged=1;
        }
        if(*cameraAddapt(face,1,0,0)=='W')
        {
            while(*cameraAddapt(cube[1],1,0,-i)=='W' ) rotateGlobalFace(1,1,1);
            rotateGlobalFace(-1,face->neighbours[LEFT]->idx,1);
            hasChanged=1;
        }
        if(*cameraAddapt(face,1,2,0)=='W')
        {
            while(*cameraAddapt(cube[1],1,2,-i)=='W' ) rotateGlobalFace(1,1,1);
            rotateGlobalFace(1,face->neighbours[RIGHT]->idx,1);
            hasChanged=1;
        }
        face=face->neighbours[RIGHT];
        i=(++i+4)%4;
    }
while(*cameraAddapt(face,1,1,0)!=*cameraAddapt(face,0,1,0) )  rotateGlobalFace(1,1,1);
hasChanged=1;

while(hasChanged || i!=0)
{
    if(i==0)hasChanged=0;
    if (*cameraAddapt(face,1,1,0)!=*cameraAddapt(face,0,1,0) )
        {
            rotateGlobalFace(1,face->idx,2);
            rotateGlobalFace(-1,3,1);
            rotateGlobalFace(1,face->neighbours[LEFT]->idx,2);
            rotateGlobalFace(1,3,1);
            rotateGlobalFace(1,face->idx,2);
            hasChanged=1;
        }
        face=face->neighbours[RIGHT];
        i=(++i+4)%4;
}
hasChanged=1;
while(hasChanged || i!=0)
{
      if(i==0)hasChanged=0;
        if(*cameraAddapt(face,2,0,0)=='W' )
        {
            if( *cameraAddapt(cube[3],0,0,i)==*cameraAddapt(face,1,1,0))
            {
                rotateGlobalFace(1,3,1);
                rotateGlobalFace(1,face->neighbours[LEFT]->idx,1);
                rotateGlobalFace(-1,3,1);
                rotateGlobalFace(-1,face->neighbours[LEFT]->idx,1);
            }
            else rotateGlobalFace(1,3,1);
        hasChanged=1;
        }
        if(*cameraAddapt(face,2,2,0)=='W' )
        {
            if( *cameraAddapt(cube[3],0,2,i)==*cameraAddapt(face,1,1,0))
            {
                rotateGlobalFace(-1,3,1);
                rotateGlobalFace(-1,face->neighbours[RIGHT]->idx,1);
                rotateGlobalFace(1,3,1);
                rotateGlobalFace(1,face->neighbours[RIGHT]->idx,1);
            }
            else rotateGlobalFace(1,3,1);
        hasChanged=1;
        }
        if(*cameraAddapt(face,0,0,0)=='W' )
        {   
                rotateGlobalFace(1,face->neighbours[LEFT]->idx,1);
                rotateGlobalFace(1,3,1);
                rotateGlobalFace(-1,face->neighbours[LEFT]->idx,1);
                rotateGlobalFace(-1,3,1);
            hasChanged=1;
        }
        if(*cameraAddapt(face,0,2,0)=='W' )
        {
                 rotateGlobalFace(-1,face->neighbours[RIGHT]->idx,1);
                rotateGlobalFace(-1,3,1);
                rotateGlobalFace(1,face->neighbours[RIGHT]->idx,1);
                rotateGlobalFace(1,3,1);
            hasChanged=1;
        }
        if(*cameraAddapt(cube[3],2,0,i)=='W')
        {
            rotateGlobalFace(-1,face->neighbours[LEFT]->idx,1);
             rotateGlobalFace(1,3,1);
             rotateGlobalFace(1,face->neighbours[LEFT]->idx,1);
            rotateGlobalFace(1,3,1);
            hasChanged=1;
        }
        face=face->neighbours[RIGHT];
        i=(++i+4)%4;
}
	float t2=clock();
	printf("Temps d'exécution : %.0f ms\n",t2-t1);
}


