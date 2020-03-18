#include<GL/glut.h>
#include<stdio.h>

int init()
{
glClearColor(1,1,1,0);
gluOrtho2D(-500,500,-500,500);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
int a,b,x,y,d;
printf("Enter the r-x of ellipse");
scanf("%d",&a);
printf("Enter the r-y of ellipse");
scanf("%d",&b);

x=0;
y=b;

d=(b*b)+(a*a*(0.25-b));
glColor3f(0,0,1);
glBegin(GL_POINTS);
glVertex2f(x,y);
glVertex2f(x,-y);
glEnd();
printf("%d %d",x,y);
while((x*b*b)<=(y*a*a))
{

if(d<=0)
{
d=d+b*b*((2*x)+3);
}
else
{
d=d+b*b*((2*x)+3)-a*a*((2*y)-2);
y=y-1;
}
x=x+1;


glColor3f(0,0,1);
glBegin(GL_POINTS);
glVertex2f(x,y);
glVertex2f(-x,y);
glVertex2f(x,-y);
glVertex2f(-x,-y);
glEnd();
}

d=(b*b*(x+0.5)*(x+0.5))+(a*a*(y-1)*(y-1))-(a*a*b*b);

while(y!=0)
{
if(d<=0)
{
d=d+2*b*b*(x+1)-(a*a*(2*y-3));
x=x+1;
}
else
{
d=d+(a*a*(3-2*y));
}
y=y-1;

printf("hello");
glColor3f(0,0,1);
glBegin(GL_POINTS);
glVertex2f(x,y);
glVertex2f(-x,y);
glVertex2f(x,-y);
glVertex2f(-x,-y);
glEnd();
}



glColor3f(1,0,0);
glRasterPos2f(-500,-500);
glutBitmapString(GLUT_BITMAP_HELVETICA_10,"NAMAN MANCHANDA:72");

glFlush();
}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(200,200);
glutCreateWindow("ellipse bresenham");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
