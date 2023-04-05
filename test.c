#include<windows.h>
#include<gl\gl.h>
#include<gl\glu.h>
#include<gl\glut.h>

float x, y, z;
GLfloat xRotated, yRotated, zRotated;
void draw(void);
void idle(void)
{
    xRotated+=0.01;
    yRotated+=0.01;
    draw();
}
void draw()
{
    x=y=z=1;
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-2.0,-2.0,-6.0);
    glRotatef(xRotated, 1.0, 0.0, 0.0);

//front
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x, -y, z); //P1
    glVertex3f(-x, y, -z); //P2
    glVertex3f(-x, -y, z); //P3
    glEnd();

//right
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x, -y, -z); //P1
    glVertex3f(-x, y, -z); //P2
    glVertex3f(x, -y, z); //P3
    glEnd();

//left
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-x, -y, -z); //P1
    glVertex3f(-x, y, -z); //P2
    glVertex3f(-x, -y, z); //P3
    glEnd();

//back
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x, -y, -z); //P1
    glVertex3f(-x, y, -z); //P2
    glVertex3f(-x, -y, -z); //P3
    glEnd();

    // glFlush();
}
void reshape(int x, int y)
{
    if(y==0||x==0)
        return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,(GLdouble)x/(GLdouble)y,0.6,40);
}
