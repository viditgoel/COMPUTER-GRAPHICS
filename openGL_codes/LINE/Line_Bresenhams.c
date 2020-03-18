#include<GL/glut.h>
#include<GL/gl.h>


float x1,x2,y2,y1;
void init()
{
glClearColor(1.0,1.0,1.0,1.0); //Blue background
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,700,0,700);
}

void display()
{
   //glClear(GL_COLOR_BUFFER_BIT);
   int a,p,t1,t2; 			//a is case counter //p is decision parameter
   float m,temp1,temp2;  		//m is for slope
   temp1 = y2-y1; 
   temp2 = x2-x1; 
   t1 = (int)(temp1);
   t2 = (int)(temp2);
   m = temp1/temp2;
   p = (2*t1) - t2;
	
  if(m<1)
   {
    a = 1;
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    glVertex2d(x1,y1);
    glEnd();
    
	while(x1<x2)
	  {
	    x1 = x1 + 1;
	      
              if(p<0)
		{
		  p = p + (2*t1);
		  glColor3f(0,1,0);
		  glBegin(GL_POINTS);
		  glVertex2d(x1,y1);
		  glEnd();

		 }
	      
              else if(p>=0)
		 {
		    p = p + (2*t1) - (2*t2);
		    y1 = y1 + 1;
		    glColor3f(0,1,0);
		    glBegin(GL_POINTS);
		    glVertex2d(x1,y1);
		    glEnd();
	
		 }
		
            }
	}
     
     else
	{
	  a = 1;
	  glColor3f(0,1,0);
	  glBegin(GL_POINTS);
	  glVertex2d(x1,y1);
	  glEnd();

	while(y1<y2)
	  {
	    y1 = y1 + 1;
			
          if(p<0)
	   {
	    p = p + (2*t2);
            glBegin(GL_POINTS);
	    glVertex2d(x1,y1);
	    glEnd();
           }

          else if(p>=0)
	   {
	     p = p -t1 + (2*t2);
	     x1 = x1 + 1;
	     glBegin(GL_POINTS);
	     glVertex2d(x1,y1);
	     glEnd();
	
	    }
	   }	
 }
glColor3f(1,0,0);
glRasterPos2f(-500,-500);
glutBitmapString(GLUT_BITMAP_HELVETICA_10,"VIDIT GOEL:65");
     glFlush();
}

int main(int argc,char **argv)
{
	printf("Bresenham's Line Drawing Algorithm\n");
	printf("Enter first point co-ordinates\n");
	printf("x1: ");
	scanf("%f",&x1);
	printf("y1: ");
	scanf("%f",&y1);
	printf("Enter second point co-ordinates\n");
	printf("x2: ");
	scanf("%f",&x2);
	printf("y2: ");
	scanf("%f",&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(700,700);
glutCreateWindow("Brensenham Line");
init();
glutDisplayFunc(display);
glutMainLoop();
}
