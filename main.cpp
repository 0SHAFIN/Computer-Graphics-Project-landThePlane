#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
#include <cstdlib>
#include <GL/freeglut.h>
using namespace std;

struct Plane
{
    float x, y;
    float width, height;
};

struct Bullet
{
    float x, y;
    float width, height;
};

struct building1
{
    float x, y;
    float h, w;
    float floor, flat;
    float br=0.0, bg=0.0, bb=0.0, wr=0.0, wg=0.0, wb=0.0;
};

void playGBGM(int t)
{

    PlaySound("MainBGM.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void stopLevelUpBGM(int n)
{
    PlaySound(NULL, NULL, 0);
}
void levelUpBGM()
{
    PlaySound("LevelUp.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    glutTimerFunc(1000, stopLevelUpBGM, 0);
}
void playGameover()
{
    PlaySound("gameOver.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    glutTimerFunc(4300, stopLevelUpBGM, 0);
}
void playLifeMinus()
{
    PlaySound("lifeminus.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    glutTimerFunc(1000, stopLevelUpBGM, 0);
}
void playexplosion()
{
    PlaySound("explosion.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    glutTimerFunc(200, stopLevelUpBGM, 0);
}
void gamewin()
{
    PlaySound("gameWin.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    glutTimerFunc(2000, stopLevelUpBGM, 0);
}
float cloudXB1=-.5;
float cloudXB2=0;
float cloudXS1=-.8;
float cloudXS2=.6;
int gameLife=3;
int gameLevel=1;
bool gameStart=false;
bool gameOver = false;
bool gameWin = false;
float bgX=-1.0;
float scorE=0,scorE2=0,scorE3=0;
string gameScore="Score: 0";
vector<Bullet> bullets;
vector<building1> buildings;
vector<building1> buildingsS;
vector<building1> buildings2;
vector<building1> buildings3;
string gameL="Game Level: "+to_string(gameLevel) ;
float levelH=0;
float fuelX=0.3;
Plane box1 = {-1.0f, 0.7f, 0.2f, 0.2f};

void cloud1(float x, float y, float r, float g, float b,float z)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + .3/z, y);
    glVertex2f(x + .3/z, y + .015/z);
    glVertex2f(x, y + .015/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x-.02/z, y+.015/z);
    glVertex2f(x + .32/z, y+.015/z);
    glVertex2f(x + .32/z, y + .03/z);
    glVertex2f(x-.02/z, y + .03/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x-.02/z, y+.03/z);
    glVertex2f(x + .32/z, y+.03/z);
    glVertex2f(x + .32/z, y + .045/z);
    glVertex2f(x-.02/z, y + .045/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x-.04/z, y+.045/z);
    glVertex2f(x + .32/z, y+.045/z);
    glVertex2f(x + .32/z, y + .06/z);
    glVertex2f(x-.04/z, y + .06/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.02/z, y+.06/z);
    glVertex2f(x + .23/z, y+.06/z);
    glVertex2f(x + .23/z, y + .075/z);
    glVertex2f(x+.02/z, y + .075/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.02/z, y+.075/z);
    glVertex2f(x + .23/z, y+.075/z);
    glVertex2f(x + .23/z, y + .09/z);
    glVertex2f(x+.02/z, y + .09/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.25/z, y+.06/z);
    glVertex2f(x + .3/z, y+.06/z);
    glVertex2f(x + .3/z, y + .075/z);
    glVertex2f(x+.25/z, y + .075/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.26/z, y+.075/z);
    glVertex2f(x + .29/z, y+.075/z);
    glVertex2f(x + .29/z, y + .09/z);
    glVertex2f(x+.26/z, y + .09/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.035/z, y+.09/z);
    glVertex2f(x + .15/z, y+.09/z);
    glVertex2f(x + .15/z, y + .105/z);
    glVertex2f(x+.035/z, y + .105/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.035/z, y+.105/z);
    glVertex2f(x + .15/z, y+.105/z);
    glVertex2f(x + .15/z, y + .120/z);
    glVertex2f(x+.035/z, y + .120/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.165/z, y+.09/z);
    glVertex2f(x + .215/z, y+.09/z);
    glVertex2f(x + .215/z, y + .105/z);
    glVertex2f(x+.165/z, y + .105/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.172/z, y+.105/z);
    glVertex2f(x + .205/z, y+.105/z);
    glVertex2f(x + .205/z, y + .12/z);
    glVertex2f(x+.172/z, y + .12/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.04/z, y+.12/z);
    glVertex2f(x + .07/z, y+.12/z);
    glVertex2f(x + .07/z, y + .135/z);
    glVertex2f(x+.04/z, y + .135/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.08/z, y+.12/z);
    glVertex2f(x + .14/z, y+.12/z);
    glVertex2f(x + .14/z, y + .135/z);
    glVertex2f(x+.08/z, y + .135/z);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.088/z, y+.135/z);
    glVertex2f(x + .14/z, y+.135/z);
    glVertex2f(x + .14/z, y + .15/z);
    glVertex2f(x+.088/z, y + .15/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.1/z, y+.15/z);
    glVertex2f(x + .125/z, y+.15/z);
    glVertex2f(x + .125/z, y + .165/z);
    glVertex2f(x+.1/z, y + .165/z);
    glEnd();
}

void BG(float bgX)
{
    glColor3f(0.30, 0.71, 0.81);
    glBegin(GL_POLYGON);
    glVertex2f(bgX, 0.5);
    glVertex2f(bgX +.11, .5);
    glVertex2f(bgX +.11, 1.0);
    glVertex2f(bgX,  1.0);
    glEnd();
    glColor3f(0.48, 0.86, 0.93);
    glBegin(GL_POLYGON);
    glVertex2f(bgX, 0.0);
    glVertex2f(bgX +.11, .0);
    glVertex2f(bgX +.11, .5);
    glVertex2f(bgX,  .5);
    glEnd();
    glColor3f(0.71, 0.98, 0.99);
    glBegin(GL_POLYGON);
    glVertex2f(bgX, -0.5);
    glVertex2f(bgX +.11, -.5);
    glVertex2f(bgX +.11, .0);
    glVertex2f(bgX,  .0);
    glEnd();



    glColor3f(0.71, 0.98, 0.99);
    glBegin(GL_POLYGON);
    glVertex2f(bgX, 0.0);
    glVertex2f(bgX +.11, 0.0);
    glVertex2f(bgX +.11, .02);
    glVertex2f(bgX,  .02);
    glEnd();
    glColor3f(0.71, 0.98, 0.99);
    glBegin(GL_POLYGON);
    glVertex2f(bgX+.01, 0.02);
    glVertex2f(bgX +.09, 0.02);
    glVertex2f(bgX +.09, .04);
    glVertex2f(bgX+.01,  .04);
    glEnd();
    glColor3f(0.71, 0.98, 0.99);
    glBegin(GL_POLYGON);
    glVertex2f(bgX+.02, 0.04);
    glVertex2f(bgX +.04, 0.04);
    glVertex2f(bgX +.04, .06);
    glVertex2f(bgX+.02,  .06);
    glEnd();
    glColor3f(0.71, 0.98, 0.99);
    glBegin(GL_POLYGON);
    glVertex2f(bgX+.05, 0.04);
    glVertex2f(bgX +.07, 0.04);
    glVertex2f(bgX +.07, .06);
    glVertex2f(bgX+.05,  .06);
    glEnd();



    glColor3f(0.48, 0.86, 0.93);
    glBegin(GL_POLYGON);
    glVertex2f(bgX, 0.5);
    glVertex2f(bgX +.04, 0.5);
    glVertex2f(bgX +.04, .52);
    glVertex2f(bgX,  .52);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(bgX+.055, 0.5);
    glVertex2f(bgX +.1, 0.5);
    glVertex2f(bgX +.1, .52);
    glVertex2f(bgX+.055,  .52);
    glEnd();
    glColor3f(0.48, 0.86, 0.93);
    glBegin(GL_POLYGON);
    glVertex2f(bgX+.01, 0.52);
    glVertex2f(bgX +.03, 0.52);
    glVertex2f(bgX +.03, .54);
    glVertex2f(bgX+.01,  .54);
    glEnd();
    glColor3f(0.48, 0.86, 0.93);
    glBegin(GL_POLYGON);
    glVertex2f(bgX+.066, 0.52);
    glVertex2f(bgX +.085, 0.52);
    glVertex2f(bgX +.085, .54);
    glVertex2f(bgX+.066,  .54);
    glEnd();


}
void background()
{
    float x=.1;
    BG(bgX);
    for(int i=0; i<20; i++)
    {
        BG(bgX+x);
        x+=.1;
    }
    glColor3f(0.41, 0.63, 0.22);
    glBegin(GL_POLYGON);
    glVertex2f(-1,-1);
    glVertex2f(1.0, -1);
    glVertex2f(1.0, -.5);
    glVertex2f(-1,  -.5);
    glEnd();

}

void life(float x, float y,float z,float r, float g, float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+.01/z, y);
    glVertex2f(x+.01/z, y+.01/z);
    glVertex2f(x,  y+.01/z);
    glEnd();

    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x-.01/z, y+.01/z);
    glVertex2f(x, y+.01/z);
    glVertex2f(x, y+.02/z);
    glVertex2f(x-.01/z,  y+.02/z);
    glEnd();
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y+.01/z);
    glVertex2f(x+.01/z, y+.01/z);
    glVertex2f(x+.01/z, y+.02/z);
    glVertex2f(x,  y+.02/z);
    glEnd();
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.01/z, y+.01/z);
    glVertex2f(x+.02/z, y+.01/z);
    glVertex2f(x+.02/z, y+.02/z);
    glVertex2f(x+.01/z,  y+.02/z);
    glEnd();
    float t1=x;
    for(int i=0; i<5; i++)
    {
        glColor3f(r,g,b);
        glBegin(GL_POLYGON);
        glVertex2f(t1-.02/z, y+.02/z);
        glVertex2f(t1-.01/z, y+.02/z);
        glVertex2f(t1-.01/z, y+.03/z);
        glVertex2f(t1-.02/z,  y+.03/z);
        glEnd();
        t1+=.01;
    }
    float t2=x;
    for(int i=0; i<7; i++)
    {
        glColor3f(r,g,b);
        glBegin(GL_POLYGON);
        glVertex2f(t2-.03/z, y+.03/z);
        glVertex2f(t2-.02/z, y+.03/z);
        glVertex2f(t2-.02/z, y+.04/z);
        glVertex2f(t2-.03/z,  y+.04/z);
        glEnd();
        t2+=.01;
    }
    float t3=x;
    for(int i=0; i<9; i++)
    {
        glColor3f(r,g,b);
        glBegin(GL_POLYGON);
        glVertex2f(t3-.04/z, y+.04/z);
        glVertex2f(t3-.03/z, y+.04/z);
        glVertex2f(t3-.03/z, y+.05/z);
        glVertex2f(t3-.04/z,  y+.05/z);
        glEnd();
        t3+=.01;
    }
    float t4=x;
    for(int i=0; i<9; i++)
    {
        glColor3f(r,g,b);
        glBegin(GL_POLYGON);
        glVertex2f(t4-.04/z, y+.05/z);
        glVertex2f(t4-.03/z, y+.05/z);
        glVertex2f(t4-.03/z, y+.06/z);
        glVertex2f(t4-.04/z,  y+.06/z);
        glEnd();
        t4+=.01;
    }
    float t5=x;
    for(int i=0; i<3; i++)
    {
        glColor3f(r,g,b);
        glBegin(GL_POLYGON);
        glVertex2f(t5-.03/z, y+.06/z);
        glVertex2f(t5-.02/z, y+.06/z);
        glVertex2f(t5-.02/z, y+.07/z);
        glVertex2f(t5-.03/z,  y+.07/z);
        glEnd();
        t5+=.01;
    }
    float t6=x;
    for(int i=0; i<3; i++)
    {
        glColor3f(r,g,b);
        glBegin(GL_POLYGON);
        glVertex2f(t6+.01/z, y+.06/z);
        glVertex2f(t6+.02/z, y+.06/z);
        glVertex2f(t6+.02/z, y+.07/z);
        glVertex2f(t6+.01/z,  y+.07/z);
        glEnd();
        t6+=.01;
    }
    float t7=x;
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(t7-.02/z, y+.07/z);
    glVertex2f(t7-.01/z, y+.07/z);
    glVertex2f(t7-.01/z, y+.08/z);
    glVertex2f(t7-.02/z,  y+.08/z);
    glEnd();
    float t8=x;
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(t8+.02/z, y+.07/z);
    glVertex2f(t8+.03/z, y+.07/z);
    glVertex2f(t8+.03/z, y+.08/z);
    glVertex2f(t8+.02/z,  y+.08/z);
    glEnd();






}
void planeBox(float x,float y,float z, float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+.01/z, y);
    glVertex2f(x+.01/z, y+.01/z);
    glVertex2f(x,  y+.01/z);
    glEnd();
}
void box(float x, float y, float width,float height,float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y+height);
    glVertex2f(x,  y+height);
    glEnd();
}
void plane(float x, float y,float z)
{


    float r1=0.47,g1=0.48,b1= 0.50;
    box(x,y-.01,-.3,.04,r1,g1,b1);
    box(x-.3,y-.01,-.02,.01,r1,g1,b1);
    box(x-.3,y+.01,-.02,.1,r1,g1,b1);
    box(x-.29,y+.1,-.02,.02,r1,g1,b1);
    box(x,y-.02,-.32,.01,r1,g1,b1);
    box(x-.03,y-.03,-.28,.01,r1,g1,b1);
    box(x-.04,y-.04,-.22,.01,r1,g1,b1);
    box(x-.03,y-.05,-.20,.01,r1,g1,b1);
    box(x-.05,y-.06,-.15,.01,r1,g1,b1);
    box(x-.1,y-.07,-.1,.01,r1,g1,b1);
    box(x-.12,y-.08,-.09,.01,r1,g1,b1);
    box(x-.12,y-.09,-.1,.01,r1,g1,b1);
    box(x-.03,y+.03,-.3,.01,r1,g1,b1);
    box(x-.04,y+.04,-.28,.01,r1,g1,b1);
    box(x-.05,y+.05,-.15,.01,r1,g1,b1);
    box(x-.06,y+.06,-.13,.01,r1,g1,b1);
    box(x-.2,y+.03,-.08,.01,r1,g1,b1);
    box(x-.2,y+.04,-.08,.01,r1,g1,b1);
    box(x-.27,y+.05,-.05,.01,r1,g1,b1);
    box(x-.28,y+.06,-.04,.01,r1,g1,b1);
    box(x-.29,y+.06,-.01,.04,r1,g1,b1);


    box(x-.04,y+.03,-.03,.02,0.24, 0.27, 0.27);
    box(x-.03,y+.03,-.01,.01,0.24, 0.27, 0.27);
    box(x-.08,y+.03,-.02,.02,0.24, 0.27, 0.27);

    float t=y;
    for(int i=0; i<3; i++)
    {
        planeBox(x,t,z,0,0,0);
        t+=.01;
    }
    planeBox(x-.01,y+.03,z,0,0,0);
    planeBox(x-.02,y+.03,z,0,0,0);
    planeBox(x-.03,y+.03,z,0,0,0);
    planeBox(x-.04,y+.04,z,0,0,0);
    planeBox(x-.05,y+.05,z,0,0,0);
    planeBox(x-.06,y+.06,z,0,0,0);
    planeBox(x-.07,y+.06,z,0,0,0);
    planeBox(x-.08,y+.06,z,0,0,0);
    planeBox(x-.09,y+.06,z,0,0,0);
    float t1=x-.1;
    for(int i=0; i<8; i++)
    {
        planeBox(t1,y+.07,z,0,0,0);
        t1-=.01;

    }
    planeBox(x-.18,y+.06,z,0,0,0);
    planeBox(x-.19,y+.06,z,0,0,0);
    planeBox(x-.2,y+.05,z,0,0,0);
    planeBox(x-.21,y+.05,z,0,0,0);
    planeBox(x-.22,y+.05,z,0,0,0);
    planeBox(x-.23,y+.05,z,0,0,0);
    planeBox(x-.24,y+.05,z,0,0,0);
    planeBox(x-.25,y+.05,z,0,0,0);
    planeBox(x-.26,y+.04,z,0,0,0);
    planeBox(x-.26,y+.03,z,0,0,0);
    planeBox(x-.27,y+.05,z,0,0,0);
    planeBox(x-.28,y+.06,z,0,0,0);
    planeBox(x-.29,y+.07,z,0,0,0);
    planeBox(x-.29,y+.08,z,0,0,0);
    planeBox(x-.29,y+.09,z,0,0,0);
    planeBox(x-.29,y+.1,z,0,0,0);
    planeBox(x-.3,y+.11,z,0,0,0);
    planeBox(x-.31,y+.12,z,0,0,0);
    planeBox(x-.32,y+.11,z,0,0,0);
    planeBox(x-.33,y+.1,z,0,0,0);
    planeBox(x-.33,y+.09,z,0,0,0);
    planeBox(x-.33,y+.08,z,0,0,0);
    planeBox(x-.33,y+.07,z,0,0,0);
    planeBox(x-.33,y+.06,z,0,0,0);
    planeBox(x-.33,y+.05,z,0,0,0);
    planeBox(x-.33,y+.04,z,0,0,0);
    planeBox(x-.33,y+.03,z,0,0,0);
    planeBox(x-.33,y+.02,z,0,0,0);
    planeBox(x-.32,y+.01,z,0,0,0);
    planeBox(x-.31,y+.0,z,0,0,0);
    planeBox(x-.32,y-.01,z,0,0,0);
    planeBox(x-.33,y-.02,z,0,0,0);
    planeBox(x-.33,y-.03,z,0,0,0);
    planeBox(x-.32,y-.03,z,0,0,0);
    planeBox(x-.31,y-.03,z,0,0,0);
    planeBox(x-.3,y-.03,z,0,0,0);
    planeBox(x-.29,y-.03,z,0,0,0);
    planeBox(x-.28,y-.03,z,0,0,0);
    planeBox(x-.27,y-.04,z,0,0,0);
    planeBox(x-.26,y-.04,z,0,0,0);
    planeBox(x-.25,y-.05,z,0,0,0);
    planeBox(x-.24,y-.05,z,0,0,0);
    planeBox(x-.23,y-.05,z,0,0,0);
    planeBox(x-.22,y-.05,z,0,0,0);
    planeBox(x-.21,y-.05,z,0,0,0);
    planeBox(x-.2,y-.05,z,0,0,0);
    planeBox(x-.2,y-.06,z,0,0,0);
    planeBox(x-.2,y-.07,z,0,0,0);
    planeBox(x-.21,y-.08,z,0,0,0);
    planeBox(x-.22,y-.09,z,0,0,0);
    planeBox(x-.21,y-.1,z,0,0,0);
    planeBox(x-.2,y-.1,z,0,0,0);
    planeBox(x-.19,y-.1,z,0,0,0);
    planeBox(x-.18,y-.1,z,0,0,0);
    planeBox(x-.17,y-.1,z,0,0,0);
    planeBox(x-.16,y-.1,z,0,0,0);
    planeBox(x-.15,y-.1,z,0,0,0);
    planeBox(x-.14,y-.1,z,0,0,0);
    planeBox(x-.13,y-.09,z,0,0,0);
    planeBox(x-.12,y-.08,z,0,0,0);
    planeBox(x-.11,y-.07,z,0,0,0);
    planeBox(x-.1,y-.07,z,0,0,0);
    planeBox(x-.09,y-.07,z,0,0,0);
    planeBox(x-.08,y-.07,z,0,0,0);
    planeBox(x-.07,y-.07,z,0,0,0);
    planeBox(x-.06,y-.06,z,0,0,0);
    planeBox(x-.05,y-.06,z,0,0,0);
    planeBox(x-.04,y-.05,z,0,0,0);
    planeBox(x-.05,y-.05,z,0,0,0);
    planeBox(x-.04,y-.04,z,0,0,0);
    planeBox(x-.04,y-.04,z,0,0,0);
    planeBox(x-.03,y-.03,z,0,0,0);
    planeBox(x-.02,y-.03,z,0,0,0);
    planeBox(x-.01,y-.02,z,0,0,0);
    planeBox(x-.0,y-.02,z,0,0,0);
    planeBox(x-.0,y-.01,z,0,0,0);




}

