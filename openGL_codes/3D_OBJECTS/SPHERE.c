#include<GL/glut.h>

//INIT FUNCTION:............................................................................
void init()
{
    GLfloat light_specular[] = {1.0, 0.0, 0.0, 1.0};    //LIGHTNING
    GLfloat light_diffuse[] =  {1.0, 1.0, 0.0, 1.0};    //LIGHTNING2
    
    GLfloat shade_shininess[] = {30.0};
    
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };  //Position of light

    glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);
    glMaterialfv(GL_FRONT, GL_SPECULAR, light_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, shade_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

//DISPLAY FUNCTION:........................................................................
void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Sphere Function.......
    glutSolidSphere(1,500,500);    
    glFlush();
}

//RENDERING of Area FUNCTION..............................................................
void Render_Area(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-1.5, 1.5, -1.5, 1.5, -10.0, 10.0);      //Use for 3D Structures
    glMatrixMode(GL_MODELVIEW);
}

//MAIN FUNCTION..........................................................................
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize (640,480);
    glutInitWindowPosition (200,200);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("SPHERE: VIDIT GOEL"); 
    glutDisplayFunc(display);
    glutReshapeFunc(Render_Area);
    init();
    glutMainLoop();
}

