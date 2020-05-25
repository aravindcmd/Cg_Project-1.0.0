#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void display();
void yellow();
void red();
void reshape(int,int);
void timer(int);
int state =1;
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);//double means double buffering
    glutInitWindowPosition(300,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("text displayed on the top of the window");
    glutDisplayFunc(display); //call back function
    glutReshapeFunc(reshape);//when the window size is changed even the image is adjusted
    glutTimerFunc(0,timer,0);

    //yellow();
    glutMainLoop(); //it loops this section


}
float xpos=10.0; //variable to update the x-position
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);//clears the color buffer the default color is black
    glLoadIdentity(); //resets the matrices
    //draw
    glPointSize(10.0);//size of the point
    glTranslatef(0,0,0); //function used to translate the object from one position to another by changing the origin
    glRotatef(45,5,5,0.0);
    glBegin(GL_POLYGON);

    glColor3f(1.0,0.0,0.0);

    glVertex2f(-xpos+2,0);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(0,5);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(xpos-2,0);

    //glVertex3f(1,1,);


    glEnd();
    glutSwapBuffers(); //swaps the front end buffer with the back-end buffer

}
void yellow()
{

    glClearColor(1.0,1.0,0.0,1.0);// red green blue and alpha



}
void red()
{

    glClearColor(1.0,0.0,0.0,1.0);
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h); //specifies the area in which you want to draw

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // resets all the parameters of model view matrix(current martix
    gluOrtho2D(-10,10,-10,10);//set the maximum range of the cartesian slate
    glMatrixMode(GL_MODELVIEW);


}
void timer(int)
{
    glutPostRedisplay(); //displays the display function again
    glutTimerFunc(1000/60,timer,0);
switch(state)

{
    case 1:
    if(xpos<9)
    xpos+=0.15;
    else
    state=2;
    break;
    case 2:
        if(xpos>-9)
            xpos-=0.15;
        else
            state=1;
        break;

}

}