void Text(string text,float x,float y)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(x, y);
    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}
void Text2(string text, float x, float y)
{
    glColor3f(0.0f, 0.25, 0.27);

    glRasterPos2f(x, y);

    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glPopMatrix();
}
void Text3(string text, float x, float y)
{
    glColor3f(0.0f, 0.25, 0.27);

    glRasterPos2f(x, y);

    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glPopMatrix();
}

void Text4(string text, float x, float y)
{
    glColor3f(0.0f, 0.25, 0.27);

    glRasterPos2f(x, y);

    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, c);
    }

    glPopMatrix();
}

void Text5(string text, float x, float y)
{
    glColor3f(1, 1, 1);

    glRasterPos2f(x, y);

    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glPopMatrix();
}

void menu()
{
    Text2("WELCOME", -.1, .8);
    Text2("TO LAND THE PLANE", -.2, .7);

    box(-.2, .3, .4, .14, 0.0, 0.0, 0.0);
    box(-.195, .305, .39, .13, 0.00, 0.30, 0.27);
    Text5("START", -.08, .36);

    box(-.2, .1, .4, .14, 0.0, 0.0, 0.0);
    box(-.195, .105, .39, .13, 0.00, 0.30, 0.27);
    Text5("Game Information", -.135, .15);

    box(-.2, -0.1, .4, .14, 0.0, 0.0, 0.0);
    box(-.195, -0.095, .39, .13,0.00, 0.30, 0.27);
    Text5("Team Information", -.135, -0.05);

}


