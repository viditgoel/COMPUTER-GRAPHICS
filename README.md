# Hello Here is Your Computer Graphics Code

# Standard Code form


<!-- Blockquote -->
> #include<GL/glut.h> /n
>  #include<GL/gl.h>
void init()
{
glClearColor(R,G,B,Transparency);
glMatrixMode(GL_PROJECTIONS);
gluOrtho2d(xmin,xmax,ymin,ymax);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(R,G,B);
glBegin(PRIMITIVE SHAPE);
glVertex3d(X,Y,Z);
glEnd();
glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv); 
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); 
    glutInitWindowSize( xmax,ymax ); 
    glutCreateWindow("Window Name"); 
    init();  
glutDisplayFunc();
glutMainLoop();
}

* This is may
** Thsis 
<!-- Links -->
[Vidit JAVA](https://github.com/ViditGoel/MyJava)
