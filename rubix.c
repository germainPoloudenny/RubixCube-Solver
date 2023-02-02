#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "rubix.h"
#include "generate.c"
#include "resolve.c"
#include "save.c"

char* cameraAddapt(Face* face,int l, int c,int rot)
{
    switch( (face->rotation+rot+4)%4 )
    {
        case 0 :
            return &(face->colors[l][c]);
            break;
        case 1 :
            return &(face->colors[c][2-l]);
            break;
        case 2 :
            return &(face->colors[2-l][2-c]);
            break;
        case 3 :
            return &(face->colors[2-c][l]);
            break;
    }
}

void rotateFace(int rot,Face* face)
{
    face->rotation=(face->rotation+rot+4)%4;
}
 
void stockLine(char* buffer, Face* face)
{
    for(int i=0;i<3;i++)
    {
        buffer[i]=*cameraAddapt(face,2,i,0);
    }
    buffer[3]='\0';
}
 
void setLine(char* buffer, Face* face)
{
    for(int i=0;i<3;i++)
    {
        *cameraAddapt(face,2,i,0)=buffer[i];
    }
}
 
void rotateLine(int sens, int rot,int idx, int nb)
{
    char buffer1[4]={' ',' ',' ','\0'}, buffer2[4], notation[3];
    if(  (idx==0 || idx==2 || idx==4 || idx==5) && rot%2==0) idx=0;
    else if(( idx%2==1 || idx==0) && rot%2==1) idx=0;
    else if(idx>0&&idx<=4 && (idx+rot)%2==1)
    {
        rot+=(1-idx+4)%4;
        idx=1;
    }
    else idx=1;
    rot=(rot+4)%4;
    int final_rot=rot, dir=(rot+sens+4)%4, final_dir=dir;
    Face *current=cube[idx];
    if(idx==0 && rot==1) notation[0]='L';
    else if(idx==0 && (rot+4)%4==3) notation[0]='R';
    else if(idx==0 && rot==2) notation[0]='U';
    else if(idx==0 && rot==0) notation[0]='D';
    else if(idx==1 && rot==0) notation[0]='F';
    else notation[0]='B';
    if(nb==2) notation[1]='2';
    else if(sens==-1) notation[1]='\'';
    else notation[1]=' ';
    notation[2]='\0';
    addStep(notation);
    if(idx==0 && dir%2==0)rotateFace(2,cube[5]);
    for(int j=0;j<nb;j++)
    {
        for(int i=0;i<5;i++)
            {
                if(idx==1 && (dir==1 ||dir==3) )
                {
                    final_rot=(rot+i*dir+8)%4;
                    final_dir=(i*dir+dir+4)%4;
                }
                else if((idx==2 || idx==4)&&(dir==1 || dir==-1)) final_rot=i*(sens+rot+5)%4*(idx-1);
                else final_dir=(rot+sens+4)%4;
                rotateFace(final_rot,current);
                stockLine(buffer2,current);
                setLine(buffer1,current);
                rotateFace(-final_rot,current);
                strcpy(buffer1,buffer2);
                current=current->neighbours[(final_dir+4)%4];
              
            }
            current=cube[idx];
            final_rot=rot;
            final_dir=dir;
    }
    if(idx==0 && dir%2==0) rotateFace(2,cube[5]);
}

void rotateGlobalFace(int sens, int idx, int nb)
{
    rotateFace(-nb*sens,cube[idx]);
    int rot=0;
    if(idx==2) rot=3;
    else if(idx==4) rot=1;
    else if(idx==1) rot=2;
    rotateLine(sens,rot,cube[idx]->neighbours[UP]->idx,nb);
}

int main()
{
    FILE* f;
    srand(time(NULL));
    *stepsList=NULL;
    generateCube();
    rotateFace(2,cube[5]);
    char num;
    printf("\n****************\nRUBIX SOLVER\n****************\n");
    while( 1 )
    {
        
        printf(" 1 : Afficher\n");
        printf(" 2 : Sauvegarder\n");
        printf(" 3 : Mélanger\n");
        printf(" 4 : Résoudre\n");
        printf(" 5 : Charger\n");
        printf(" 6 : Quitter\n");
 
        scanf("%c[^\n]",&num);
        fflush(stdin);
        switch (num)
        {
            case '1' :
                save(stdout);
                break;
            case '2' : 
                save(f);
                printf("Sauvegardé !\n");
                break;
            case '3' :
            	printf("Mélangé !\n");
                randomize();
                break;
            case '4' :
            	 printf("Première couronne résolue !\n");
            	 clearSteps();
                firstCrown();
                printSteps();
                break;
            case '5' :
                load(f);
                printf("Chargé !\n");
                break;
            case '6' :
                printf("A BIENTOT !\n");
                exit(0);
        }
        
        printf("\n****************\n");
    }
}
 







