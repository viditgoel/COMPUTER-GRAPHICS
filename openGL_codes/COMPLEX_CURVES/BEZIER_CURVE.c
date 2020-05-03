#include <GL/glut.h>
#include <stdio.h>

GLfloat P[4][3] = {
                    { -4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0}, 
                    {2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}
                  };

//INIT FUNCTION:.....................................................................
void init(void)
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glShadeModel(GL_FLAT);
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &P[0][0]);
   glEnable(GL_MAP1_VERTEX_3);
}

//DISPLAY FUNCTION:.................................................................
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_LINE_STRIP);
   for(int i=0; i<=30; i++) 
   {
      glEvalCoord1f(i/30.0);                  //BEZIER CURVE
   }   
   glEnd();
   
   //DOTS...................
   glPointSize(5.0);
   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_POINTS);
   for (int i=0; i<4; i++)
   {	   
      glVertex3fv(&P[i][0]);
   }   
   glEnd();
   glFlush();
}

//RESHAPE FUNCTION:.................................................................
void reshape(int w, int h)
{
   glViewport(0, 0, w, h); 			//W and H are (GLsizie)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
   {
       glOrtho(-5.0, 5.0, -5.0, 5.0,-5.0, 5.0);     //Use for 3D u can Multiplication with 
   }                                                 //W and H for GLfloat values
   else
   {   
       glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
   }
}

//MAIN FUNCTION:..................................................................
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutCreateWindow("CURVE: BEZIER CURVE");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}

