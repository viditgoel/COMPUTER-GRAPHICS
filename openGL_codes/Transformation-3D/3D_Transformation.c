#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

typedef float Matrix4 [4][4];
Matrix4 theMatrix;

static GLfloat input[8][3]={ {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},{30,30,0},{80,30,0},{80,80,0},{30,80,0} };
float output[8][3];
float tx,ty,tz;
float sx,sy,sz;
float shx,shy,shz;
float angle;
int choice,choiceRot,choiceRef,choiceShe;

//MatrixIdentity*********************************************************
void setIdentityM(Matrix4 m)
{
for(int i=0;i<4;i++)
{ for(int j=0;j<4;j++)
	{ 
        m[i][j]=(i==j);
        }
}
}

//Translation Function:*************************************
void translate(int tx,int ty,int tz)
{

for(int i=0;i<8;i++)
{
output[i][0]=input[i][0]+tx;
output[i][1]=input[i][1]+ty;
output[i][2]=input[i][2]+tz;
}
}

//Scaling Function:******************************************
void scale(int sx,int sy,int sz)
{
    theMatrix[0][0]=sx;
    theMatrix[1][1]=sy;
    theMatrix[2][2]=sz;
}

//Rotation Function:******************************************
//Parallel to x-
void RotateX(float angle) 
{
 angle = angle*3.142/180;
 theMatrix[1][1] = cos(angle);
 theMatrix[1][2] = -sin(angle);
 theMatrix[2][1] = sin(angle);
 theMatrix[2][2] = cos(angle);
}
//Parallel to y-
void RotateY(float angle) 
{
 angle = angle*3.14/180;
 theMatrix[0][0] = cos(angle);
 theMatrix[0][2] = -sin(angle);
 theMatrix[2][0] = sin(angle);
 theMatrix[2][2] = cos(angle);
}
//Parallel to z-
void RotateZ(float angle) 
{
 angle = angle*3.14/180;
 theMatrix[0][0] = cos(angle);
 theMatrix[0][1] = sin(angle);
 theMatrix[1][0] = -sin(angle);
 theMatrix[1][1] = cos(angle);
}

//Polygon Multiplication-Matrix:**********************************************
void multiplyM()
{
//4th row and column not used in scaling and translation
for(int i=0;i<8;i++)
{
  for(int j=0;j<3;j++)
  {
    output[i][j]=0;
    for(int k=0;k<3;k++)
    {
    output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];
    }
  }
}
}

//Reflection Function:******************************************************
//Reflection plane xy:
void Reflection_xy()
{
for(int i=0;i<8;i++)
{
output[i][0]=input[i][0];
output[i][1]=input[i][1];
output[i][2]=-(input[i][2]);
}
}
//Reflection plane yz:
void Reflection_yz()
{
for(int i=0;i<8;i++)
{
output[i][0]=-(input[i][0]);
output[i][1]=input[i][1];
output[i][2]=input[i][2];
}
}
//Reflection plane zx:
void Reflection_zx()
{
for(int i=0;i<8;i++)
{
output[i][0]=input[i][0];
output[i][1]=-(input[i][1]);
output[i][2]=input[i][2];
}
}

//Shearing Function:********************************************************
//Shear about x-axis:
void Shearing_x(int shy,int shz)
{
for(int i=0;i<8;i++)
{
output[i][0]=input[i][0];
output[i][1]=(input[i][1]+(shy*input[i][0]));
output[i][2]=(input[i][2]+(shz*input[i][0]));
}
}
//Shear about y-axis:
void Shearing_y(int shx,int shz)
{
for(int i=0;i<8;i++)
{
output[i][0]=(input[i][0]+(shx*input[i][1]));
output[i][1]=input[i][1];
output[i][2]=(input[i][2]+(shz*input[i][1]));
}
}
//Shear about z-axis:
void Shearing_z(int shx,int shy)
{
for(int i=0;i<8;i++)
{
output[i][0]=(input[i][0]+(shx*input[i][2]));
output[i][1]=(input[i][1]+(shy*input[i][2]));
output[i][2]=input[i][2];
}
}


//X and Y axis lines Black Line:*********************************************
void Axes(void)
{
    glColor3f (0.0, 0.0, 0.0);               // Set the color to BLACK
    
    glBegin(GL_LINES);                       // Plotting X-Axis
    glVertex2s(-1000 ,0);
    glVertex2s( 1000 ,0);
    glEnd();
    
    glBegin(GL_LINES);                       // Plotting Y-Axis
    glVertex2s(0 ,-1000);
    glVertex2s(0 , 1000);
    glEnd();
}

