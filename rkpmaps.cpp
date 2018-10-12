#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include <limits.h>
#define V 30

int des,sr;
int w=0, u=0,path1[30];
float k,l;
int arr[30][30]={0},arr1[V];
struct node
{
    float x;
    float y;
    int id;
    struct node *link;
};

struct node *head=NULL;
void input(int[]);
void insert(float xd,float yd,int i)
{
    struct node *newnode,*temp;
    newnode=new node();

    newnode->x=xd;
    newnode->y=yd;
    newnode->link=NULL;
    newnode->id=i;
    if(head==NULL)
    {
	head=newnode;
    }
    else
	{
	    temp=head;
	    while(temp->link!=NULL)
	    {
	       temp=temp->link;
	    }
	    temp->link=newnode;
	}

}


void traverse()

{
    struct node*temp;
    int xa,ya;

    temp=head;
    char a[20];
    while(temp->link!=NULL)
    {

     sprintf(a,"%d",temp->id);
     outtextxy(temp->x+2,temp->y+2,a);

     circle(temp->x,temp->y,2);
     xa=temp->x;
     ya=temp->y;
    temp=temp->link;
    if(xa==temp->x||ya==temp->y)
    {
     line(xa,ya,temp->x,temp->y);
    }
    }

    sprintf(a,"%d",temp->id);
    outtextxy(temp->x+2,temp->y+2,a);
    circle(temp->x,temp->y,2);

}
void join()
{
 line(10,0,10,130);
 line(110,0,110,130);
 line(260,0,260,130);
 line(360,0,360,130);
 line(460,0,460,130);
 line(560,0,560,230);
 line(460,0,560,0);
 line(460,230,560,230);
 line(460,330,560,330);
 line(110,130,110,330);
 line(110,330,110,430);
 line(210,130,210,230);
 line(210,230,210,430);
 line(410,330,410,430);
 line(310,330,310,430);
 line(560,430,560,330);
 line(110,330,210,330);
 line(210,230,460,230);
}
void matrix()
{
    for(int i=0; i<30; i++)
	{
	    for(int j=0; j<30; j++)
	    {


		    arr[i][j]=0;

	    }
	}


    arr[0][14]=130;
    arr[0][1]=100;
    arr[1][2]=150;
    arr[1][15]=130;
    arr[2][3]=100;

    arr[2][17]=130;
    arr[3][4]=100;
    arr[3][18]=130;
    arr[4][5]=100;
    arr[4][19]=130;
    arr[5][25]=230;
    arr[25][26]=100;
    arr[6][26]=100;
    arr[6][9]=150;
    arr[9][10]=100;
    arr[10][11]=100;
    arr[11][12]=100;
    arr[12][13]=100;
    arr[13][14]=200;
    arr[14][15]=100;
    arr[15][16]=100;
    arr[16][17]=50;
    arr[17][18]=100;
    arr[18][19]=100;
   arr[19][20]=100;
    arr[16][23]=100;
    arr[23][20]=250;
    arr[23][22]=100;
    arr[15][24]=200;
    arr[20][21]=100;
    arr[17][18]=90;
    arr[18][19]=97;
    arr[19][20]=100;
    arr[22][21]=250;
    arr[26][21]=100;

    for(int m=0; m<30; m++)
	{
	    for(int n=0; n<30; n++)
	    {
		if(arr[m][n]!=0)
		{
		    arr[n][m]=arr[m][n];
		  }
	    }
	}


}
void text()
{
    setcolor(WHITE);
    outtextxy(20,60,"RECEPTION");
    outtextxy(120,60,"F BLOCK");
    outtextxy(270,60,"E BLOCK");
    outtextxy(370,60,"A BLOCK");
    outtextxy(470,100,"ASSEMBLY");
    outtextxy(20,250,"GIRLS");
   outtextxy(20,280,"HOSTEL");
   outtextxy(120,230,"OAT");
   outtextxy(300,190,"GARDEN");
   outtextxy(300,300,"CIRCULAR");
   outtextxy(300,280,"BLOCK");
   outtextxy(500,280,"B BLOCK");
   outtextxy(420,380,"C BLOCK");
   outtextxy(320,380,"BLOSSOMS");
   outtextxy(220,380,"D BLOCK");
   outtextxy(120,380,"H BLOCK");


 }


