#include<stdio.h>
#include<malloc.h>
struct stu
{
	int num;
	float score;
	struct stu *next;
 };
 struct game
{
	 num();
	struct game *next;
};
 struct stu *creat();//建立链表 
 struct stu* print(struct stu*p);//打印链表 
 struct stu*find(struct stu*p);//查询链表
 struct stu*sort(struct stu*p);//成绩排序
 struct stu*cut(struct stu*p);//删除链表 
 struct stu *add(struct stu*p);//增加链表
 void menu();//菜单 及用户操作 
 void files(struct stu *p);//文件保存
 void file_p(struct stu*p);//文件打开 
 //void game1(); //死亡游戏 
 int n;
 int main()
 {	
    menu();
	return 0;
 }
 struct stu *creat()
 {
 	printf("如果您学号输入0,则录入结束\n");
 	struct stu *n1,*n2,*head;
 	n=0; head=NULL;
 	n1=n2=(struct stu*)malloc(sizeof(struct stu));
 	printf("please enter number:");
 	scanf("%d",&n1->num );
 	printf("please enter score:");
 	scanf("%f",&n1->score);
 	printf("\n\n");
 	while(n1->num)
 	{
 		n++;
 		if(n==1)
 		{
 			head=n1;
		 }else
		 {
		 	n2=n1;
		 }
		 n1=(struct stu*)malloc(sizeof(struct stu));
		 n2->next=n1;
		 printf("please enter number:");
 	     scanf("%d",&n1->num );
       	 printf("please enter score:");
 	     scanf("%f",&n1->score);
 	     printf("\n\n");
	 }
	 n2->next =NULL;
	 return head;
 }
 struct stu* print(struct stu*p)
 {
 	struct stu*head;
 	head=p;
 	n=0;
 	printf("结果如下\n\n");
 	while(p)
 	{
         printf("学号为%d的学生成绩是%f\n",p->num,p->score);
		 p=p->next;
		 n++;		
    }
	 printf("\n\n");
	 return head;
 }
struct stu* find(struct stu*p)
{
	int a,k=0;
	struct stu*head,*i;
	i=head=p;
	printf("放弃查询请输入0，查询则输入他的学号：");
	scanf("%d",&a);
	while(a!=0)
	{
		if(k!=0)
        {
		    printf("结束查询请输入0，继续查询则输入他的学号：");
	        scanf("%d",&a);
     	}
	        if(a==0)
	        {
	        	goto end1;
			}else
            {
        	    if(a==p->num)
                {
        	       goto print;
		        }else
		        {
			        while(a!=p->num)//找出查找序号 
	                {
	        	        if(p->next)
	        	        {
			               p=p->next;
		                }else
		                {
			               printf("没有这个学生\n退出则输入0，否则请重新输入:");//防止错误 
			               scanf("%d",&a);
			               if(a==0)
					       {
					   	       goto end1;
						   } 
			               p=head;
		                }  
                    }
	    	    }
		    }
        
            print: printf("学号为%d的学生成绩是%f!\n",p->num,p->score);
            k++;
            p=head;
        }
        end1:printf("");
        return i;
    }
struct stu*sort(struct stu*p)
{
	printf("成绩由高到低如下:\n");
	struct stu *i,*q;
	int a;
	float b;
	q=p;
	while(p)
	{
	    i=p->next; 
	    while(i)
	    {    
		    if(i->score>p->score)//交换值 
	  	    {
			    b=i->score;
			    i->score=p->score;
			    p->score=b;
			    a=i->num;
			    i->num=p->num;
			    p->num=a;
		    }
		    i=i->next;
        }
        p=p->next;
    } 
    print(q);
    return q;
}	
struct stu*cut(struct stu*p)
{
	int a,m=0,k;
	struct stu *i,*j,*head;
	head=i=j=p;
	printf("放弃操作请输入0，继续则输入您想删除的学号：");
	scanf("%d",&a);
	printf("\n");
	if(a==0)
	{
		goto end4;
	}else
	 {
	cut:while(a!=0)//循环为了多次删除 
	 	{
	 	if(a==p->num)
	       {
		     p=p->next;
		    head=p;
	       }else
	       {  
	 	        while(p->num!=a)//查找链表序号 
               	{
		            if(p->next)
		            {
		            	p=p->next;
	             	}else
		            {
		            	p=head;
		            	if(a!=p->num)
		            	{
		                 	m=-1;
			                printf("对不起没有这个学生，若放弃请输入0，继续则请重新输入: ");//防错 
			                scanf("%d",&a);
			            }
			            if(a==p->num)
			            {
			            	goto cut;
						}
			            if(a==0)
						{
							goto end4;
						 } 
		            }
		            m++;
                }
                i=j=p=head;//是p重新指向表头 
                for(k=0;k<m-1;k++)
                {
                	j=j->next;
				}
				for(k=0;k<m+1;k++)
				{
					i=i->next;
				}
				m=0;
				j->next=i;
				i=j=head;    
	        } 
	 	    printf("放弃操作请输入0，继续则输入您想删除的学号：");
	        scanf("%d",&a);
	         printf("\n");	
		}
	    end4:print(head);
	     return head;
	}
	