void reset()
{
    box1.x=-1.0;
    box1.y=.7;
    // gameLevel=0;
    //  gameLife=0;
    // scorE=0.0;
    buildings=buildingsS;
    gameL="Game Level: "+to_string(gameLevel) ;

}
void box2(float x, float y,float z, float width,float height,float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y+height);
    glVertex2f(x,  y+height);
    glEnd();
}
void missile(float x, float y, float z)
{

    box2(x,y+.01/z,.8,.01/z,.01/z,0.94, 0.19, 0.17);
    float tY2=.02;
    for(int i=0; i<22; i++)
    {
        if(i<=5)
        {
            box2(x-.01/z,y+tY2/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
            box2(x,y+tY2/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
            box2(x+.01/z,y+tY2/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
            tY2+=.01;
        }
        else
        {
            box2(x-.01/z,y+tY2/z,.8/z,.01/z,.01/z,1, 1, 1);
            box2(x,y+tY2/z,.8/z,.01/z,.01/z,0.94, 1, 1);
            box2(x+.01/z,y+tY2/z,.8/z,.01/z,.01/z,1,1, 1);
            tY2+=.01;
        }
    }

    box2(x-.03/z,y+(tY2-.02)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.02/z,y+(tY2-.02)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x-.03/z,y+(tY2-.02)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.03/z,y+(tY2-.02)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x-.04/z,y+(tY2-.02)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.04/z,y+(tY2-.02)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);

    box2(x-.03/z,y+(tY2-.03)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.02/z,y+(tY2-.03)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x-.03/z,y+(tY2-.03)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.03/z,y+(tY2-.03)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x-.04/z,y+(tY2-.03)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.04/z,y+(tY2-.03)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);


    box2(x-.03/z,y+(tY2-.04)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.03/z,y+(tY2-.04)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x-.03/z,y+(tY2-.04)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.03/z,y+(tY2-.04)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);

    box2(x-.03/z,y+(tY2-.05)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.03/z,y+(tY2-.05)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x-.03/z,y+(tY2-.05)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.03/z,y+(tY2-.05)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);

    box2(x-.03/z,y+(tY2-.06)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.03/z,y+(tY2-.06)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x-.03/z,y+(tY2-.06)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);
    box2(x+.03/z,y+(tY2-.06)/z,.8/z,.01/z,.01/z,0.94, 0.19, 0.17);




//
    box2(x,y,1/z,.01/z,.01/z,0,0,0);
    box2(x-.01/z,y+.01/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.01/z,y+.01/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.02/z,y+.02/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.02/z,y+.02/z,1/z,.01/z,.01/z,0,0,0);
    float tY=.02;
    for(int i=0; i<22; i++)
    {
        box2(x-.02/z,y+tY/z,1/z,.01/z,.01/z,0,0,0);
        box2(x+.02/z,y+tY/z,1/z,.01/z,.01/z,0,0,0);
        tY+=.01;
    }
    box2(x-.02/z,y+tY/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.02/z,y+tY/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.01/z,y+tY/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.01/z,y+tY/z,1/z,.01/z,.01/z,0,0,0);
    box2(x,y+tY/z,1/z,.01/z,.01/z,0,0,0);


    box2(x+.03/z,y+(tY-.01)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.04/z,y+(tY-.01)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.05/z,y+(tY-.01)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.05/z,y+(tY-.02)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.05/z,y+(tY-.03)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.04/z,y+(tY-.04)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.04/z,y+(tY-.05)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.04/z,y+(tY-.06)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x+.03/z,y+(tY-.07)/z,1/z,.01/z,.01/z,0,0,0);


    box2(x-.03/z,y+(tY-.01)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.04/z,y+(tY-.01)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.05/z,y+(tY-.01)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.05/z,y+(tY-.02)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.05/z,y+(tY-.03)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.04/z,y+(tY-.04)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.04/z,y+(tY-.05)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.04/z,y+(tY-.06)/z,1/z,.01/z,.01/z,0,0,0);
    box2(x-.03/z,y+(tY-.07)/z,1/z,.01/z,.01/z,0,0,0);


}


void fuelBar(float x, float y,float z,float r, float g, float b)
{
    Text3("Fuel : ",x,y);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x+.13, y);
    glVertex2f(x +.13+ .3/z, y);
    glVertex2f(x +.13+ .3/z, y + .05/z);
    glVertex2f(x+.13, y + .05/z);
    glEnd();
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x+.13, y);
    glVertex2f(x+.13+fuelX/z, y);
    glVertex2f(x+.13+fuelX/z, y + .05/z);
    glVertex2f(x+.13, y + .05/z);
    glEnd();
}


void teamInfo()
{
    Text2("AMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH",-.65,.9);
    Text3("408/1 (Old KA 66/1), Kuratoli, Khilkhet,",-.3,.8);
    Text3("Dhaka 1229,Bangladesh",-.2,.7);
    Text3("Course Title : ",-.35,.55);
    Text3("Computer Graphics.",.1,.55);
    Text3("Project Title : ",-.35,.45);
    Text3("Land The Plane.",.1,.45);
    Text3("Supervised By : ",-.35,.35);
    Text3("Mahfujur Rahman.",.1,.35);
    Text3("Section : ",-.35,.25);
    Text3("( G )",.1,.25);

    Text3("Group Information ",-.15,.0);
    Text3("-------------------",-.2,-.05);

//1
    Text3("1. ",-.4,-.2);
    Text3("Tafsirul Islam Shafin ",-.35,-.2);
    Text3("22-47325-1 ",.15,-.2);

//2
    Text3("2. ",-.4,-.3);
    Text3("Umaiya Tahiyat Bushra ",-.35,-.3);
    Text3("21-45095-2 ",.15,-.3);
//3
    Text3("3. ",-.4,-.4);
    Text3("Mehedi Hasan Mim  ",-.35,-.4);
    Text3("21-45113-2 ",.15,-.4);
//4
    Text3("4. ",-.4,-.5);
    Text3("Roudro Rahman ",-.35,-.5);
    Text3("22-46310-1 ",.15,-.5);



    Text4(" Press ESC to exit or press <-- to back",.3,-.8);

}


void gameInfo()
{
    Text2("Land The Plane",-.1,.8);
    Text3("Game Title: ",-.2,.6);
    Text3("Land The Plane",.1,.6);





    Text3("Game Controls",-.7,.24);

    Text3("Button: 'SPACE' ",-.85,.15);
    Text3("Missile Throw.",-.4,.15);


    Text3("Game Features",-.7,-.05);

    Text3("=> There are Total Three Levels ",-.85,-.15);
    Text3("=> There are Total Three Lifes ",-.85,-.25);
    Text3("=> There are a Fuel Bar ",-.85,-.35);
    Text3("=> There are a Score Label ",-.85,-.45);







    Text3("Game Descreption",.5,.3);
    Text4("Our Main target is to land the plane but the main problem  ",.3,.24);
    Text4("is the ground is not suitable for landing. There are too many buildings",.3,.2);
    Text4("on the ground. To Land the plane we have the clear the ground.",.3,.16);
    Text4("To achieve this we need to throw missile toward the buildings. After ",.3,.12);
    Text4("Completely destroying all the building the plane is finally ready ",.3,.08);
    Text4("for landing. In this way we can complete one level and we have total 3 level",.3,.04);
    Text4("and by going every next level the building height will increase .There are ",.3,.0);
    Text4("3 life and fual system ",.3,-.04);

    Text4(" Press ESC to exit or press <-- to back",.3,-.8);

}

char navigation;
void drawBuilding(building1 b)
{
    glColor3f(b.br,b.bg,b.bb);
    glBegin(GL_POLYGON);
    glVertex2f(b.x, b.y);
    glVertex2f(b.x+b.w, b.y);
    glVertex2f(b.x+b.w, b.y+b.h);
    glVertex2f(b.x,  b.y+b.h);
    glEnd();
    float fH=.06,x=b.x+0.03;
    float fW=.05,y=b.y+0.04;





    for(int i=1; i<b.floor; i++)
    {

        int temp=b.flat;
        if(temp%2==0)
        {
            glColor3f(b.wr,b.wg,b.wb);
            glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x+fW, y);
            glVertex2f(x+fW, y+fH);
            glVertex2f(x, y+fH);
            glEnd();
            x+=fW+.02;
            glColor3f(b.wr,b.wg,b.wb);
            glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x+fW, y);
            glVertex2f(x+fW, y+fH);
            glVertex2f(x, y+fH);
            glEnd();
            x=b.x+.03;

        }
        else
        {
            for(int i=0; i<b.flat-1; i++)
            {
                if(i==1)
                {
                    glColor3f(b.wr,b.wg,b.wb);
                    glBegin(GL_POLYGON);
                    glVertex2f(x, y);
                    glVertex2f(x+fW+.04, y);
                    glVertex2f(x+fW+.04, y+fH);
                    glVertex2f(x, y+fH);
                    glEnd();
                    x+=fW+.04+.02;
                }
                glColor3f(b.wr,b.wg,b.wb);
                glBegin(GL_POLYGON);
                glVertex2f(x, y);
                glVertex2f(x+fW, y);
                glVertex2f(x+fW, y+fH);
                glVertex2f(x, y+fH);
                glEnd();
                x+=fW+.02;
            }
            x=b.x+.03;
        }



        y+=fH+.05;

    }
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(gameStart)
    {

        background();
        cloud1(cloudXB2, 0.56, 0.91, 0.99, 1.00,.9);
        cloud1(cloudXB1, 0.76, 0.91, 0.99, 1.00,1);
        cloud1(cloudXS2, 0.76, 0.91, 0.99, 1.00,1.5);
        cloud1(cloudXS1, 0.5, 0.91, 0.99, 1.00,1.5);
        Text3(gameL,-.9,.9);
        Text3(gameScore,0,.9);

        if (!gameOver&&!gameWin)
        {



            float lifeX=.59;
            for(int i=0; i<gameLife; i++)
            {
                life(lifeX,.9,1,0.82, 0.16, 0.12);
                lifeX+=.11;
            }

            fuelBar(-.5,.9,1,0.0f, 0.25, 0.27);


            for(auto &bullet : bullets)
            {
                missile(bullet.x,bullet.y,2.7);
            }
            plane(box1.x,box1.y,1);

            for(auto &building : buildings)
            {

                drawBuilding(building);

            }

        }

        if (gameOver)
        {

            Text2("Game Over!!",-0.2f, 0.0f);
            Text2("You lost. ",-0.15f, -0.1f);


        }
        if(gameWin)
        {
            Text2("You Won!",-0.2f, 0.0f);

        }

    }
    else
    {
        //teamInfo();

        if(navigation=='T')
        {
            teamInfo();
        }
        else if(navigation=='M')
        {
            menu();
        }
        else if(navigation=='G')
        {
            gameInfo();
        }
        else
        {
            menu();
        }
    }

    glFlush();
}



