#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int xmin,ymin,xmax,ymax,num;   
struct point
{
    float x, y;
    int status;
    struct point *next;
}

*head=NULL;
void display(void)
{
    glBegin(GL_LINE_LOOP);     //OUTER WINDOW
    glVertex2i(xmin,ymin);
    glVertex2i(xmin,ymax);
    glVertex2i(xmax,ymax);
    glVertex2i(xmax,ymin);
    glEnd();
    glFlush();
   
    struct point *p = head;   //POLYGON
    glBegin(GL_POLYGON); 
    while(p != NULL)
    {
      	if(p->status==1)
            glVertex2i(ceil(p->x),ceil(p->y));
        p = p->next;
    }
    glEnd();
    glFlush();
}

//CLIP THE LEFT PORTION:
void leftClip()
{
    struct point *p = head;
    while(p != NULL)
    {
        if(p->next == NULL)
        {
            if(p->x < xmin && head->x < xmin)
            {
                p->status = 0;
                head->status = 0;
            }
            else if(p->x < xmin || head->x < xmin)
            {
                if(p->x < xmin) p->status = 0;
                if(head->x < xmin) head->status = 0;
                float m = (head->y - p->y)/(head->x - p->x);
                float y = m * (xmin-p->x) + p->y;
                struct point *t = (struct point*)malloc(sizeof(struct point));
                t->x = xmin;
                t->y = y;
                t->status = 1;
                t->next = head;
                head = t;
                num++;
            }
        }
        else
        {
            if(p->x < xmin && p->next->x < xmin)
            {
                p->status = 0;
                p->next->status = 0;
            }
            else if(p->x < xmin || p->next->x < xmin)
            {
                if(p->x < xmin) p->status = 0;
                if(p->next->x < xmin) p->next->status = 0;
                float m = (p->next->y - p->y)/(p->next->x - p->x);
                float y = m * (xmin-p->x) + p->y;
                struct point *t = (struct point*)malloc(sizeof(struct point));
                t->x = xmin;
                t->y = y;
                t->status = 1;
                t->next = p->next;
                p->next = t;
                p = p->next;
                num++;
            }
        }
        p = p-> next;
    }
}

//CLIP THE RIGHT PORTION:
void rightClip()
{
    struct point *p = head;
    while(p != NULL)
    {
        if(p->next == NULL)
        {
            if(p->x > xmax && head->x > xmax)
            {
                p->status = 0;
                head->status = 0;
            }
            else if(p->x > xmax || head->x > xmax)
            {
                if(p->x > xmax) p->status = 0;
                if(head->x > xmax) head->status = 0;
                float m = (head->y - p->y)/(head->x - p->x);
                float y = m * (xmax-p->x) + p->y;
                struct point *t = (struct point*)malloc(sizeof(struct point));
                t->x = xmax;
                t->y = y;
                t->status = 1;
                t->next = head;
                head = t;
                num++;
            }
        }
        else
        {
            if(p->x > xmax && p->next->x > xmax)
            {
                p->status = 0;
                p->next->status = 0;
            }
            else if(p->x > xmax || p->next->x > xmax)
            {
                if(p->x > xmax) p->status = 0;
                if(p->next->x > xmax) p->next->status = 0;
                float m = (p->next->y - p->y)/(p->next->x - p->x);
                float y = m * (xmax-p->x) + p->y;
                struct point *t = (struct point*)malloc(sizeof(struct point));
                t->x = xmax;
                t->y = y;
                t->status = 1;
                t->next = p->next;
                p->next = t;
                p = p->next;
                num++;
            }
        }
        p = p-> next;
    }
}

//CLIP THE UPPER PORTION:
void upClip()
{
    struct point *p = head;
    while(p != NULL)
    {
        if(p->next == NULL)
        {
            if(p->y > ymax && head->y > ymax)
            {
                p->status = 0;
                head->status = 0;
            }
            else if(p->y > ymax || head->y > ymax)
            {
                if(p->y > ymax) p->status = 0;
                if(head->y > ymax) head->status = 0;
                float m = (head->y - p->y)/(head->x - p->x);
                float x = (ymax-p->y)/m + p->x;
                struct point *t = (struct point*)malloc(sizeof(struct point));
                t->x = x;
                t->y = ymax;
                t->status = 1;
                t->next = head;
                head = t;
                num++;
            }
        }
        else
        {
            if(p->y > ymax && p->next->y > ymax)
            {
                p->status = 0;
                p->next->status = 0;
            }
            else if(p->y > xmax || p->next->y > xmax)
            {
                if(p->y > xmax) p->status = 0;
                if(p->next->y > xmax) p->next->status = 0;
                float m = (p->next->y - p->y)/(p->next->x - p->x);
                float x = (ymax-p->y)/m + p->x;
                struct point *t = (struct point*)malloc(sizeof(struct point));
                t->x = x;
                t->y = ymax;
                t->status = 1;
                t->next = p->next;
                p->next = t;
                p = p->next;
                num++;
            }
        }
        p = p-> next;
    }
}

//CLIP THE LOWER PORTION:
void downClip()
{
    struct point *p = head;
    while(p != NULL)
    {
        if(p->next == NULL)
        {
            if(p->y < ymin && head->y < ymin)
            {
                p->status = 0;
                head->status = 0;
            }
            else if(p->y < ymin || head->y < ymin)
            {
                if(p->y < ymin) p->status = 0;
                if(head->y < ymin) head->status = 0;
                float m = (head->y - p->y)/(head->x - p->x);
                float x = (ymin-p->y)/m + p->x;
                struct point *t = (struct point*)malloc(sizeof(struct point));
                t->x = x;
                t->y = ymin;
                t->status = 1;
                t->next = head;
                head = t;
                num++;
            }
        }
        else
        {
            if(p->y < ymin && p->next->y < ymin)
            {
                p->status = 0;
                p->next->status = 0;
            }
            else if(p->y < ymin || p->next->y < ymin)
            {
                if(p->y < ymin) p->status = 0;
                if(p->next->y < ymin) p->next->status = 0;
                float m = (p->next->y - p->y)/(p->next->x - p->x);
                float x = (ymin-p->y)/m + p->x;
                struct point *t = (struct point*)malloc(sizeof(struct point));
                t->x = x;
                t->y = ymin;
                t->status = 1;
                t->next = p->next;
                p->next = t;
                p = p->next;
                num++;
            }
        }
        p = p-> next;
    }
}

//INSERT POINTS FOR POLYGON:
void insertPoints(int x,int y)
{
    struct point *p = (struct point*)malloc(sizeof(struct point));
    p->x = x;
    p->y = y;
    p->status = 1;
    p->next = NULL;
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        struct point *t = head;
        while(t->next != NULL)
            t = t->next;
        t->next = p;
    }
}

//NUMBER OF VERTICES YOU HAVE TO ENTER: 
void inputPoints()
{
    int i = 1;
    while(i <= num)
    {
        float x,y;
        printf("Enter the coordinate->%d: ",i);
        scanf("%f %f",&x,&y);
        insertPoints(x,y);
        i++;
    }
}


void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
}

int main(int argc, char** argv) {
printf("Enter the left bottom corner: ");   scanf("%d %d",&xmin,&ymin);
printf("Enter the right up corner: ");      scanf("%d %d",&xmax,&ymax);
printf("Enter the number of coordinates: ");scanf("%d",&num);
inputPoints();
leftClip();
upClip();
rightClip();
downClip();
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (10,10);
glutCreateWindow ("Sutherland Hodgeman Polygon Clipping...");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}


