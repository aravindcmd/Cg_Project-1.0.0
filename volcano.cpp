#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>
#include<GL/freeglut.h>
using namespace std;
void display();
void shootingstars();
void poly();
void reshape(int,int);
void volcano();
void timer(int);
void color();
void rocks();
void color(float r,float g,float b)
{
    glColor3f(r/255,g/255,b/255);
}
void poly(float x,float y)
{
    glVertex2f(x,y);
}
int main(int argc,char**argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(300,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("Volcano simulation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000,timer,0);
    glutMainLoop();
    printf("Hello There")


}
//each item variable is like this  boat+position = bpos
float xpos = -1.0;
float spos = -1.0;//shooting star position
float bpos = -1.0; //boat position
float cpos = -1.0; //cloud position
float rpos = -1.0;// flying rocks  position
float vpos=55+rpos;
float count = 1000;
void display()
{   char display;

    glClear(GL_COLOR_BUFFER_BIT | GL_DOUBLE);

    glLoadIdentity();






    glBegin(GL_POLYGON); //sky
    color(135,206,250);
    //color(25,25,112);
    poly(-150,150);
    poly(-150,30);
    poly(150,30);
    poly(150,150);
    glEnd();



    glBegin(GL_POLYGON); // sand
    color(255,127,80);
    poly(-150,0);
    poly(150,0);
    poly(150,-150);
    poly(-150,-150);
    glEnd();
    glBegin(GL_POLYGON); // sea
    color(100,149,237);
    poly(-150,30);
    poly(150,30);
    poly(150,0);
    poly(-150,0);
    glEnd();

    color(255,128,0);
    //color(244,255,255);
    glPointSize(50);
    glBegin(GL_POINTS);//sun
    poly(-135,125);
    glEnd();
    glPointSize(40);
    color(224,255,255);
    glBegin(GL_POINTS); // cloud
    poly(-80-cpos,105);
    poly(-85-cpos,100);
    poly(-75-cpos,100);
    poly(-80-cpos,95);

    poly(80+cpos,105); // same cloud opposite direction
    poly(85+cpos,100);
    poly(75+cpos,100);
    poly(80+cpos,95);
    glEnd();

    glBegin(GL_POLYGON); // boat
    //color(224,255,255);
    color(240,230,140);
    poly(135+bpos,37);
    poly(130+bpos,30);
    poly(110+bpos,30);
    poly(105+bpos,37);
    glEnd();
    glBegin(GL_POLYGON); //sail of the yatch
    color(224,255,255);
    poly(125+bpos,47);
    poly(125+bpos,37);
    poly(112+bpos,39);
    glEnd();


    rocks();


    volcano();
    shootingstars(); //calling the volcano so that the boat goes behind the volcano

    glBegin(GL_POLYGON);
    color(255,69,0);
    poly(-65,-16);
    poly(-73,-57);
    poly(-64,-90);
    poly(-32,-96);
    poly(-22,-92);
    poly(-29,-55);
    glEnd();










    glutSwapBuffers();

}
void reshape(int w,int h)
{

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-150,150,-150,150);
    glMatrixMode(GL_MODELVIEW);


}
void timer(int)
{
    glutPostRedisplay();
    glutPostOverlayRedisplay();
    glutTimerFunc(1000/60,timer,0);
    bpos += -0.70;
    cpos += -0.15;
    spos += -0.70;
    rpos += 1;

if(vpos+rpos==150.0){

            cout <<" Vposed!!";
        vpos = 55;
        rpos = 1.0;}

}

void rocks()
{
    //cout<<"Inside rock function";
     glLoadIdentity();
    color(255,128,00);
    glPointSize(10);
     glBegin(GL_POINTS); //volcano rocks in air

    poly(20+rpos,85+rpos); //1
    poly(18-rpos,80+rpos); //2
    poly(12+rpos,77+rpos); //3
    poly(15-rpos,65+rpos); //4
    poly(22+rpos,76+rpos); //5
    poly(10-rpos,62+rpos); //6
    poly(-19-rpos,65+rpos);//7
    poly(-9-rpos,68+rpos); //8
    poly(-5+rpos,77+rpos); //9
        poly(-7,55+rpos);
    poly(-7,vpos);


    glEnd();
}
void volcano() // body of the volcano
{

 glLoadIdentity();




    glBegin(GL_POLYGON); //left section of volcano
    color(152,76,0);
    poly(-20,65);
    poly(0,48);
    poly(0,0);
    poly(-80,0);
    glEnd();

    glBegin(GL_POLYGON); // upper middle section
    color(255,69,0);
    poly(-5,80);
    poly(30,90);
    poly(-20,65);
    glEnd();
    glBegin(GL_POLYGON); //lower middle section
    color(255,69,0);
    poly(30,90);
    poly(-20,65);
    poly(0,48);
    glEnd();

    glBegin(GL_POLYGON);  // right section of volcano
    color(51,25,0);
    poly(30,90);
    poly(0,48);
    poly(0,0);
    poly(70,0);
    glEnd();

    glBegin(GL_POLYGON); //right lower base of volcano
    poly(70,0);
    poly(0,-85);
    poly(0,0);
    glEnd();

    glBegin(GL_POLYGON); //left lower base of volcano
    color(152,76,0);
    poly(-80,0);
    poly(0,0);
    poly(0,-85);
    glEnd();


    glBegin(GL_POLYGON); // the left side lava co-ods are a bit clumsy
     color(255,69,0);
    poly(-5,53);
    poly(-10,57);
    poly(-29,-55);
    poly(-65,-16);
    glEnd();
    glBegin(GL_LINE_LOOP);
    {
        poly(-8,53);
        poly(-6,55);
        poly(-3,53);
        glEnd();


    }

}
void shootingstars()
{

glLoadIdentity();



color(224,255,255);
    glPointSize(5);
    glBegin(GL_POINTS); //shooting star

        poly(150+spos,150+cpos);
    glEnd();
}

// idea section
//make the moon and the sun enter vertically up and when that happens change the sky color respectively