void cloudUpdate(int value)
{
    cloudXB1+=.001;
    cloudXB2+=.001;
    cloudXS1+=.0005;
    cloudXS2+=.0005;
    if(cloudXB1>=1)
    {
        cloudXB1=-1.4;
    }
    else if(cloudXB2>=1)
    {
        cloudXB2=-1.4;
    }
    else if(cloudXS1>=1)
    {
        cloudXS1=-1.2;
    }
    else if(cloudXS2>=1)
    {
        cloudXS2=-1.2;
    }

    glutPostRedisplay();
    glutTimerFunc(30, cloudUpdate, 0);
}
bool checkBuildingHeight()
{
    for(auto b:buildings)
    {
        if( b.h>.05)
        {
            return false;
        }

    }
    return true;
}
bool checkCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
    return (x1 < x2 + w2 &&
            x1 + w1 > x2 &&
            y1 < y2 + h2 &&
            y1 + h1 > y2
           )|| fuelX==0;
}

void planeUpdate(int value)
{

    if(gameStart)
    {
        box1.x += 0.005f;
        if(fuelX>0)
        {
            fuelX-=.0005f;
        }
        else
        {
            fuelX=0;
        }


    }
    if(box1.x > 1.3)
    {
        box1.x = -1.2;
        box1.y -= 0.15f;

    }



    for(auto &building : buildings)
    {

        if (checkCollision(box1.x-.05, box1.y-.05, box1.width, box1.height, building.x, building.y, building.w, building.h))
        {

            if(gameLife>0)
            {
                gameLife--;
                playLifeMinus();
                fuelX=.3;
                scorE=0;

                gameScore="Score: 0";

            }


            cout<<"Game Life: "<<gameLife<<endl;
            cout<<"Game Level: "<<gameLevel<<endl;
            if(gameLevel==1)
            {
                reset();
            }
            else if(gameLevel==2)
            {
                reset();
                buildings=buildings2;
            }
            else
            {
                reset();
                buildings=buildings3;
            }
            if(gameLife<=0)
            {
                gameOver = true;
                playGameover();

            }
            break;


        }
    }

    if(checkBuildingHeight())

    {

        if(gameLevel<3)
        {

            gameLevel+=1;
            levelUpBGM();
            gameL="Game Level: "+to_string(gameLevel);
            scorE+=box1.y*6+fuelX*10+gameLife*5;
            gameScore="";
            stringstream ss;
            ss << fixed <<setprecision(1) << scorE;
            gameScore="Score: "+ss.str();
            if(gameLevel==2)
            {
                buildings=buildings2;
            }
            else if(gameLevel==3)
            {
                buildings=buildings3;
            }
            box1.x=-1.0;
            box1.y=.7;
            gameLife=3;

        }
        else if(gameLevel==3)
        {

            gameScore="";
            stringstream ss;
            ss << fixed <<setprecision(1) << scorE;
            gameScore="Score: "+ss.str();
            gamewin();
            gameWin=true;

        }
    }



    glutPostRedisplay();
    glutTimerFunc(16, planeUpdate, 0);
}


