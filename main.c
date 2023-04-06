#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>
#include <stdio.h>

#define DRAW_POINT 1
#define DRAW_CIRCLE 2
#define DRAW_TRIANGLE 3
#define DRAW_RACTANGLE 4
#define Delete01 5
#define DRAW_Lines 6


int mainMenu, colorMenu, drawMenu;
int X, Y, r, g, b;
int checkCase=0;
int aa=0,sizeDelete=10,sizeTri=50,sizeRac=50,bb=0,first;
int Rx=0,Ry=0;
int flipX = 800, flipY = 500;
void display();
void menuFunc();
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, flipX, flipY, 0.0);

}

void drawSubMenu(int option)
{
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
        checkCase=3;
        break;
    case DRAW_RACTANGLE:
        checkCase=4;
        break;
    case DRAW_Lines:
        checkCase=6;
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
    case 4:
        glColor3f(0.0, 0.0, 0.0); // blue
        r=0;
        g=0;
        b=0;
        break;
    }
}

void mainMenuFunc(int option)
{
    switch(option)
    {
    case Delete01:
        checkCase=2;
        break;
//        // Add more cases for other menu options as needed
    }
}

void createMenu()
{
    colorMenu = glutCreateMenu(colorSubMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    glutAddMenuEntry("Black", 4);

    drawMenu = glutCreateMenu(drawSubMenu);
    glutAddMenuEntry("Draw Point", DRAW_POINT);
    glutAddMenuEntry("Draw Circle", DRAW_CIRCLE);
    glutAddMenuEntry("Draw Triangle", DRAW_TRIANGLE);
    glutAddMenuEntry("Draw Ractangle", DRAW_RACTANGLE);
    glutAddMenuEntry("Draw Line", DRAW_Lines);

    mainMenu = glutCreateMenu(mainMenuFunc);
    glutAddSubMenu("Change Color", colorMenu);
    glutAddSubMenu("Draw", drawMenu);
    glutAddMenuEntry("Delete", Delete01);


    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void plotQ(int x, int y, int xcenter, int ycenter)
{
    glVertex2d(x + xcenter, y + ycenter);//Q1
    glVertex2d(y + xcenter, x + ycenter);//Q2
    glVertex2d(y + xcenter, -x + ycenter);//Q3
    glVertex2d(x + xcenter, -y + ycenter);//Q4
    glVertex2d(-x + xcenter, -y + ycenter);//Q5
    glVertex2d(-y + xcenter, -x + ycenter);//Q6
    glVertex2d(-y + xcenter, x + ycenter);//Q7
    glVertex2d(-x + xcenter, y + ycenter);//Q8
}
void DDD(X1,Y1,X2,Y2){
    double x1 = X1, y1 = Y1, x2 = X2, y2 = Y2;
    float dx = (x2-x1);
    float dy = (y2-y1);
    float step, xinc, yinc, x, y;

    if(abs(dx) > abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    xinc = dx/(float)step;
    yinc = dy/(float)step;

    x = x1;
    y = y1;

    glColor3f(r,g,b);
    glPointSize(2);

    for(int i = 0; i < step; i++){
        x+=xinc;
        y+=yinc;
        glBegin(GL_POINTS);
        glVertex2d(round(x),round(y));
        glEnd();
        glFlush();
    }

}
void draw()
{
    if(checkCase==0)
    {
        glPointSize(2);
        glColor3f(r,g,b);
        glBegin(GL_POINTS);
        glVertex2i(X, Y);
        glEnd();
        glFlush();
    }
    else if(checkCase==1)
    {
        int r2=0;
        if (aa>0)
        {
            aa=0;
            if(Rx>X)
            {
                r2=Rx-X;
            }
            else
            {
                r2=X-Rx;
            }
            int xcenter = X, ycenter = Y;
            int x = 0, y = r2;
            int p = 1-r2;
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
        else
        {
            Rx=X;
            Ry=Y;
            aa++;
        }
    }
    else if(checkCase==2)
    {
        glPointSize(sizeDelete);
        glColor3f(1,1,1);
        glBegin(GL_POINTS);
        glVertex2i(X, Y);
        glEnd();
        glFlush();
    }
    else if (checkCase==3){


        /*glBegin(GL_LINE_STRIP);
        glColor3f(r,g,b);
        glVertex2i(X-sizeTri,Y+sizeTri);
        glVertex2i(X+sizeTri,Y-sizeTri);
        glVertex2i(X+sizeTri*3,Y+sizeTri);
        glVertex2i(X-sizeTri,Y+sizeTri);
        glEnd();
        glFlush();*/

        DDD(X,Y-sizeTri,X-sizeTri,Y+sizeTri);
        DDD(X-sizeTri,Y+sizeTri,X+sizeTri,Y+sizeTri);
        DDD(X+sizeTri,Y+sizeTri,X,Y-sizeTri);

    }
    else if (checkCase==4){

        DDD(X-sizeRac,Y-sizeRac,X-sizeRac,Y+sizeRac);
        DDD(X-sizeRac,Y+sizeRac,X+sizeRac,Y+sizeRac);
        DDD(X+sizeRac,Y+sizeRac,X+sizeRac,Y-sizeRac);
        DDD(X+sizeRac,Y-sizeRac,X-sizeRac,Y-sizeRac);
    }
    else if(checkCase==6){

        if(bb==1){
            printf("111");
            bb=0;
            DDD(Rx,Ry,X,Y);
        }
        else{
            printf("222");
            Rx=X;
            Ry=Y;
            bb=1;
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
void keyboard(unsigned char key,int x,int y){
    if(key=='+'&&checkCase==2){
        sizeDelete+=2;
    }
    if(key=='-'&checkCase==2){
        sizeDelete-=2;
    }
    if(key=='+'&&checkCase==3){
        sizeTri+=2;
    }
    if(key=='-'&checkCase==3){
        sizeTri-=2;
    }
    if(key=='+'&&checkCase==4){
        sizeRac+=2;
    }
    if(key=='-'&checkCase==4){
        sizeRac-=2;
    }
    //glutPostRedisplay();
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
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