//Draw Polygon 3D Function:****************************************************
void draw(float a[8][3])
{
    glBegin(GL_QUADS);
    
    glColor3f(0.7,0.4,0.5);   //behind
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);

    glColor3f(0.8,0.2,0.4);  //bottom
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glVertex3fv(a[5]);
    glVertex3fv(a[4]);

    glColor3f(0.3,0.6,0.7); //left
    glVertex3fv(a[0]);
    glVertex3fv(a[4]);
    glVertex3fv(a[7]);
    glVertex3fv(a[3]);

    glColor3f(0.2,0.8,0.2);  //right
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[6]);
    glVertex3fv(a[5]);

    glColor3f(0.7,0.7,0.2); //up
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);
    glVertex3fv(a[7]);
    glVertex3fv(a[6]);

    glColor3f(1.0,0.1,0.1); //front
    glVertex3fv(a[4]);
    glVertex3fv(a[5]);
    glVertex3fv(a[6]);
    glVertex3fv(a[7]);

    glEnd();
}

//Init Method:****************************************************************
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);               
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);        // Set the no. of Co-ordinates along X & Y axes and their gappings
    glEnable(GL_DEPTH_TEST);                        // To Render the surfaces Properly according to their depths
}

//Display Function:***********************************************************
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
Axes();
glColor3f(1.0,0.0,0.0);
draw(input);
setIdentityM(theMatrix);
switch(choice)
{
//...............................................//	
case 1:                     //For Translate
    translate(tx,ty,tz);
    break;
//...............................................//    
case 2:                     //For Scaling
    scale(sx,sy,sz);
    multiplyM();
    break;
//...............................................//    
case 3:                     //For Rotation
    switch (choiceRot) 
    {
    case 1:
        RotateX(angle);
        break;
    case 2: 
	RotateY(angle);
        break;
    case 3:
        RotateZ(angle);
        break;
    default: break;
    }
    multiplyM();
    break;
//..............................................//    
case 4:                    //For Reflection 
    switch(choiceRef)
    {
    case 1:
        Reflection_xy();
        break;
    case 2:
        Reflection_yz();
        break;
    case 3:
        Reflection_zx();
        break;	
     default: break;
     }
    break;
//...............................................//
case 5:                     //For Shearing
    switch(choiceShe)
    {
    case 1:
        Shearing_x(shy,shz);
        break;
    case 2:
        Shearing_y(shx,shz);
        break;
    case 3:
        Shearing_z(shx,shy);
        break;
     default: break;
     }
    break;
    
default: break;
}  	   
draw(output);
glFlush();
}

//Main Function:****************************************************************
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1362,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("3D TRANSFORMATIONS");
    init();
    printf("Enter your choice number:\n1.Translation\n2.Scaling\n3.Rotation\n4.Reflection\n5.Shearing\n=> ");
    scanf("%d",&choice);
    switch (choice) 
    {
//.............................................................//	    
     case 1:                                  //For Translation:
           printf("\nEnter Tx,Ty &Tz: \n");
           scanf("%f%f%f",&tx,&ty,&tz);
           break;
  //...........................................................//	   
     case 2:                                 //For Scaling
           printf("\nEnter Sx,Sy & Sz: \n");
           scanf("%f%f%f",&sx,&sy,&sz);
           break;
 //............................................................//    
     case 3:                                 //For Rotation:
     printf("Enter your choice for Rotation abou axis:\n1.parallel to X-axis(y&z)\n2.parallel toY-axis(x&z)\n3.parallel to Z-axis(x&y)\n=> ");
     scanf("%d",&choiceRot);
        switch (choiceRot) 
	{
         case 1:
            printf("\nENter Rotation angle: ");
            scanf("%f",&angle);
            break;
         case 2:
            printf("\nENter Rotation angle: ");
            scanf("%f",&angle);
            break;
         case 3:
            printf("\nENter Rotation angle: ");
            scanf("%f",&angle);
            break;
         default: break;
        }
        break;
 //...........................................................//    
     case 4:                                 //For Reflection:
     printf("Enter your choice about any plane:\n1.Reflection about xy\n2.Reflection about yz\n3.Reflection about zx\n=> ");
     scanf("%d",&choiceRef);
	  switch(choiceRef)
        {
	 case 1: 
	    printf("\nHere about xy: ");
            break;	    
         case 2:
            printf("\nHere about yz: ");
            break;
	 case 3:
            printf("\nHere about zx: ");
            break;	    
	 default: break;
       }
       break;
//.............................................................//
     case 5:                                 //For Shearing:
     printf("Enter your choice about any axis:\n1.Shearing about x\n2.Shearing about y\n3.Shearing about z\n=> ");
     scanf("%d",&choiceShe);
          switch(choiceShe)
        {
         case 1:
            printf("\nEnter the value of shy, shz: ");
	    scanf("%f%f",&shy,&shz);
            break;
         case 2:
            printf("\nEnter the value of shx, shz: ");
	    scanf("%f%f",&shx,&shz);
            break;
         case 3:
            printf("\nEnter the value of shx, shy: ");
	    scanf("%f%f",&shx,&shy);
            break;
         default: break;
       }
       break;
   
     default: break;
    }
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


