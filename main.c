#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>
#include <stdio.h>

#define DRAW_POINT 1
#define DRAW_CIRCLE 2
#define DRAW_TRIANGLE 3
#define DRAW_RACTANGLE 4
//////

int mainMenu, colorMenu, drawMenu;
int X, Y, r, g, b;
int checkCase=0;
int flipX = 800, flipY = 500;
void display();
void menuFunc();
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, flipX, flipY, 0.0);

}

void drawSubMenu(int option){
// Handle submenu options for drawing
    switch(option)
    {
        case DRAW_POINT:
            checkCase=0;
            break;
        case DRAW_CIRCLE:
            checkCase=1;
            break;
        case DRAW_TRIANGLE:
            // Handle drawing a triangle
            break;
        case DRAW_RACTANGLE:
            // Handle drawing a rectangle
            break;
    }
}
void colorSubMenu(int option)
{
    switch(option)
    {
    case 1:
        glColor3f(1.0, 0.0, 0.0); // red
        r=1;
        g=0;
        b=0;
        break;
    case 2:
        glColor3f(0.0, 1.0, 0.0); // green
        r=0;
        g=1;
        b=0;
        break;
    case 3:
        glColor3f(0.0, 0.0, 1.0); // blue
        r=0;
        g=0;
        b=1;
        break;
    }
}

void mainMenuFunc(int option)
{
    //switch(option)
    //{
    //    case COLOR:
//
//            // Handle menu option 1

//           break;
//        // Add more cases for other menu options as needed
//}
}

void createMenu()
{
    colorMenu = glutCreateMenu(colorSubMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);

   drawMenu = glutCreateMenu(drawSubMenu);
    glutAddMenuEntry("Draw Point", DRAW_POINT);
  glutAddMenuEntry("Draw Circle", DRAW_CIRCLE);

    mainMenu = glutCreateMenu(mainMenuFunc);
    glutAddSubMenu("Change Color", colorMenu);
     glutAddSubMenu("Draw", drawMenu);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void plotQ(int x, int y, int xcenter, int ycenter){
    glVertex2d(x + xcenter, y + ycenter);//Q1
    glVertex2d(y + xcenter, x + ycenter);//Q2
    glVertex2d(y + xcenter, -x + ycenter);//Q3
    glVertex2d(x + xcenter, -y + ycenter);//Q4
    glVertex2d(-x + xcenter, -y + ycenter);//Q5
    glVertex2d(-y + xcenter, -x + ycenter);//Q6
    glVertex2d(-y + xcenter, x + ycenter);//Q7
    glVertex2d(-x + xcenter, y + ycenter);//Q8
}
void draw()
{
    if(checkCase==0){
        glPointSize(2);
        glColor3f(r,g,b);
        glBegin(GL_POINTS);
        glVertex2i(X, Y);
        glEnd();
        glFlush();
    }
    else if(checkCase==1){
        int xcenter = X, ycenter = Y, r = 80;
        int x = 0, y = r;
        int p = 1-r;
        glColor3f(r,g,b);
        glPointSize(2);
        glBegin(GL_POINTS);
        glVertex2d(x + xcenter, y + ycenter);
        glEnd();
        while(x<y)
        {
            x++;
            if(p<0)
            {
                p = p+2*x+1;
            }
            else
            {
                y--;
                p = p+2*x+1-2*y;
            }
            glBegin(GL_POINTS);
            plotQ(x,y,xcenter,ycenter);
            glEnd();
            glFlush();
        }
    }

}
void mouse(int button, int state, int x, int y) //จับการคลิกของเมาส์
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

void motion(int x, int y) //จับการเคลื่อนไหวของเมาส์
{
    X = x;
    Y = y;
    printf("(%d,%d)\n", X, Y);
    draw();
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
    createMenu();
    glutDisplayFunc(display);

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
