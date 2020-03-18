#include<GL/glut.h>
void initgl();
void display(void);
void mouse(int button, int state, int x, int y);
void spinDisplay(void);

static GLfloat spin =0.0;
void myinit(void)
{
 glClearColor(0.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}


void mouse(int button, int state, int x, int y)
{
       switch (button) {
          case GLUT_LEFT_BUTTON:
             if (state == GLUT_DOWN)
		glutIdleFunc(spinDisplay); /* start spin */

			   break;
         case GLUT_RIGHT_BUTTON:
               if (state == GLUT_DOWN)
		 glutIdleFunc(NULL);    /* stop spin */
         break;
             default:
         break;
       }
}

/* update angle of display */
void spinDisplay(void)
{
  spin = spin + 2.0;
	if (spin > 360.0)
		spin = spin - 360.0;

  glutPostRedisplay();

}
 
void hut(void)
{
	 glClear(GL_COLOR_BUFFER_BIT);


   glPushMatrix(); /* save current transformation state on stack */

	glRotatef(spin,1.5,1.5,0.0);/* rotate about z-axis */


   glBegin(GL_POLYGON);             /* POLYGON with 4 Verticies */
      glVertex3f (0.25, 0.25, 0.0);
      glVertex3f (0.75, 0.25, 0.0);
      glVertex3f (0.75, 0.75, 0.0);
      glVertex3f (0.25, 0.75, 0.0);
   glEnd();

   glPopMatrix(); /* reset to previous transformation state */

   //glFlush();
   glutSwapBuffers();

//	
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.7,0.4,0.2);

glBegin(GL_POLYGON);
glVertex3f (0.1, 0.1, 0.0);
        glVertex3f (0.4, 0.1, 0.0);
        glVertex3f (0.4, 0.5, 0.0);
        glVertex3f (0.1, 0.5, 0.0);
    glEnd();
glColor3f(1.0,1.0,0.0);

glBegin(GL_POLYGON);
glVertex3f (0.10, 0.5, 0.0);
        glVertex3f (0.4, 0.5, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
       glEnd();
glColor3f(0.0,0.0,1.0);

glBegin(GL_POLYGON);
glVertex3f (0.4, 0.1, 0.0);
        glVertex3f (0.8, 0.4, 0.0);
        glVertex3f (0.8, 0.75, 0.0);
        glVertex3f (0.4, 0.5, 0.0);
    glEnd();
glColor3f(0.2,0.7,0.4);

glBegin(GL_POLYGON); //anti clockwise bottom left to bottom top
glVertex3f (0.4, 0.5, 0.0);
        glVertex3f (0.8, 0.75, 0.0);
        glVertex3f (0.62, 0.93, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
    glEnd();
glFlush();
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(640,480);
glutCreateWindow("Polygon with viewport");
myinit();
glutDisplayFunc(hut);
glutMouseFunc(mouse);
glutMainLoop();
}
