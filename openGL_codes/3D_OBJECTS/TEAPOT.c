#include<GL/glut.h>

GLfloat x,y,z;

void display(void);

//INIT FUNCTION........................................................................
void init()
{
    GLfloat light_specular[] = { 1.0, 0.0, 1.0, 1.0 };    //LIGHTNING1   
    GLfloat light_diffuse[] =  {1.0, 0.0, 1.0, 1.0};      //LIGHTNING2 
    
    GLfloat shade_shininess[] = { 50.0 };             //SHADING1
    
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };   //Position oflight
    glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, shade_shininess);
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

//DISPLAY FUNCTION.....................................................................
void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // traslate the draw by z = -8.0(This will shows center point far as appear)
    glTranslatef(0.0,0.0,-8.0);
    
    //Transformation:Rotation:.....
    glRotatef(x,1.0,0.0,0.0);
    glRotatef(y,0.0,1.0,0.0);
    glRotatef(z,0.0,0.0,1.0);
    //Transfomation:Scaling:...... 
    glScalef(1.0,1.0,1.0);
    
    //Teapot Function:...........
    glutSolidTeapot(0.8);
    
    glFlush();        
}

//RENDERING of Area FUNCTION:..........................................................
void Render_Area(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);             //Render Full Window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-1.5, 1.5, -1.5, 1.5, -10.0, 10.0);          //Use for 3DStructures 
    glMatrixMode(GL_MODELVIEW);
}

//ROTATION SPACE:.....................................................................
void Rotate(void)
{
   x =x + 0.01;
   y+= 0.01;
   z+= 0.01;
   display();
}

//MAIN FUNCTION:....................................................................
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize (640,480);
    glutInitWindowPosition (200,200);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    x = y = z = 30.0;
    glutCreateWindow("TEAPOT: VIDIT GOEL");
    glutDisplayFunc(display);
    glutReshapeFunc (Render_Area);
    init();
    glutIdleFunc(Rotate);
    glutMainLoop();
}