void bulletUpdate(int value)
{

    for(auto &bullet : bullets)
    {
        bullet.y -= 0.02f;

        for(auto it=buildings.begin(); it!=buildings.end(); ++it)

        {
            if (((bullet.x >= it->x && bullet.x <= it->x + it->w)||
                    (bullet.x < it->x && bullet.x+bullet.width > it->x)||
                    (bullet.x+bullet.width>it->x+it->w && bullet.x<it->x+it->w)) &&
                    bullet.y >= it->y && bullet.y <= it->y +it->h)
            {
                if(it->h>.05)
                {
                    it->floor -= 1;
                    playexplosion();
                    if(it->floor==1)
                    {
                        it->h =0;
                    }
                    else
                    {
                        it->h -= 0.11;

                    }



                    if (it->floor <= 0)
                    {
                        it->floor = 0;
                    }

                    scorE+=3*(box1.y+1);
                    gameScore="";
                    stringstream ss;
                    ss << fixed <<setprecision(1) << scorE;
                    gameScore="Score: "+ss.str();
                    if(fuelX+.04<=.3)
                    {
                        fuelX+=.04;
                    }
                    else
                    {
                        fuelX=.3;
                    }


                }
                else
                {
                    it->h = 0;

                    if(gameLevel<3)
                    {
                        gameLevel+=1;
                        levelUpBGM();

                        gameL=to_string(gameLevel);
                        cout<<"Game Level: "<<gameLevel<<endl;
                        if(gameLevel==2)
                        {
                            buildings=buildings2;
                        }
                        else if(gameLevel==3)
                        {
                            buildings=buildings3;
                        }
                        box1.x=-1.0;
                        box1.y=.7;
                        gameLife=3;


                    }
                    else if( gameLevel==3)
                    {


                        cout<<"Round win from 1242 line. "<<endl;
                        gameScore="";
                        stringstream ss;
                        ss << fixed <<setprecision(1) << scorE;
                        gameScore="Score: "+ss.str();
                        gamewin();
                        gameWin=true;

                    }

                }

                bullet.y = -10.0f;

            }
        }

    }

    glutPostRedisplay();
    glutTimerFunc(16, bulletUpdate, 0);
}
bool canFire=true;
void addBullet(int val)
{
    Bullet b;
    b.x = (box1.x + box1.width / 2)-.2;
    b.y = box1.y - 0.07f;
    b.width = 0.017f;
    b.height = 0.05f;
    bullets.push_back(b);
    canFire=true;
}

