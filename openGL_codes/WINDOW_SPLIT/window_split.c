#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/freeglut.h>



void Display()
{glClear( GL_COLOR_BUFFER_BIT );
//points:
glBegin(GL_POINTS);
glColor3f(0,1,0 );
glVertex2f(-400,-400);
glVertex2f(-400,-330);
glVertex2f(-360,-320);
glVertex2f(-320,-320);
glVertex2f(-320,-400);
glVertex2f(-330,-470);
glVertex2f(-400,-470);
glVertex2f(-310,-400);
glVertex2f(-390,-320);
glVertex2f(-380,-326);
glVertex2f(-370,-355);
glVertex2f(-380,-444);
glVertex2f(-360,-370);
glVertex2f(-370,-388);
glEnd();

//triangle:
glBegin(GL_TRIANGLES);
glVertex2f( 100,200 );
glVertex2f( 200,400 );
glVertex2f( 300,200 );
glEnd();

//lines:
glBegin(GL_LINES);
glColor3f(0,1,1);
glVertex2f(-450,50);
glVertex2f(-450,450);
glVertex2f(-350,50);
glVertex2f(-350,450);
glVertex2f(-400,50);
glVertex2f(-400,450);
glEnd();

//line strip:
glBegin(GL_LINE_STRIP);
glColor3f(0.0,1.0,0.0);
glVertex2f(-200,50);
glVertex2f(-150,200);
glVertex2f(80,200);
glVertex2f(200,50);
glVertex2f(0,10);
glEnd();

//line loop
glBegin(GL_LINE_STRIP);
glColor3f(0.0,1.0,0.0);
glVertex2f(0,0);
glVertex2f(-100,-100);
glVertex2f(-100,-200);
glVertex2f(0,-300);
glVertex2f(100,-200);
glVertex2f(100,-100);
glVertex2f(0,0);
glEnd();

glColor3f(1,0,0);
glRasterPos2f(-500,-500);
glutBitmapString(GLUT_BITMAP_HELVETICA_10,"NAMAN MANCHANDA:72");

glFlush();
glutSwapBuffers();
}


void Display1()

{
glClear( GL_COLOR_BUFFER_BIT );
//polygon:
glBegin(GL_POLYGON);
glColor3f(1,0,1 );
glVertex2f(-480,-250);
glVertex2f(-400,-200);
glVertex2f(-320,-100);
glVertex2f(-240,-180);
glVertex2f(-160,-200);
glVertex2f(-280,-270);
glVertex2f(-360,-360);
glVertex2f(-420,-410);
glEnd();

//triangle:
glBegin(GL_TRIANGLE_FAN);
glColor3f(1,0,1 );
glVertex2f( 50,50 );
glVertex2f( 100,200 );
glVertex2f( 200,200 );
glBegin(GL_POLYGON);
glColor3f(1,0,0);
glVertex2f( 50,50 );
glVertex2f( 200,200 );
glVertex2f( 300,100 );
glBegin(GL_POLYGON);
glColor3f(1,1,0);
glVertex2f( 50,50 );
glVertex2f( 300,100 );
glVertex2f( 400,50 );
glBegin(GL_POLYGON);
glColor3f(0,0,1);
glVertex2f( 50,50 );
glVertex2f( 400,50 );
glVertex2f( 350,-100 );
glEnd();
glColor3f(1,0,0);
glRasterPos2f(-500,-500);
glutBitmapString(GLUT_BITMAP_HELVETICA_10,"NAMAN MANCHANDA:72");
glFlush();
glutSwapBuffers();
}



int main(int argc, char* argv[])
    {
         glutInit(&argc, argv);
         glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
         glutInitWindowSize(500,500);



         glutInitWindowPosition(0,0);
         glutCreateWindow("window1");
         glClearColor(1,1,1,1);
         gluOrtho2D(-500,500,-500,500);
         glutDisplayFunc(Display);

        

         glutInitWindowPosition(500,500);
         glutCreateWindow("window2");
         glClearColor(1,1,1,1);
         gluOrtho2D(-500,500,-500,500);
         glutDisplayFunc(Display1);
         glutMainLoop();

         

         return 0;

    }
