#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



void printFace(Face* face,FILE* f)
{
      for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
       {
           fprintf(f,"%c",*cameraAddapt(face,i,j,0));
       }
        fprintf(f,"\n");
    }
    fprintf(f,"\n");
}


void save(FILE* f)
{
    if (f!=stdout) f = fopen("cube","w");
    printFace(cube[0],f);
    printFace(cube[1],f);
    printFace(cube[2],f);
    printFace(cube[3],f);
    printFace(cube[4],f);
    printFace(cube[5],f);
    if (f!=stdout) fclose(f);
}

void load(FILE* f)
{
f = fopen("cube","r");
 char c;
 for(int i=0;i<6;i++)
 {
     for(int j=0;j<3;j++)
     {
         for(int k=0;k<3;k++)
         {
            c =fgetc(f);
            while( c == '\n' || c=='\0') c =fgetc(f);
            cube[i]->colors[j][k]=c;
         }
     }
 }
    fclose(f);
}

void addStep(char* notation)
{
    Step* step= malloc(sizeof(Step));
    strcpy(step->notation,notation);
    step->next=NULL;
    if(*stepsList==NULL)
    {
    *stepsList=step;
         fflush(stdout);
    }
    else
    {
        Step* current=*stepsList, *prec=NULL;
        while(current!=NULL)
        {
            prec=current;
            current=current->next;
        }
        prec->next=step;
    }
}

void printSteps()
{
    Step* current=*stepsList;
        while(current!=NULL)
        {
            printf("%s ",current->notation);
            current=current->next;
        }
       printf("\n");
}

void clearSteps()
{
	Step* current=*stepsList, *prec=NULL;
	while(current!=NULL)
        {
            prec=current;
            current=current->next;
            free(prec);
        }
        *stepsList=NULL;
}