void colouring()
{
  setcolor(BROWN);
    setfillstyle(INTERLEAVE_FILL,BROWN);
    rectangle(10,130,110,0);//reception
    floodfill(80,100,BROWN);
    rectangle(110,130,260,0);//F BLOCK
    floodfill(140,100,BROWN);
    rectangle(260,130,360,0);//E
    floodfill(300,100,BROWN);
    /*rectangle(360,130,460,0);//A
    floodfill(400,100,BROWN);
    rectangle(460,330,560,230);//B
    floodfill(490,300,BROWN);
    rectangle(410,430,560,330);//C
    floodfill(550,400,BROWN);
    rectangle(430,280,470,320);//D
    floodfill(450,290,BROWN);
    rectangle(330,280,370,320);//H
    floodfill(350,290,BROWN);
    rectangle(130,100,170,100);//oat
    rectangle(70,90,30,240);//abb3
    floodfill(40,190,BROWN);
    rectangle(230,40,270,250);//acdblock
    floodfill(250,190,BROWN);

    setcolor(GREEN);
    setfillstyle(CLOSE_DOT_FILL,GREEN);
    rectangle(130,157,170,220);//ground
    floodfill(150,170,GREEN);
    rectangle(70,280,33,300);//lt5
    floodfill(35,290,GREEN);
    rectangle(130,30,170,40);
    floodfill(140,35,GREEN);
    rectangle(210,260,230,335);
    floodfill(211,270,GREEN);


    setcolor(7);
    setfillstyle(BKSLASH_FILL,7);
    rectangle(70,150,30,215);//cafe
     floodfill(50,190,7);
    rectangle(130,280,170,320);//bbcourt
     floodfill(150,290,7);
    setcolor(4);
    setfillstyle(SOLID_FILL,4) ;
    rectangle(270,340,290,300);//temple
    floodfill(280,320,4);

    setcolor(1);
    setfillstyle(SOLID_FILL,1);
     rectangle(420,430,480,410);//atoz
    floodfill(430,420,1);
    setcolor(9);
    setfillstyle(XHATCH_FILL,9);
    rectangle(245,290,255,330);
    floodfill(246,295,9);  */
}

int minDistance(int dist[], int sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
	if (sptSet[v] == 0 && dist[v] <= min)
	    min = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest path from source to j
// using parent array

void printPath(int parent[], int j)
{

  parent[0]=-1;
  arr1[w++]=j;
	while(parent[j]!=-1)
		{

			j=parent[j];
			arr1[w++]=j;
			if(sr==1&&j==1)
		       {        w++;
				break;
		       }
		}

  /* for(int i=0;i<w-1;i++)
   {
      cout<<arr1[i]<<" ";
   }*/
}
// A utility function to print the constructed distance
// array
void printSolution(int dist[], int n, int parent[])
{

	gotoxy(58,7);
	setcolor(RED);
	printf("Distance is %dm.",dist[des]);
	printPath(parent, des);
}

// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V];  // The output array. dist[i] will hold
		  // the shortest distance from src to i

    // sptSet[i] will true if vertex i is included / in shortest
    // path tree or shortest distance from src to i is finalized
    int sptSet[V];

    // Parent array to store shortest path tree
    int parent[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
	parent[0] = -1;
	dist[i] = INT_MAX;
	sptSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
	// Pick the minimum distance vertex from the set of
	// vertices not yet processed. u is always equal to src
	// in first iteration.
	int u = minDistance(dist, sptSet);

	// Mark the picked vertex as processed
	sptSet[u] = 1;

	// Update dist value of the adjacent vertices of the
	// picked vertex.
	for (int v = 0; v < V; v++)

	    // Update dist[v] only if is not in sptSet, there is
	    // an edge from u to v, and total weight of path from
	    // src to v through u is smaller than current value of
	    // dist[v]
	    if (!sptSet[v] && graph[u][v] &&
		dist[u] + graph[u][v] < dist[v])
	    {
		parent[v]  = u;
		dist[v] = dist[u] + graph[u][v];
	    }
    }

    // print the constructed distance array
    printSolution(dist, V, parent);
}
void swap()
{
 if(des<sr)
    {
      int temp=sr;
      sr=des;
      des=temp;
    }

}
void input()
{   int temp2;
    outtextxy(450,20,"Enter the source");
    gotoxy(65,3);
    cin>>sr;

    outtextxy(450,50,"Enter the destination");
    gotoxy(65,5);
    cin>>des;
    swap();
 }

void getcoord(struct node*temp , int d)
{ struct node*p=temp;
    while(p!=NULL)
    {
	if(p->id==d)
	{
	    k=p->x;
	    l=p->y;
	}
	p=p->link;
    }
}
void highlight()
{
	int a=0;
	int b=0;
	getcoord(head,sr);
	setcolor(RED);
	a=k;
	b=l;
	setfillstyle(SOLID_FILL,RED);
	circle(k,l,3);
	floodfill(k,l,RED);

    for(int i=w-2;i>=0;i--)
    {
	getcoord(head,arr1[i]);
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(k,l,3);
	floodfill(k,l,RED);
	line(a,b,k,l);
	a=k;
	b=l;
    }
}

void main()
{label:

 w=0; u=0;
 for(int i=0;i<V;i++)
 arr1[i]=0;

int gd=DETECT, gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    struct node* temp;
      insert(10,0,0);
    insert(110,0,1);
    insert(260,0,2);
    insert(360,0,3);
    insert(460,0,4);
    insert(560,0,5);
    insert(560,430,6);
    insert(410,430,9);
    insert(310,430,10);
    insert(210,430,11);
    insert(110,430,12);
    insert(10,430,13);
    insert(10,130,14);
    insert(110,130,15);
    insert(210,130,16);
    insert(260,130,17);
    insert(360,130,18);
    insert(460,130,19);
    insert(460,230,20);
    insert(460,330,21);
    insert(210,330,22);
    insert(210,230,23);
    insert(110,330,24);
    insert(560,230,25);
    insert(560,330,26);




    traverse();
    join();
  //  colouring();
    text();
    matrix();
    input();
   dijkstra(arr, sr);
    highlight();
    getch();
    cleardevice();
    char ch;
    outtextxy(10,10,"Enter y to enter any other location : ");
    gotoxy(5,3);
    cin>>ch;
    if(ch=='y')
    goto label;
   getch();
}