void keyFun(unsigned char key, int x, int y)
{

    if(key == ' ' && canFire)
    {
        canFire=false;
        glutTimerFunc(180,addBullet,0);
    }
    else if(key == 27)
    {
        glutLeaveMainLoop();
    }
    else if(key == 8)
    {
        navigation='M';
    }
    else if(key == 13)
    {
        navigation='M';
        gameStart=false;
        gameOver=false;
        gameWin=false;
    }

}

bool isHovering = false;
bool isFirstMusicPlaying = false;

void playFirstMusic()
{
    if (!isFirstMusicPlaying && !gameStart)
    {
        PlaySound("NavigateS.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        isFirstMusicPlaying = true;


    }
}

void stopFirstMusic()
{

    PlaySound(NULL, NULL, 0);

}
void mouseMotion(int x, int y)
{
    float mouseX = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
    float mouseY = 1 - (float)y / glutGet(GLUT_WINDOW_HEIGHT) * 2;

    if (mouseX >= -0.19 && mouseX <= 0.19 && mouseY >= 0.305 && mouseY <= 0.435)
    {
        if (!isFirstMusicPlaying)
        {
            // playFirstMusic();
        }
    }
    else if (mouseX >= -0.2 && mouseX <= 0.2 && mouseY >= 0.105 && mouseY <= 0.235)
    {
        if (!isFirstMusicPlaying)
        {
            // playFirstMusic(); // Start playing the first music on hover
        }

    }
    else if (mouseX >= -0.2 && mouseX <= 0.2 && mouseY >= -0.095 && mouseY <= 0.035)
    {
        if (!isFirstMusicPlaying)
        {
            // playFirstMusic(); // Start playing the first music on hover
        }

    }

    else
    {
        if (isFirstMusicPlaying)
        {
            //stopFirstMusic(); // Stop playing the first music on hover exit
        }
    }
}
void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float mouseX = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float mouseY = 1 - (float)y / glutGet(GLUT_WINDOW_HEIGHT) * 2;


        if (mouseX >= -0.19 && mouseX <= 0.19 && mouseY >= 0.305 && mouseY <= 0.435)
        {

            // PlaySound("NavigateS.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
            cout << "Button clicked: START" << endl;
            gameStart = true;
            stopFirstMusic();
            // PlaySound("GBGM.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        }
        else if (mouseX >= -0.2 && mouseX <= 0.2 && mouseY >= 0.105 && mouseY <= 0.235)
        {
            cout << "Button clicked: Game Information" << endl;
            navigation = 'G';

        }
        else if (mouseX >= -0.2 && mouseX <= 0.2 && mouseY >= -0.095 && mouseY <= 0.035)
        {
            cout << "Button clicked: Team Information" << endl;
            navigation = 'T';

        }

    }
}
struct glassColor
{
    float r;
    float g;
    float b;
};
struct buildingColor
{
    float r;
    float g;
    float b;
};
glassColor g1= {0.85, 1.00, 1.00};
buildingColor b= {0.33, 0.37, 0.41};
buildingColor bl2= {0.38, 0.43, 0.49};
buildingColor bl3= {0.56, 0.62, 0.68};
buildingColor bl4= {0.35, 0.38, 0.38};
buildingColor bl5= { 0.28, 0.24, 0.25};
void buildingOne()
{
    float x=-.95;
    float y=-1;
    building1 b1;
    b1= {x,y,.95,.29,9,3,b.r,b.g,b.b,g1.r,g1.g,g1.b};
    buildings.push_back(b1);
    x+=.35;
    building1 b2;
    b2= {x,y,.6,.19,6,2,bl2.r,bl2.g,bl2.b,g1.r,g1.g,g1.b};
    buildings.push_back(b2);
    x+=.25;
    building1 b3;
    b3= {x,y,.95,.19,9,2,bl5.r,bl5.g,bl5.b,g1.r,g1.g,g1.b};
    buildings.push_back(b3);
    x+=.25;
    building1 b4;
    b4= {x,y,.5,.19,5,2,b.r,b.g,b.b,g1.r,g1.g,g1.b};
    buildings.push_back(b4);
    x+=.25;
    building1 b5;
    b5= {x,y,.6,.19,6,2,bl5.r,bl5.g,bl5.b,g1.r,g1.g,g1.b};
    buildings.push_back(b5);
    x+=.25;
    building1 b6;
    b6= {x,y,.95,.29,9,3,bl4.r,bl4.g,bl4.b,g1.r,g1.g,g1.b};
    buildings.push_back(b6);
    x+=.35;
    building1 b7;
    b7= {x,y,1.05,.19,10,2,b.r,b.g,b.b,g1.r,g1.g,g1.b};
    buildings.push_back(b7);
    x+=.35;

    buildingsS=buildings;
}

