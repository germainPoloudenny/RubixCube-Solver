#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


Face* generateFace()
{
    Face* face = malloc(sizeof(Face));
      for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
 
    face->colors[i][j]=Colors[inc];
    face->colors[i][3]='\0';
    }
    face->rotation=0;
    inc++;
    return face;
}


void generateCube()
{
   
      for(int i=0;i<6;i++)
    {
        cube[i]=generateFace();
        cube[i]->idx=i;
       
    }
 
    cube[0]->neighbours[UP]=cube[1];
    cube[0]->neighbours[RIGHT]=cube[2];
    cube[0]->neighbours[DOWN]=cube[3];
    cube[0]->neighbours[LEFT]=cube[4];
   
    cube[1]->neighbours[UP]=cube[5];
    cube[1]->neighbours[RIGHT]=cube[2];
    cube[1]->neighbours[DOWN]=cube[0];
    cube[1]->neighbours[LEFT]=cube[4];
 
    cube[2]->neighbours[UP]=cube[1];
    cube[2]->neighbours[RIGHT]=cube[5];
    cube[2]->neighbours[DOWN]=cube[3];
    cube[2]->neighbours[LEFT]=cube[0];
 
    cube[3]->neighbours[UP]=cube[0];
    cube[3]->neighbours[RIGHT]=cube[2];
    cube[3]->neighbours[DOWN]=cube[5];
    cube[3]->neighbours[LEFT]=cube[4];
 
    cube[4]->neighbours[UP]=cube[1];
    cube[4]->neighbours[RIGHT]=cube[0];
    cube[4]->neighbours[DOWN]=cube[3];
    cube[4]->neighbours[LEFT]=cube[5];
 
    cube[5]->neighbours[UP]=cube[3];
    cube[5]->neighbours[RIGHT]=cube[4];
    cube[5]->neighbours[DOWN]=cube[1];
    cube[5]->neighbours[LEFT]=cube[2];
 
}

void randomize()
{
    int sens, idx;
    for(int i=0;i<30;i++)
    {
        sens=(rand()%2)*2-1;
        idx=rand()%6;
        rotateGlobalFace(sens,idx,1);
    }
}


