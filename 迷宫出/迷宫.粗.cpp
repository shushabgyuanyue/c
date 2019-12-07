#include<stdio.h>
#include<conio.h>
#include<windows.h> 
#include<time.h>
#define HO  37
#define LC  79
struct sign
{
	int x;
	int y;
}s[702]; 
struct pepole
{
	int x;
	int y;
	int direction;
}man={82,38,2 };
int h,l;
int road[HO][LC];
int random();
void autoshow();
void gotoxy(int x,int y);//移动光标  
void ycgb(int k);//隐藏光标  
int n;
void game();
int main()
{
	ycgb(0);
	autoshow();
	game();
	return 0;
}
void gotoxy(int x,int y) //移动光标  
{  
    COORD coord;  
    coord.X=x;  
    coord.Y=y;  
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );  
} 
void ycgb(int k)//隐藏光标  
{  
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
    CONSOLE_CURSOR_INFO cci;  
    GetConsoleCursorInfo(hOut,&cci);  
    cci.bVisible=k;//赋1为显示，赋0为隐藏  
    SetConsoleCursorInfo(hOut,&cci);  
} 
int random()
{
	srand(rand()+time(NULL));
	return rand();
}
void autoshow()
{
	int c1,c2;
    system("title 迷宫");
	system ("mode con cols=200 lines=44");
	gotoxy(4,2);
	int i,j,l,k=0;
	for(i=0;i<HO;i++)
	{
		for(j=0;j<LC;j++)
		{
			road[i][j]=1;
		}
	}
	road[35][39]=0;
	road[34][39]=0;
	road[36][39]=0;
	h=33;
	l=39;
	road[h][l]=0;
	s[k].x=h;
	s[k].y=l;
	k++;
	i=0;
	while(i<k)
    {
	    while((road[h-2][l]==1&&h-2>0)||(road[h][l-2]==1&&l-2>0)||(road[h][l+2]==1&&l+2<78)||(road[h+2][l]==1&&h+2<36)) 
		{
		   j=random()%4+1;
		   switch(j)
	       {
	    	case 1:
	    		if(road[h-2][l]==1&&h-2>0)
	    		{
	    			road[h-2][l]=0;
	    			s[k].x=h-2;
	    			s[k].y=l;
	    			road[h-1][l]=0;
		    		h=h-2;    
				    k++;
				}
				break;
	    	case 2:
			    if(road[h][l-2]==1&&l-2>0)
	    		{
	    			road[h][l-2]=0;
	    			s[k].x=h;
	    			s[k].y=l-2;
	    			road[h][l-1]=0;
			        l=l-2;
			        k++;
				}
				break;
	    	case 3:
				if(road[h][l+2]==1&&l+2<78)
	    		{
	    			road[h][l+2]=0;
	    			s[k].x=h;
	    			s[k].y=l+2;
	    			road[h][l+1]=0;
			        l=l+2;
			        k++;
				} 
				break;
	    	case 4:
				if(road[h+2][l]==1&&h+2<36)
	    		{
	    			road[h+2][l]=0;
	    			s[k].x=h+2;
	    			s[k].y=l;
	    			road[h+1][l]=0;
	    			h=h+2;
			        k++;
				}
				break;	
		    }   
		}
		if((road[s[i].x-2][s[i].y]==1&&s[i].x-2>0)||(road[s[i].x][s[i].y-2]==1&&s[i].y-2>0)||(road[s[i].x][s[i].y+2]==1&&s[i].y+2<78)||(road[s[i].x+2][s[i].y]==1&&s[i].x+2<36)) 
		{
			h=s[i].x;
		    l=s[i].y;
		}else
		{
		    i++;
			h=s[i].x;
		    l=s[i].y;	
		}	 
	}
	c1=random()%34+1;
	c2=random()%76+1;
	switch(random()%4+1)
	{
		case 1:if(road[c1][1]==0)
		       {
		       	    road[c1][0]=0;
			   }else
			   {
			   	    road[c1+1][0]=0;
			   }
			   break;
	   case 2: if(road[1][c2]==0)
		       {
		       	    road[0][c2]=0;
			   }else
			   {
			   	    road[0][c2+1]=0;
			   }
			   break;
		case 3: if(road[c1][77]==0)
		       {
		       	    road[c1][78]=0;
			   }else
			   {
			   	    road[c1+1][78]=0;
			   }
			   break;
		case 4: if(road[35][c2]==0)
		       {
		       	    road[36][c2]=0;
			   }else
			   {
			   	    road[36][c2+1]=0;
			   }
			   break;	   
	}	
   for(i=0;i<HO;i++)
	{
		for(j=0;j<LC;j++)
		{
			if(road[i][j]==1)
			{
				printf("■");
			}else
			printf("  "); 
		}
		gotoxy(4,i+3);
	}
}
void game()
{
	int c1,c2,i,j;
     gotoxy(82,39);
     printf("♂");
	 Sleep(100);
	 gotoxy(82,39);
	 printf("  "); 
 	 gotoxy(man.x,man.y);
     printf("♂");
	 while(1)
 	{
 		Sleep(20);
 		gotoxy(man.x,man.y);
	    printf("  ");
	    c1=man.y-2;
	 	c2=(man.x-4)/2;
	    if(man.direction==1)
	    {
	    	if(road[c1+1][c2]==0)
    	    {
    		    man.direction=4;
    		    goto begain;
		    }else
			{
			   if(road[c1][c2-1]==0)
		    	{
		    		man.direction=1;
				}else
				{ 
				    if(road[c1-1][c2]==0)
		    	    {
		    		    man.direction=2;
		    		    goto begain;
				    }else
					{ 
				       	if(road[c1][c2+1]==0)
		    	        {
				    		man.direction=3;
				    		goto begain;
					    }
					}
			   }
			}
	   }
    	if(man.direction==2)
	    {
	    	if(road[c1][c2-1]==0)
    	    {
    		    man.direction=1;
		    }else
			{
			   if(road[c1-1][c2]==0)
		    	{
		    		man.direction=2;
				}else
				{ 
				    if(road[c1][c2+1]==0)
		    	    {
		    		    man.direction=3;
		    		    goto begain;
				    }else
					{ 
				       	if(road[c1+1][c2]==0)
		    	        {
				    		man.direction=4;
				    		goto begain;
					    }
					}
			   }
			}
	   }
    	if(man.direction==3)
	    {
	    	if(road[c1-1][c2]==0)
    	    {
    		    man.direction=2;
		    }else
			{
			   if(road[c1][c2+1]==0)
		    	{
		    		man.direction=3;
				}else
				{ 
				    if(road[c1+1][c2]==0)
		    	    {
		    		    man.direction=4;
		    		    goto begain;
				    }else
					{ 
				       	if(road[c1][c2-1]==0)
		    	        {
				    		man.direction=1;
					    }
					}
			   }
			}
	   }
		if(man.direction==4)
	    {
	    	if(road[c1][c2+1]==0)
		    {
			    man.direction=3;
		    }else
			{
			   if(road[c1+1][c2]==0)
		    	{
		    		man.direction=4;
				}else
				{ 
				    if(road[c1][c2-1]==0)
		    	    {
		    		    man.direction=1;
				    }else
					{ 
				       	if(road[c1-1][c2]==0)
		    	        {
				    		man.direction=2;
					    }
					}
			   }
			}
	   }
	   
	   	begain:switch(man.direction)
	 	{
	 		case 1:man.x=man.x-2;break;
	 		case 2:man.y=man.y-1;break;
	 		case 3:man.x=man.x+2;break;
	 		case 4:man.y=man.y+1;break;
		}
		gotoxy(man.x,man.y);
	    printf("♂");
		n++;
		if(man.x==160||man.x==4||man.y==2||man.y==38)
		{
			gotoxy(6,3);
			for(i=0;i<HO-2;i++)
	        {
				for(j=0;j<LC-2;j++)
				{
					 printf("  "); 
				}
				gotoxy(6,i+4);
			   }
			gotoxy(80,25); 
			printf("恭喜！走出了迷宫！\n\t\t\t\t\t\t\t\t\t共走了%d步",n);
			system("pause");
			break;
		}	
	}
}