	while(a<=0)
	{
		printf("没有这个学生，请重新输入：");
		scanf("%d",&a);
		printf("\n"); 
	}
	
 }
 struct stu* add(struct stu*p) 
 {
 	int a,c;
 	struct stu *i,*j,*head;
 	head=p;
 	printf("放弃增加信息则学号输入0，继续则输入不为0的学号：\n"); 
 	i=(struct stu*)malloc(sizeof(struct stu));
	scanf("%d",&i->num);
	if(i->num==0)
	{
		goto end3;
	 } else
	  {
	      while(i->num!=0)//循环为了多次添加链表 
          {  
	            printf("请输入成绩:");
	            scanf("%f",&i->score);
	            printf("如果您想把该学生加在开头则输入c=0,如果不是请输入c=1\nc=");//是否加在链表头 
	            scanf("%d",&c);
	            if(c==0)
	            {
		             i->next=p;
		             head=i;
		             p=i;
	            }else
	            {
	                 printf("请您选择加在哪个学生的后面，请输入他的学号：");
                     scanf("%d",&a);
                     while(p->num!=a)//寻找链表序号 
	                 {
		                  if(p->next)
		                  {
			                  p=p->next;
		                  }else
		                  {
			                    printf("对不起没有这个学生，放弃输入0，继续则重新输入: ");//防错 
		                     	scanf("%d",&a);
			                    if(a==0)
			                    {
				                    goto end3;
			                    } 
			                    p=head;
		                  }
	               }
	               j=p->next;
	               p->next=i;
	               i->next=j;
                } 
	            printf("放弃增加信息则学号输入0，继续则输入不为0的学号：\n"); 
 	            i=(struct stu*)malloc(sizeof(struct stu));
 	            scanf("%d",&i->num);
            }
	         end3:print(head);
        }
        return head;
   }
 void menu()
 {
 	int i,h,k=0;
 	struct stu*j;
 	printf("欢迎进入这个bug很多的系统！\n\n");//用户指南 
 	printf("若想录入信息请输入1\n\n若想显示已录入信息请输入2\n\n若想修改（删除）某个学生的信息并显示请输入3\n\n");
 	printf("若想修改（增加）信息并显示请输入4\n\n若想查询某一个学生的成绩请输入5\n\n若想成绩排序请输入6（由大到小）\n\n登出系统请输入0\n\n");
    printf("请选择您需要的操作：");
 	scanf("%d",&i);
 	while(i!=0)
 	{
 		if(k==0 && i!=1)
		 {
 			while(i!=1)
 			{
 				printf("请先录入信息选择1录入信息才能进入下面的操作：");
				 scanf("%d",&i); 
				 if(i==0)
				 goto end;//跳出循环 
			 }
		 }switch(i)
		{
	        case 1:j=creat();break;//有返回值是因为每次调用不同函数后，链表与操作后的链表相同 
		    case 2:j=print(j);break;
		    case 3:j=cut(j);break;
		    case 4:j=add(j);break;
		    case 5:j=find(j);break;
		    case 6:j=sort(j);break;
	   }
		 printf("继续请输入对应功能数字，登出系统请输入0："); 
		 scanf("%d",&i); 
	     printf("\n");
		 k++;
	 }
	end: printf("恭喜您退出了这个满是bug的系统！\n\n");
	     files(j);
	     printf("您的信息保以保存，若需要打开文件请输入1，放弃则输入0：");
	     scanf("%d",&h);
		 if(h==1)
		 {
		 	file_p(j);
		  } 
		 printf("操作结束，谢谢您的使用!"); 
		  
  } 
 
 void files(struct stu*p)
 {
 	
 	char fname[30];
 	FILE *i;
 	int a;
 	printf("请您输入数据保存的文件名及地址：");
	scanf("%s",&fname); 
	if(!(i=fopen(fname,"w+")))
	{
		printf("已为您创建了%s文件\n\n",fname);
	}else
	{
		printf("文件创建成功，您的信息将保存到文件%s中\n\n",fname);
	} 
	for(a=0;a<n;a++)
 	{
 		fwrite(p,sizeof(struct stu),1,i);
 		p=p->next;
	 }
	 fclose(i);
  } 
  void file_p(struct stu*p)
 {
 	
 	char fname[30];
 	FILE *i;
 	int a;
 	printf("请您输入需要打开的文件名及地址：");
	scanf("%s",&fname); 
	if(!(i=fopen(fname,"r+")))
	{
		printf("对不起没有这个文件，但已为您创建了%s文件\n\n",fname);
	}else
	{
		printf("文件%s打开成功：\n\n",fname);
	} 
	printf("\t\t学生学号\t学生成绩\n");
	for(a=0;a<n;a++)
 	{
 		fread(p,sizeof(struct stu),1,i);
 		printf("\t\t%d\t\t%f\n",p->num,p->score);
 		p->next=p;
	 }
	 fclose(i);
  } 
 /*void game1()
{
	int k,m,c,b;
	printf("please enter the number of the people:");
	scanf("%d",&m);
	struct game*a,*j,*head,*i;
	a=j=(struct game*)malloc(sizeof(struct game));
	head=NULL;
	for(n=0;n<m;n++)
	{
		if(n==0)
		{
		    head=a;
			head->num=n+1;
		}else
		{
			j=a;
			j->num=n+1;
		}
		a=(struct game*)malloc(sizeof(struct game));
		j->next=a;
    }
	j->next=head;
	i=a=j=head;
	puts("参与人的编号为："); 
	for(n=0;n<m;n++)
	{
		printf("%d\t",head->num);
		head=head->next;
	}
	printf("\n\n");
    printf("please enter the number of the out:");
	scanf("%d",&k);
	for(c=0;c<m-1;c++)
	{
		
		if(k==1)
		{
			printf("淘汰的选手是%d\n",a->num);
			a=a->next;
            			
		}else
		{
		    for(b=0;b<k-1;b++)	
	    	{
		    	i=i->next;
	    	}
			for(n=0;n<k;n++)
			{
				a=a->next;
			}
			n=0;
			while(k-n>2)
			{
				j=j->next;
				n++;
			}
		    j->next=a;
		    printf("本局淘汰的选手是%d\n",i->num);
		    i=a;
		    j=i;
		}
	}
	printf("最终获胜的选手是%d",a->num);
} */