void buildingTwo()
{
    float x=-.95;
    float y=-1;
    building1 b1;
    b1= {x,y,1.15,.29,11,3,bl5.r,bl5.g,bl5.b,g1.r,g1.g,g1.b};
    buildings2.push_back(b1);
    x+=.35;
    building1 b2;
    b2= {x,y,.8,.19,8,2,bl4.r,bl4.g,bl4.b,g1.r,g1.g,g1.b};
    buildings2.push_back(b2);
    x+=.25;
    building1 b3;
    b3= {x,y,1.15,.19,11,2,bl2.r,bl2.g,bl2.b,g1.r,g1.g,g1.b};
    buildings2.push_back(b3);
    x+=.25;
    building1 b4;
    b4= {x,y,.7,.19,7,2,b.r,b.g,b.b,g1.r,g1.g,g1.b};
    buildings2.push_back(b4);
    x+=.25;
    building1 b5;
    b5= {x,y,.8,.19,8,2,bl4.r,bl4.g,bl4.b,g1.r,g1.g,g1.b};
    buildings2.push_back(b5);
    x+=.25;
    building1 b6;
    b6= {x,y,1.3,.29,12,3,bl4.r,bl4.g,bl4.b,g1.r,g1.g,g1.b};
    buildings2.push_back(b6);
    x+=.35;
    building1 b7;
    b7= {x,y,1.15,.19,11,2,b.r,b.g,b.b,g1.r,g1.g,g1.b};
    buildings2.push_back(b7);
    x+=.35;
}

