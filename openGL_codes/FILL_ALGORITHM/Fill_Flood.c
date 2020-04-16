#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

//Structure for Color:
struct Color 
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

//Structure for Point:
struct Point
{   
	GLint x;
	GLint y;
};

struct Point p;
struct Color newColor;

//...........................................................................//
void init() 
{
	glClearColor(1.0, 1.0, 1.0,1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 700, 0, 700);
}
//..........................................................................//
//FUNCTIONS.................................................................//
Color getPixelColor(GLint x, GLint y)
{
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

//FUNCTION: SET PIXEL COLOR:
void setPixelColor(GLint x, GLint y, Color color) 
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

//FUNCTION: FLOOD_FILL:
void floodFill(GLint x, GLint y, Color oldColor, Color newColor) 
{
	Color color;
	color = getPixelColor(x, y);

	if((color.r==oldColor.r)&&(color.g==oldColor.g)&&(color.b==oldColor.b))
	{
		setPixelColor(x, y, newColor);                        //4-connected approach u can change to 8               
		floodFill(x+1, y, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
	}
	
}

//MOUSE FUNCTION:..................................................................//
void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = {newColor.r, newColor.g, newColor.b};
	Color oldColor = {1.0, 1.0, 1.0};
        floodFill(p.x, p.y , oldColor, newColor);
}

//DISPLAY FUNCTION:.................................................................//
void display(void) 
{
	int i;
glClear(GL_COLOR_BUFFER_BIT);
	for(i=200;i<=500;i++)
	{
	 glColor3f(0,1,0);
	 glBegin(GL_POINTS);
	 glVertex2i(i,200);
	 glEnd();
	 glFlush();
	}		
	for(i=200;i<=500;i++)
	{
	 glColor3f(1,0,0);
	 glBegin(GL_POINTS);
	 glVertex2i(500,i);
	 glEnd();
	 glFlush();
	}
	for(i=500;i>=200;i--)
	{
	 glColor3f(0,0,1);
	 glBegin(GL_POINTS);
	 glVertex2i(i,500);
	 glEnd();
	 glFlush();
	}
	for(i=500;i>=200;i--)
	{
	 glColor3f(1.4,1,0);
	 glBegin(GL_POINTS);
	 glVertex2i(200,i);
	 glEnd();
	 glFlush();
	}
}

//MAIN............................................................................//
int main(int argc, char** argv)
{      
        printf("Enter the newColor values for Seed Pixel(IN GLFLOAT): ");
        scanf("%f%f%f",&newColor.r,&newColor.g,&newColor.b);
	
        printf("Enter the Point for Seed Pixel(IN INT,Both values must be equal): ");
        scanf("%d%d",&p.x,&p.y);

        glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Flood Fill :BY VIDIT GOEL");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}

