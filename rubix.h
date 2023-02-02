#define RUBIX_H 0
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char Colors[6] ={ 'R', 'W', 'B', 'Y', 'G', 'O'};
int inc=0;


typedef struct face
{
    char colors[3][5];
    struct face* neighbours[4];
    int rotation;
    int idx;
} Face;

Face* cube[6];

typedef struct step
{
    char notation[3];
    struct step* next;
} Step;
Step* stepsList[1];

char* cameraAddapt(Face*,int,int,int);
void rotateLine(int,int,int,int);
void printFace(Face*,FILE*);
void generateCube();
void firstCrown();
void save(FILE*);
void rotateFace(int,Face*);
void rotateGlobalFace(int,int,int);


