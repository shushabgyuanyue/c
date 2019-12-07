#include<stdio.h>
#include<conio.h>
#include<windows.h> 
#include<time.h>
#define HO  37
#define LC  79
#define C   9
#define D   10 
#define T   30
struct sign
{
	int x;
	int y;
}s[702],man1={82,38},man2={82,37}; 
int h,l,exit1,exit2;
int road[HO][LC];
int random();
void autoshow();
void gotoxy(int x,int y);//移动光标  
void ycgb(int k);//隐藏光标
void c(int k);//颜色 
void exit();//出口 
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
void c(int k)//改变颜色输出  
{  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);  
} 
void exit()
{
	int i,j,c1,c2;
	c1=random()%34+1;
	c2=random()%76+1;
	switch(random()%4+1)
	{
		case 1:if(road[c1][1]==0)
		       {
		       	    road[c1][0]=0;
		       	    exit1=c1;
		       	    exit2=0;
			   }else
			   {
			   	    road[c1+1][0]=0;
			   	    exit1=c1+1;
		       	    exit2=0;
			   }
			   break;
	   case 2: if(road[1][c2]==0)
		       {
		       	    road[0][c2]=0;
		       	    exit1=0;
		       	    exit2=c2;
			   }else
			   {
			   	    road[0][c2+1]=0;
			   	    exit1=0;
		       	    exit2=c2+1;
			   }
			   break;
		case 3: if(road[c1][77]==0)
		       {
		       	    road[c1][78]=0;
		       	    exit1=c1;
		       	    exit2=78;
			   }else
			   {
			   	    road[c1+1][78]=0;
			   	    exit1=c1+1;
		       	    exit2=78;
			   }
			   break;
		case 4: if(road[35][c2]==0)
		       {
		       	    road[36][c2]=0;
		       	    exit1=36;
		       	    exit2=c2;
			   }else
			   {
			   	    road[36][c2+1]=0;
			   	    exit1=36;
		       	    exit2=c2+1;
			   }
			   break;	   
	}
	gotoxy(4,2);
	c(3);
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
void autoshow()
{
    system("title 迷宫.寻");
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
	exit();
}
void game()
{
	 int c1,c2,c3,c4,i,j,ch,t1,t2;
	 gotoxy(man2.x,man2.y);
 	 c(D);
     printf("♀");
 	 gotoxy(man1.x,man1.y);
 	 c(C);
     printf("♂");
	 road[37][39]=1;
	 t1=time(NULL); 
	 while(1)
 	{
 		t2=time(NULL);
 		if(t2-t1>T)
 		{
 			road[exit1][exit2]=1;
 			exit();
 			gotoxy(man1.x,man1.y);
 			c(C);
 			printf("♂");
 			gotoxy(man2.x,man2.y);
 			c(D);
 			printf("♀");
			t1=t2;
		 }
 		c1=man1.y-2;
	 	c2=(man1.x-4)/2;
	 	c3=man2.y-2;
	 	c4=(man2.x-4)/2;
 	    if(kbhit())
 	    {
  	        ch=getch();
			if(ch==224)
			{
				gotoxy(man1.x,man1.y);
 		        printf("  ");
			    ch = getch();  
		        if (ch == 72&&road[c1-1][c2]==0)
			    {
			      	man1.y=man1.y-1;
				}
		        if (ch == 80&&road[c1+1][c2]==0) 
		        {
		        	man1.y=man1.y+1;
				}
		        if (ch == 75&&road[c1][c2-1]==0) 
				{
					man1.x=man1.x-2;
				 } 
		        if (ch == 77&&road[c1][c2+1]==0) 
		        {
		            man1.x=man1.x+2;
				}
			    gotoxy(man1.x,man1.y);
			    c(C);
	            printf("♂");
			} 
			if(ch!=224)
			{
				gotoxy(man2.x,man2.y);
 		        printf("  ");  
		        if (ch==119&&road[c3-1][c4]==0)
			    {
			      	man2.y=man2.y-1;
				}
		        if (ch==115&&road[c3+1][c4]==0) 
		        {
		        	man2.y=man2.y+1;
				}
		        if (ch==97&&road[c3][c4-1]==0) 
				{
					man2.x=man2.x-2;
				 } 
		        if (ch==100&&road[c3][c4+1]==0) 
		        {
		            man2.x=man2.x+2;
				}
				    gotoxy(man2.x,man2.y);
			        c(D);
	                printf("♀");
	                gotoxy(man1.x,man1.y);
	                c(C);
	                 printf("♂");
			   
			} 	
		}
		if(man1.x==160||man1.x==4||man1.y==2||(man1.y==38&&man1.x!=82))
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
			gotoxy(80,40); 
			c(3);
			printf("恭喜！♂走出了迷宫！");
			system("pause");
			break;
		}
		if(man2.x==160||man2.x==4||man2.y==2||(man2.y==38&&man2.x!=82))
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
			gotoxy(80,40); 
			c(3);
			printf("恭喜！♀走出了迷宫！");
			system("pause");
			break;
		}	
	}
}

