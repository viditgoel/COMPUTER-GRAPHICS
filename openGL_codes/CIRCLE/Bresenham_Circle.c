#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int xCenter,yCenter,r;

void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-200.0,200.0,-200.0,200.0);
}

void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void Circle()
{
  int x=0,y=r;
  int d = 3/2 - r;    // = 1 - r
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 1 ,0, 0);
  while(x<=y){
    setPixel(xCenter+x,yCenter+y);
    setPixel(xCenter+y,yCenter+x);  //find other points by symmetry
    setPixel(xCenter-x,yCenter+y);
    setPixel(xCenter+y,yCenter-x);
    setPixel(xCenter-x,yCenter-y);
    setPixel(xCenter-y,yCenter-x);
    setPixel(xCenter+x,yCenter-y);
    setPixel(xCenter-y,yCenter+x);

    if (d<0)
    {	    
  d+= (2*x)+3;
    }
    else 
    {
  d+= (2*(x-y))+5;
  y-= 1;
    }
    x++;
  }
  glColor3f(1,0,0);
  glRasterPos2f(-200,-200);
  glutBitmapString(GLUT_BITMAP_HELVETICA_10,"NAMAN MANCHANDA:72");

  glFlush();
}

int main(int argc,char **argv)
{
    
	
    printf("Enter the value of it's center");
    scanf("%d%d",&xCenter,&yCenter);
    printf("Enter the value of it's radius");
    scanf("%d",&r);    
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Circle");
    init();
    glutDisplayFunc(Circle);
    glutMainLoop();
    return 0;
}

