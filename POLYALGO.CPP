

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

#define PI 3.1415926
#define MaxSides 11

//Functions Declarations
void startP();
void funPolygon();
void DrawPolygon();
void showName(int,int,int);
void rotation();

//Variables
int initAngle=45; //Initial Angle
float rad=PI/180;
float angle=0;
int rotated;
int count=1,r=50,N;
float pointX[MaxSides];
float pointY[MaxSides];
int i,j;
int xd,yd,t1,t2;
int valid=0;     //Validity Flag
int tries=0;     //Limit for Invailid Inputs
int nside=MaxSides-1; //Max side Limit
int x1,x2,y1,y2;
float offset;

void main()  /////MAIN FUNCTION///////
{
clrscr();
int gdriver = DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

t1=getmaxx();   //Max Win X
t2=getmaxy();   //Max win Y
xd=t1/2;        //Shape Position X
yd=(t2/2)+20;   //Shape Position Y

startP();       //Initialising
funPolygon();   // Function that Envokes the Drawing Process

getch();

}
//////////////////////////END OF MAIN////////////////////////////
/*_____________________________________________________________________*/



/////////////////////////Function Definitions//////////////////////////
void DrawPolygon()
{

for(i=0;i<N;i++)
{
x1=pointX[i];
x2=pointX[i+1];
y1=pointY[i];
y2=pointY[i+1];
line(x1,y1,x2,y2);
}
line(x2,y2,pointX[0],pointY[0]);
}

/*_____________________________________________________________________*/

void showName(int x,int y,int sides)  //Function For showing names of the shapes
{
settextstyle(3,0,4);
switch(sides)
{
case 1:
outtextxy(x-50,y+r+10,"That's a point (Not a Polygon)");
break;
case 2:
outtextxy(x-50,y+r+10,"That's a line (Not a Polygon)");
break;
case 3:
outtextxy(x-50,y+r+10,"Triangle");
break;
case 4:
outtextxy(x-50,y+r+10,"Square");
break;
case 5:
outtextxy(x-50,y+r+10,"Pentagon");
break;
case 6:
outtextxy(x-50,y+r+10,"Hexagon");
break;
case 7:
outtextxy(x-50,y+r+10,"Heptagon");
break;
case 8:
outtextxy(x-50,y+r+10,"Octagon");
break;
case 9:
outtextxy(x-50,y+r+10,"Nonagon");
break;
case 10:
outtextxy(x-50,y+r+10,"Decagon");
break;
defaut:
outtextxy(x-50,y+r+10,"Nothng");
break;
}
}

/*_____________________________________________________________________*/
void funPolygon()
{
int sumAngles=0;
int interiorAngle=0;
cleardevice();
offset=360/N;
i=0;
///////////////ABDUL's INTERIER ANGLE THEOREM//////////////////
/*
Required:-
Sum of all the interior angles of a N sided Polygon is (N-2) * 180
therefore each angle will be = sum of angles / N

" To align a N sided polygone with Abdul's Polygon Algo
  The Initial angle should be half of any one
  interior angle of the polygon . "

*/
///////////////////////////////////////////////////////////////
sumAngles=(N-2)*180;
interiorAngle=sumAngles/N;
initAngle=interiorAngle/2;
for(angle=0+initAngle;angle<=360+initAngle;angle+=offset)
{
//printf("Angle at step %d : %d\n",i+1,angle);
pointX[i]=xd+(r*cos(angle*rad));  //Storing X coordinate
pointY[i]=yd+(r*sin(angle*rad));  //Storing Y coordinate
//putpixel(pointX[i],pointY[i],RED);
//printf("Point Calculated : (%d,%d)",pointX[i],pointY[i]);
i++;
//angle=angle+offset;
}

if(valid)
{
DrawPolygon();
showName(xd,yd,N);
}
}

////////////////////Initialise///////////////////
void startP()
{
cleardevice();
printf("\n\n");
printf("\t\t...................................................\n");
printf("\t\tC++ PROGRAM TO DRAW POLYGON OF N SIDES\n");
printf("\t\t...................................................\n");
while(!valid)   //Checks For Valid Input for no. of Sides
{
if(tries>1)     //Restricting no. of Invailid Inputs
{
printf("\t\t\n\n[Error] : Too many Invailid Attempts !!!");
getch();
break;
}
printf("\t\tEnter No. of Sides  ( Upto %d ) : ",nside);
scanf("%d",&N);
if(N==0 || N>MaxSides)
{
tries++;
printf("\n\r\t\t[Error] :Invailid Input !\n");
}
else
{
valid=1;
}
} // Validity Check ENDS here //

}