void buildingThree()
{
    float x=-.95;
    float y=-1;
    building1 b1;
    b1= {x,y,1.5,.29,14,3,bl4.r,bl4.g,bl4.b,g1.r,g1.g,g1.b};
    buildings3.push_back(b1);
    x+=.35;
    building1 b2;
    b2= {x,y,1.15,.19,11,2,bl2.r,bl2.g,bl2.b,g1.r,g1.g,g1.b};
    buildings3.push_back(b2);
    x+=.25;
    building1 b3;
    b3= {x,y,1.6,.19,15,2,bl4.r,bl4.g,bl4.b,g1.r,g1.g,g1.b};
    buildings3.push_back(b3);
    x+=.25;
    building1 b4;
    b4= {x,y,1.05,.19,10,2,bl2.r,bl2.g,bl2.b,g1.r,g1.g,g1.b};
    buildings3.push_back(b4);
    x+=.25;
    building1 b6;
    b6= {x,y,1.5,.29,14,3,b.r,b.g,b.b,g1.r,g1.g,g1.b};
    buildings3.push_back(b6);
    x+=.35;
    building1 b5;
    b5= {x,y,1.15,.19,11,2,bl4.r,bl4.g,bl4.b,g1.r,g1.g,g1.b};
    buildings3.push_back(b5);
    x+=.25;

    building1 b7;
    b7= {x,y,1.5,.19,14,2,bl5.r,bl5.g,bl5.b,g1.r,g1.g,g1.b};
    buildings3.push_back(b7);
    x+=.35;
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Land The Plane");
    glClearColor(0.30, 0.71, 0.81, 1.0f);

    buildingOne();
    buildingTwo();
    buildingThree();


    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyFun);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(mouseMotion);
    if(!gameStart)
    {
        playGBGM(0);

    }

    glutTimerFunc(100,cloudUpdate,0);
    glutTimerFunc(25, planeUpdate, 0);
    glutTimerFunc(25, bulletUpdate, 0);
    glutMainLoop();
    return 0;
}
