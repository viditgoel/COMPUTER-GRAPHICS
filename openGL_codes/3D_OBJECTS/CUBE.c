#include <GL/glut.h>

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};    //Red Diffusion 
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};   
GLfloat n[6][3] = {  
                    {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},     //Vertex for cubes
                    {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} 
                  };
GLint faces[6][4] = { 
                     {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
                     {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} 
                    };
GLfloat v[8][3]; 


//INIT FUNCTION..................................................................................
void init(void)
{
  /* Setup cube vertex data. */
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  GLfloat mat_shininess[] = { 50.0 };
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  gluPerspective( 40.0,1.0,1.0,10.0); 
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 5.0,  
            0.0, 0.0, 0.0,     
            0.0, 1.0, 0.0);

  
  glTranslatef(0.0, 0.0, -1.0);
  glRotatef(60, 1.0, 0.0, 0.0);
  glRotatef(-20, 0.0, 0.0, 1.0);
}

//DISPLAY FUNCTION......................................................................
void display(void)
{ glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for(int i = 0; i < 6; i++) 
  {
    glBegin(GL_QUADS);
    glNormal3fv(&n[i][0]);
    glVertex3fv(&v[faces[i][0]][0]);
    glVertex3fv(&v[faces[i][1]][0]);
    glVertex3fv(&v[faces[i][2]][0]);
    glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
  glutSwapBuffers();
}

//MAIN FUNCTON...........................................................................
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize (640,480);
  glutInitWindowPosition (200,200);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("CUBE:VIDIT GOEL");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;           
}
