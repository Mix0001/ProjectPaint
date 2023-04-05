#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>
#include <stdio.h>

int X, Y;
int flipX = 800, flipY = 500;

void display();
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, flipX, flipY, 0.0);
}
void draw()
{
    glPointSize(2);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(X, Y);
    glEnd();
    glFlush();
}
void mouse(int button, int state, int x, int y)
{
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        X = x;
        Y = y;
        printf("(%d,%d)\n", X, Y);
        draw();
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        printf("(%d,%d)\n", X, Y);
    }
}
void motion(int x, int y)
{
    X = x;
    Y = y;
    printf("(%d,%d)\n", X, Y);
    draw();
}
void EntryDisplay(int state)
{
    if (state == GLUT_LEFT)
    {
        glutMotionFunc(NULL);
        glutMouseFunc(NULL);
        printf("Left");
    }
    else if (state == GLUT_ENTERED)
    {
        printf("Entered");
        glutMouseFunc(mouse);
        glutMotionFunc(motion);
    }
}
void display()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(flipX, flipY);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Project Paint");
    init();
    glutDisplayFunc(display);
    glutEntryFunc(EntryDisplay);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
