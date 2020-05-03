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
}

//POLYNOMIAL FUNCTION:..............................................................
float POLYNOMIAL(float  points[][3], float x, int N)
{
  float y;
  float Num = 1.0, Den = 1.0;
  float SUM = 0.0;

  for(int i=0; i<N; ++i) 
  {
    Num = Den = 1.0;
    for(int j = 0; j<N; ++j) 
    {
      if (j == i) continue;
      Num = Num * ( x - points[j][0]);		 	 //x - xj
    }
    for(int j = 0; j<N; ++j ) 
    {
      if (j == i) continue;
      Den = Den * (points[i][0] - points[j][0]);	//xi - xj
    }
     
    SUM += Num / Den * points[i][1];
  }
  
  y = SUM;

  return y;
}

//DISPLAY FUNCTION:................................................................
void display(void)
{
   float x, y;

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_LINE_STRIP);
   for (int i=-40; i<=40; i++) 
   {
	 x = i/10.0;
         y = POLYNOMIAL(P, x, 4);
	 glVertex2f (x, y);
   }
   glEnd();
   
   //DOTS...................
   glPointSize(5.0);
   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_POINTS);
   for (int i = 0; i < 4; i++) 
   {      
      glVertex3fv(&P[i][0]);
   }
   glEnd();
   glFlush();
}

//RESHAPE FUNCTION:...............................................................
void reshape(int w, int h)
{
   glViewport(0, 0, w, h);                      //W and H are (GLsizie)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
   {   
       glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);      //Use for 3D, U can Multiply with
   }                                                  //W and H (GLfloat) 
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
   glutCreateWindow("CURVE: BEZIER_CURVE");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
  
