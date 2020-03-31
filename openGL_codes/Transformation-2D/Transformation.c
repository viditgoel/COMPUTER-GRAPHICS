#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int pntX1, pntY1,choice, edges;
int pntX[100];
int pntY[100];
int transX, transY;
double scaleX, scaleY;
double angle, angleRad;
char reflectionAxis, shearingAxis;
int shearingX, shearingY;
int constant;
double slope,theta;

void myInit(void)
{
        glClearColor(1,1,1,0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(4.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-500, 500, -500, 500);
}


//TRANSFORMATION FUNCTIONS:
//POLYGON: 
void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	for (int i = 0; i < edges; i++)
	{
	glVertex2f(pntX[i], pntY[i]);
	}
	glEnd();
}

//POLYGON TRANSLATION:
void drawPolygonTrans(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	for (int i = 0; i < edges; i++)
	{
	glVertex2f(pntX[i] + x, pntY[i] + y);
	}
	glEnd();
}

//POLYGON SCALING:
void drawPolygonScale(double x, double y)
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	for (int i = 0; i < edges; i++)
	{
	glVertex2f((pntX[i] * x),(pntY[i] * y));
	}
	glEnd();
}

//POLYGON ROTATION:
void drawPolygonRotation(double angleRad)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
	glVertex2f(((pntX[i]*cos(angleRad)) - (pntY[i]*sin(angleRad))), ((pntX[i]*sin(angleRad)) + (pntY[i]*cos(angleRad))));
	}
	glEnd();
}

//POLYGON REFLECTION:
void drawPolygonReflection(char reflectionAxis)
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);

	if (reflectionAxis == 'x' || reflectionAxis == 'X')           //for reflection about x axis
	{
		for (int i = 0; i < edges; i++)
		{
		glVertex2f(pntX[i],pntY[i]*-1);
                }
	}
	
	else if (reflectionAxis == 'y' || reflectionAxis == 'Y')       //for reflection about y axis
	{
		for (int i = 0; i < edges; i++)
		{
		glVertex2f(pntX[i]*-1,pntY[i]);
		}
	}
	else if (reflectionAxis == 'e' || reflectionAxis == 'E')       //for reflection about y=x axis
        {
                for (int i = 0; i < edges; i++)
                {
                glVertex2f(pntX[i]*-1,pntY[i]*-1);
                }
        }

	glEnd();
}

//POLYGON SHEARING:
void drawPolygonShearing()
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);

	if (shearingAxis == 'x' || shearingAxis == 'X')
	{
		glVertex2f(pntX[0], pntY[0]);

		glVertex2f(pntX[1] + shearingX*pntY[1], pntY[1]);
		glVertex2f(pntX[2] + shearingX*pntY[2], pntY[2]);

		glVertex2f(pntX[3], pntY[3]);
	}
	else if (shearingAxis == 'y' || shearingAxis == 'Y')
	{
		glVertex2f(pntX[0], pntY[0]);
		glVertex2f(pntX[1], pntY[1]);
		
		glVertex2f(pntX[2], pntY[2] + shearingY*pntX[2]);
		glVertex2f(pntX[3], pntY[3] + shearingY*pntX[3]);
	}
	glEnd();
}
//Reflection about any arbitary line
void drawPolygonReflectionLine()
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);

	
		for (int i = 0; i < edges; i++)
		{
		int x1=cos(2*theta)*pntX[i]+pntY[i]*sin(2*theta)-constant*sin(2*theta);
		int y1=sin(2*theta)*pntX[i]-cos(2*theta)*pntY[i]+constant*(1+cos(2*theta));
		glVertex2f(x1,y1);
                }
	
	glEnd();

}

//DISPLAY FUNCTION:
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);

	if (choice == 1)
	{
		drawPolygon();
		drawPolygonTrans(transX, transY);
	}
	else if (choice == 2)
	{
		drawPolygon();
		drawPolygonScale(scaleX, scaleY);
	}
	else if (choice == 3)
	{
		drawPolygon();
		drawPolygonRotation(angleRad);
	}
	else if (choice == 4)
	{
		drawPolygon();
		drawPolygonReflection(reflectionAxis);
	}
	else if (choice == 5)
	{
		drawPolygon();
		drawPolygonShearing();
	}
	else if (choice == 6)
	{
		drawPolygon();
		drawPolygonReflectionLine();
	}

	glFlush();
}


//MAIN FUNCTION:
int  main(int argc, char** argv)
{
	printf( "Enter your choice:\n");
	printf("1. Translation\n");
	printf("2. Scaling\n");
	printf("3. Rotation\n");
	printf("4. Reflection\n");
	printf("5. Shearing\n");
	printf("6. Reflection about any arbitary line in y=mx+c\n");
	printf("7. Exit\n");

	scanf("%d",&choice);

	if (choice == 7) 
	{
		return 0;
	}

	printf("\nInitial POLYGON:\n");

	printf("Enter total  no. of vertices:\n");
        scanf("%d",&edges);
	for (int i = 0; i < edges; i++)
	{
		printf( "Enter co-ordinates for %d vertex  " ,(i + 1));
                scanf("%d %d",&pntX1,&pntY1);
		pntX[i]=pntX1;   
                pntY[i]=pntY1;    
 
	}

	if (choice == 1)
	{
		printf("Enter the translation factor for X and Y: "); 
                scanf("%d %d",&transX,&transY);
	}
	else if (choice == 2)
	{
		printf("Enter the scaling factor for X and Y: "); 
                scanf("%le %le",&scaleX,&scaleY);
	}
	else if (choice == 3)
	{
		printf("Enter the angle for rotation: "); 
		scanf("%le",&angle);
		angleRad = angle * 3.1416 / 180;
	}
	else if (choice == 4)
	{
		printf("Enter reflection axis ( x or y or enter e/E for x=y): "); 
		scanf(" %c",&reflectionAxis);
	}
	else if (choice == 5)
	{
		printf("Enter about axis ( x or y ): "); 
		scanf(" %c",&shearingAxis);
		if (shearingAxis == 'x' || shearingAxis == 'X')
		{
			printf("Enter the shearing factor for X: "); 
			scanf("%d" ,&shearingX);
		}
		else
		{
			printf("Enter the shearing factor for Y: "); 
			scanf("%d",&shearingY);
		}
	}
        else if (choice == 6)
	{
		printf("Enter the slope m of line ");
		scanf("%le",&slope);
		printf("Enter the constant of line ");
		scanf("%d",&constant);
		theta=atan(slope);	
	}
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Transformations-VIDIT GOEL");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

