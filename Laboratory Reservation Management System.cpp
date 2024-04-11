#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include <string.h>//定义字符数组
#include <math.h>
#include<memory.h> 
#define LEN sizeof(struct land)//有关登录系统的结构体

struct Tland//老师登录信息
{
	int zhanghao;//账号 
	char password[20];//密码 
	struct Tland*next;
};

struct land//学生登录信息
{
	int zhanghao;	//账号 
	char password[20];	//密码 
	struct land*next;
};

typedef struct QNode//有关学生信息的结构体 
{ 
  char name[10];//名字 
   char banji[10];//班级 
  int  number;//班级 
  struct QNode*next;
}student;

typedef struct//有关时间点的结构体 
{
 QNode *front;
 QNode *rear;
}linkqueue;

void lmenu();      //显示学生登录菜单函数 
void main1();      // 学生端实验室预约界面函数 
void land();      //学生登录功能系统函数 
int xinjian(int,char[]);   //学生创建账号密码函数 
void xgmm();           //学生修改密码函数 
void lmain();      //学生登录界面函数
void Tlmenu();    //教师端显示登录菜单函数 
void main2();    // 教师端实验室预约界面函数 
void Tland();    //教师端登录功能系统函数 
int Txinjian(int,char[] );    //教师端创建账号密码函数 
void Txgmm();    //教师端修改密码函数 
void Tlmain();    //教师端登录界面函数
void shenfen();   //选择身份函数 

int Ttj()
//统计老师账号密码文本个数
{
FILE *fp;
//文件指针 
int zhao=0, n;
char mm[20]={'\0'};
fp=fopen("Tland.txt","r");
//打开文件
for (n=0;!feof(fp);n++)
//逐个读文件
fscanf(fp,"%d %s",&zhao,mm);
n--;
fclose(fp);
//关闭文件
return (n);
//返回个数
}

void Tlmenu()
//显示教师端登录菜单函数 
{
printf("\n\n\t欢迎使用教师端实验室预约登录系统\n\n");
printf("**********************************************\n");
printf("**********************************************\n");
printf("\n\n\t\t1.登录系统\n\n");
printf("\n\n\t\t2.创建账号\n\n");
printf("\n\n\t\t3.修改密码\n\n");
printf("\n\n\t\t4.退出登录系统\n\n");
printf("\n\n\t    请按键选择，回车确定\n");
printf("**********************************************\n");
printf("**********************************************\n");
printf("\n\t\t请选择（1-4）"); 
return ;
}  

void Tlmain()
//登录功能函数
{
	void Tland();
	//登录功能系统函数 
	void Txinjian();
	//新建账号密码函数 
	char choose;
	Tlmenu();
	scanf(" %c",&choose);
	switch(choose) 
	//功能函数
  {
	  case'1':
	    Tland();
	    break;
	  case'2':
	  	Txinjian();
	  	break;
	  	case'3':
	  	Txgmm();
	  	break;
	  case'4':
	  	system("cls");
	  	//清屏函数 
    getch();
  	exit(0);
  	//正常退出 
  	system ("cls");
	break;
  }
}

void Txinjian()
//新建账户密码函数 
{
	FILE *fp;
	int zhanghao;
	//账号 
	char password[20];
	//密码 
	char password1[20];
	//二次确认密码 
	char hit=0;
	if ((fp=fopen("Tland.txt","r"))==NULL)
	//打开文件只读 
	{
      fp=fopen("Tland.txt","w");
      //建立新的文件，只允许写入数据 
      fclose(fp);
      //关闭文件 
    }
    system("cls");
    //清屏函数 
	fp=fopen("Tland.txt","a");
	//打开"land"文件，并且在文件末尾写入数据 
	for(;;)
	//输入两次密码确认，两次相同才能确认
	{
	   printf("\n请按以下格式输入账户:\n学号 密码\n");
	   printf("请输入:");
	   scanf("%d %s",&zhanghao,password);
       printf("再次输入密码:\n");
	   scanf("%s",password1);
	   if(strcmp(password,password1)==0)
	   //比较输入的两个密码是否一致 
	   {
	       fprintf(fp,"%d %s\n",zhanghao,password);
	       //将数据写入文件 
		   break;
       }
       else
	   {
	     printf("\n\t\t***************************************************");
         printf("\n\t\t***************************************************"); 
         printf("\n\t\t***两次输入密码不一致，继续创建按回车，退出按ESC***");
         printf("\n\t\t***************************************************");
         printf("\n\t\t***************************************************");
	       hit=getch();
		   if(hit=27)
		   //如果按ESC键 
		   system("cls");
		   //清屏函数 
		   Tlmain();
	   }
   }
   fclose(fp);
   //关闭文件 
         printf("\n\t\t****************************");
         printf("\n\t\t****************************"); 
         printf("\n\t\t***创建成功，按任意键返回***");
         printf("\n\t\t****************************");
         printf("\n\t\t****************************");
         getch();
         system("cls");
         Tlmain();
}

int Tmatch(int m,char a[20])
//匹配数据库中的账号密码函数 
{
	FILE*fp;
	//文件指针 
	int n=0,i=0,zhanghao;
	char password[20];
	if ((fp=fopen("Tland.txt","r"))==NULL)
	//不存在老师信息文件
	  {
         system ("cls");
		 printf("\n ");
		 printf("\n\t\t*****************************");
         printf("\n\t\t*****************************"); 
         printf("\n\t\t***还未存在用户!请新建账户***");
         printf("\n\t\t*****************************");
         printf("\n\t\t*****************************");
		 getch();
	 	system("cls");
		Tlmain();
      }
        for(;!feof(fp);)
      {
        fscanf(fp,"%d%s",&zhanghao,password);
        //从文件读数据 
        if(m==zhanghao)
        {
        	if(strcmp(a,password)==0)
        	//比较密码是否相同 
			return 1;
			else
			{
			return -1;
		   }
	    }
	  }
	  return 0;
 }

void Tland()
//输入账户密码的登录函数
{
	int zhanghao;
	char password[20];
	int i=2, j, k, n;
	char hit=0;
	system("cls");
	do
	{
	   printf("\n请输入账号:\n");
       scanf("%d",&zhanghao);
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
         printf("\n\t\t***确认输入请按回车，重新输入请按ECS***");
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
       hit=getch();
	   //暂停程序当i接收后继续下一条指令
       for (;hit!=13&&hit!=27;)
	   //保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
       {
	        hit=getch();
	   }
    }
    while(hit==27);
	 printf("\n请输入密码:\n");
	 scanf("%s",password);
     i=Tmatch(zhanghao,password);
     //调用"match"函数是否账号和密码是否相关联 
     if(i==1)
	 {
         printf("\n\t\t***************************");
         printf("\n\t\t***************************");
         printf("\n\t\t***登陆成功!按任意键继续***");
         printf("\n\t\t***************************");
         printf("\n\t\t***************************");
	   getch();
	   system ("cls");
	   //清屏函数 
	   main1();
	   Tlmain();
	 }
	 else
	 {
	 	if(i==-1)
		 {
		 printf("\n\t\t************************");
         printf("\n\t\t************************"); 
         printf("\n\t\t***不好意思，密码错误***");
         printf("\n\t\t************************");
         printf("\n\t\t************************");
		 getch();
         Tland();
		 }
		 if(i==0)
		 printf("\n\t\t****************************************");
         printf("\n\t\t****************************************"); 
         printf("\n\t\t***不存在此用户，确认账号密码再来登陆***");
         printf("\n\t\t****************************************");
         printf("\n\t\t****************************************\n\n\n");
		 getch();
		 system("cls");
		 Tlmain();
	 }
}

void Txg(int z,char m[20])
//修改函数
{
	FILE *fp;
	//文件指针 
	int zhanghao1,n,j,k;
	char mima1[20];
	struct land *head,*p,*p1,*p2;
	 fp=fopen("Tland.txt","r");
	 //打开文件只读 
	   j =Ttj();
	   for (k=0;k<=j;k++)
       {
	       fscanf(fp,"%d %s",&zhanghao1,mima1);
	       //在文件里读账号和密码 
           if (z!=zhanghao1)
		   //比较名字，将不同名字的信息复制到链表
          {
	            n++;
				//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的学生信息建立成链表
	            if (n==1)
				//建立链表
                {
		          p1=p2=(struct land*)malloc(LEN);
		          //分配空间 
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct land*)malloc(LEN);
				  //新建链表
                }
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);
				//复制账号密码
          }
       }
        if (n==0)
			 {
			 head=NULL;
			 }
			 else
			 //建立链表的最后剩余一个储存空间，所以封底
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 //关闭文件 
			 }
			  fp=fopen("Tland.txt","w");
			  //清空文件，只写打开，然后关闭
              fclose(fp);
              fp=fopen("Tland.txt","a");
			  //追加文件
              p=head;
            for (;p!=NULL;)
			//把链表内容覆盖到文件
   			{
   	   		 	fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   		 	//写入数据到文件 
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s\n",z,m);
            fclose(fp);
            //关闭文件 
         printf("\n\t\t******************");
         printf("\n\t\t******************"); 
         printf("\n\t\t***修改密码成功***");
         printf("\n\t\t******************");
         printf("\n\t\t******************");
            

}

   void Txgmm()
   //修改密码函数 
{

	   FILE *fp;
	   //文件指针 
       int zh=0,k=0,many=0;
	   int m=0,n=0, chazhao;
	   int hit;
       char mima[20]={'\0'};
	   char password1[20]={'\0'};
       char  mm[20]={'\0'};
       char i;
       if ((fp=fopen("Tland.txt","r"))==NULL)
	   //打开文件
       {
	       system ("cls");
         printf("\n\t\t*********************************");
         printf("\n\t\t*********************************"); 
         printf("\n\t\t***记录文件不存在!按任意键返回***");
         printf("\n\t\t*********************************");
         printf("\n\t\t*********************************");
  		   getch();
  		   system("cls");
		   Tlmain();
       }
	   system("cls");
       printf("请输入你的帐号和旧密码：\n");
       scanf("%d %s",&chazhao,mima);
	   m =Ttj();
	   for (n=0;n<=m;n++)
	   {
	    fscanf(fp,"%d %s",&zh,mm);
        if(zh==chazhao)
        {
        	if(!strcmp(mm,mima))
        	//比较两个密码 
        	{
        		printf("请输入新的密码");
        		scanf("%s",mima);
       		    printf("再次输入密码:\n");
	            scanf("%s",password1);
	             if(strcmp(mima,password1)==0)
	            //比较两个密码 
	   			 {
		             Txg(chazhao,mima);
		            getch();
				    Tlmain();
	                system("cls");
   			     }
       			  else
	   			  {
	     printf("\n\t\t*************************************");
         printf("\n\t\t*************************************"); 
         printf("\n\t\t***两次输入密码不一致,按任意键退出***");
         printf("\n\t\t*************************************");
         printf("\n\t\t*************************************");
	       			  hit=getch();
		   			  system("cls");
				      Tlmain();
   				  }
			}
			else
			{
		 printf("\n\t\t******************************");
         printf("\n\t\t******************************"); 
         printf("\n\t\t***旧密码错误，按任意键返回***");
         printf("\n\t\t******************************");
         printf("\n\t\t******************************");
				getch();
				system("cls");
				Tlmain();
		}
        }
      }
	     printf("\n\t\t********************************");
         printf("\n\t\t********************************"); 
         printf("\n\t\t***不存在此账号，按任意键返回***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
		fclose(fp);
		//修改结束
		getch();
		system("cls");
		Tlmain();
}

int tj()
//统计账号密码文本个数
{
FILE *fp;
//文件指针 
int zhao=0; 
int n;
char mm[20]={'\0'};
fp=fopen("land.txt","r");
//打开文件
for (n=0;!feof(fp);n++)
//逐个读文件
fscanf(fp,"%d %s",&zhao,mm);
n--;
fclose(fp);
//关闭文件
return (n);
//返回个数
}

void lmenu()
//显示登录菜单函数 
{
printf("\n\n\t欢迎使用学生实验室预约登录系统\n\n");
printf("**********************************************\n");
printf("**********************************************\n");
printf("\n\n\t\t1.登录系统\n\n");
printf("\n\n\t\t2.创建账号\n\n");
printf("\n\n\t\t3.修改密码\n\n");
printf("\n\n\t\t4.退出登录系统\n\n");
printf("\n\n\t    请按键选择，回车确定\n");
printf("**********************************************\n");
printf("**********************************************\n");
printf("\n\t\t请选择（1-4）"); 
return ;
}  

void lmain()
//登录功能函数
{
	void land();
	//登录功能系统函数 
	void xinjian();
	//新建账号密码函数 
	char choose;
	lmenu();
	scanf(" %c",&choose);
	switch(choose) 
	//功能函数
  {
	  case'1':
	    land();
	    break;
	  case'2':
	  	xinjian();
	  	break;
	  	case'3':
	  	xgmm();
	  	break;
	  case'4':
	  	system("cls");
	  	//清屏函数 
    getch();
  	exit(0);
  	//正常退出 
  	system ("cls");
	break;
  }
}


void xinjian()
//新建账户密码函数 
{
	FILE *fp;
	int zhanghao;
	//账号 
	char password[20];
	//密码 
	char password1[20];
	//二次确认密码 
	char hit=0;
	if ((fp=fopen("land.txt","r"))==NULL)
	//打开文件只读 
	{
      fp=fopen("land.txt","w");
      //建立新的文件，只允许写入数据 
      fclose(fp);
      //关闭文件 
    }
    system("cls");
    //清屏函数 
	fp=fopen("land.txt","a");
	//打开"land"文件，并且在文件末尾写入数据 
	for(;;)
	//输入两次密码确认，两次相同才能确认
	{
	   printf("\n请按以下格式输入账户:\n学号 密码\n");
	   printf("请输入:");
	   scanf("%d %s",&zhanghao,password);
       printf("再次输入密码:\n");
	   scanf("%s",password1);
	   if(strcmp(password,password1)==0)
	   //比较输入的两个密码是否一致 
	   {
	       fprintf(fp,"%d %s\n",zhanghao,password);
	       //将数据写入文件 
		   break;
       }
       else
	   {
	     printf("\n\t\t***************************************************");
         printf("\n\t\t***************************************************"); 
         printf("\n\t\t***两次输入密码不一致，继续创建按回车，退出按ESC***");
         printf("\n\t\t***************************************************");
         printf("\n\t\t***************************************************");
	       hit=getch();
		   if(hit=27)
		   //如果按ESC键 
		   system("cls");
		   //清屏函数 
		   lmain();
	   }
   }
   fclose(fp);
   //关闭文件 
         printf("\n\t\t****************************");
         printf("\n\t\t****************************"); 
         printf("\n\t\t***创建成功，按任意键返回***");
         printf("\n\t\t****************************");
         printf("\n\t\t****************************");
   getch();
   system("cls");
   lmain();
}

int match(int m,char a[20])
//匹配数据库中的账号密码函数 
{
	FILE*fp;
	//文件指针 
	int n=0;
	int i=0;
	int zhanghao;
	char password[20];
	if ((fp=fopen("land.txt","r"))==NULL)
	//不存在学生信息文件
	  {
         system ("cls");
		 printf("\n ");
		 printf("\n\t\t*****************************");
         printf("\n\t\t*****************************"); 
         printf("\n\t\t***还未存在用户!请新建账户***");
         printf("\n\t\t*****************************");
         printf("\n\t\t*****************************");
		 getch();
	 	 system("cls");
		 lmain();
      }
        for(;!feof(fp);)
      {
        fscanf(fp,"%d%s",&zhanghao,password);
        //从文件读数据 
        if(m==zhanghao)
        {
        	if(strcmp(a,password)==0)
        	//比较密码是否相同 
			return 1;
			else
			{
			return -1;
		   }
	    }
	  }
	  return 0;
 }

void land()
//输入账户密码的登录函数
{
	int zhanghao;
	char password[20];
	int i=2;
	int j;
	int k;
	int n;
	char hit=0;
	system("cls");
	do
	{
	   printf("\n请输入账号:\n");
       scanf("%d",&zhanghao);
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
         printf("\n\t\t***确认输入请按回车，重新输入请按ECS***");
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
       hit=getch();
	   //暂停程序当i接收后继续下一条指令
       for (;hit!=13&&hit!=27;)
	   //保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
       {
	        hit=getch();
	   }
    }
    while(hit==27);
	 printf("\n请输入密码:\n");
	 scanf("%s",password);
     i=match(zhanghao,password);
     //调用"match"函数是否账号和密码是否相关联 
     if(i==1)
	 {
         printf("\n\t\t***************************");
         printf("\n\t\t***************************");
         printf("\n\t\t***登陆成功!按任意键继续***");
         printf("\n\t\t***************************");
         printf("\n\t\t***************************");
	   getch();
	   system ("cls");
	   //清屏函数 
	   main2();
	   lmain();
	 }
	 else
	 {
	 	if(i==-1)
		 {
		 printf("\n\t\t************************");
         printf("\n\t\t************************"); 
         printf("\n\t\t***不好意思，密码错误***");
         printf("\n\t\t************************");
         printf("\n\t\t************************");
		 getch();
         land();
		 }
		 if(i==0)
		 printf("\n\t\t****************************************");
         printf("\n\t\t****************************************"); 
         printf("\n\t\t***不存在此用户，确认账号密码再来登陆***");
         printf("\n\t\t****************************************");
         printf("\n\t\t****************************************\n\n\n");
		 getch();
		 system("cls");
		 lmain();
	 }
}

void xg(int z,char m[20])
//修改函数
{
	FILE *fp;
	//文件指针 
	int zhanghao1;
	int n;
	int j;
	int k;
	char mima1[20];
	struct land *head,
	*p,
	*p1,
	*p2;
	 fp=fopen("land.txt","r");
	 //打开文件只读 
	   j =tj();

	   for (k=0;k<=j;k++)
       {
	       fscanf(fp,"%d %s",&zhanghao1,mima1);
	       //在文件里读账号和密码 
           if (z!=zhanghao1)
		   //比较名字，将不同名字的信息复制到链表
          {
	            n++;
				//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的学生信息建立成链表
	            if (n==1)
				//建立链表
                {
		          p1=p2=(struct land*)malloc(LEN);
		          //分配空间 
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct land*)malloc(LEN);
				  //新建链表
                }
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);
				//复制账号密码
          }
       }
        if (n==0)
			 {
			 head=NULL;
			 }
			 else
			 //建立链表的最后剩余一个储存空间，所以封底
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 //关闭文件 
			 }
			  fp=fopen("land.txt","w");
			  //清空文件，只写打开，然后关闭
              fclose(fp);
              fp=fopen("land.txt","a");
			  //追加文件
              p=head;
            for (;p!=NULL;)
			//把链表内容覆盖到文件
   			{
   	   		 	fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   		 	//写入数据到文件 
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s\n",z,m);
            fclose(fp);
            //关闭文件 
             system ("cls");

}

   void xgmm()
   //修改密码函数 
{
	   FILE *fp;
	   //文件指针 
       int zh=0;
	   int k=0;
	   int many=0;
	   int m=0;
	   int n=0;
       int chazhao;
	   int hit;
       char mima[20]={'\0'};
	   char password1[20]={'\0'};
       char  mm[20]={'\0'};
       char i;

       if ((fp=fopen("land.txt","r"))==NULL)
	   //打开文件
       {
	       system ("cls");
         printf("\n\t\t*********************************");
         printf("\n\t\t*********************************"); 
         printf("\n\t\t***记录文件不存在!按任意键返回***");
         printf("\n\t\t*********************************");
         printf("\n\t\t*********************************");
  		   getch();
  		   system("cls");
		   lmain();
       }
	   system("cls");
       printf("请输入你的帐号和旧密码：\n");
       scanf("%d %s",&chazhao,mima);
	   m =tj();
	   for (n=0;n<=m;n++)
	   {
	    fscanf(fp,"%d %s",&zh,mm);
        if(zh==chazhao)
        {
        	if(!strcmp(mm,mima))
        	//比较两个密码 
        	{
        		printf("请输入新的密码");
        		scanf("%s",mima);
       		    printf("再次输入密码:\n");
	            scanf("%s",password1);
	             if(strcmp(mima,password1)==0)
	            //比较两个密码 
	   			 {
		             xg(chazhao,mima);
		            getch();
				    lmain();
	                system("cls");
   			     }
       			  else
	   			  {
	     printf("\n\t\t*************************************");
         printf("\n\t\t*************************************"); 
         printf("\n\t\t***两次输入密码不一致,按任意键退出***");
         printf("\n\t\t*************************************");
         printf("\n\t\t*************************************");
	       			  hit=getch();
		   			  system("cls");
				      lmain();

   				  }
			}
			else
			{
		 printf("\n\t\t******************************");
         printf("\n\t\t******************************"); 
         printf("\n\t\t***旧密码错误，按任意键返回***");
         printf("\n\t\t******************************");
         printf("\n\t\t******************************");
				getch();
				system("cls");
				lmain();
	            
			}

        }
      }
	     printf("\n\t\t********************************");
         printf("\n\t\t********************************"); 
         printf("\n\t\t***不存在此账号，按任意键返回***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
		fclose(fp);
		//修改结束
		getch();
		system("cls");
		lmain();
}

void InQueue1(linkqueue *q) 
// 进队函数 
{
	FILE *fp;
	fp= fopen("shijian1.txt","a");
    int x;
    char y[10];
    char z[20];
    student *p=new student;
    printf("\n\t\t请输入学号和姓名和班级：");
    scanf("%d%s%s",&x,y,z);
    fprintf(fp,"%d %s %s",x,y,z);
    fclose(fp);
    getchar(); 
    p->number=x;
    strcpy(p->name,y);
    //复制 
    strcpy(p->banji,z);
    p->next=NULL;
    if(q->front==NULL)
        q->front=p;
    else
        q->rear->next=p;
        q->rear=p;
    if(p)
       printf("\n\t\t学号：%d  姓名： %s  班级：%s  \n",x,y,z);
}

void InQueue2(linkqueue *q) 
// 进队函数 
{
	FILE *fp;
	fp= fopen("shijian2.txt","a");
    int x;
    char y[10];
    char z[20];
    student *p=new student;
    printf("\n\t\t请输入学号和姓名和班级：");
    scanf("%d%s%s",&x,y,z);
    fprintf(fp,"%d %s %s",x,y,z);
    fclose(fp);
    getchar(); 
    p->number=x;
    strcpy(p->name,y);
    //复制 
    strcpy(p->banji,z);
    p->next=NULL;
    if(q->front==NULL)
        q->front=p;
    else
        q->rear->next=p;
        q->rear=p;
    if(p)
       printf("\n\t\t学号：%d  姓名： %s  班级：%s  \n",x,y,z);
}

void InQueue3(linkqueue *q) 
// 进队函数 
{
	FILE *fp;
	fp= fopen("shijian3.txt","a");
    int x;
    char y[10];
    char z[20];
    student *p=new student;
    printf("\n\t\t请输入学号和姓名和班级：");
    scanf("%d%s%s",&x,y,z);
    fprintf(fp,"%d %s %s",x,y,z);
    fclose(fp);
    getchar(); 
    p->number=x;
    strcpy(p->name,y);
    //复制 
    strcpy(p->banji,z);
    p->next=NULL;
    if(q->front==NULL)
        q->front=p;
    else
        q->rear->next=p;
        q->rear=p;
    if(p)
       printf("\n\t\t学号：%d  姓名： %s  班级：%s  \n",x,y,z);
}

void ReadFront(linkqueue *q) // 读队首元素函数
{ 
 
 if(q==NULL||q->front==NULL)
         { 
         printf("\n\t\t****************************");
         printf("\n\t\t****************************"); 
         printf("\n\t\t***队列为空!没有队顶元素!***");
         printf("\n\t\t****************************");
         printf("\n\t\t****************************");
         }
	else
    printf("\n\t\t队首元素是：%d     %s     %s\n",q->front->number,q->front->name,q->front->banji);
}

int OutQueue(linkqueue *q) // 出队函数
{
    int i=0;
    student *p;
    if(q->front==NULL)
    return 0;
    else
 {
        p=q->front;
        q->front=p->next;
        if(q->front==NULL)
        q->rear=NULL;
        free(p);
        return 1;
 }
}

void DeleteQueue(linkqueue *q,int num)
//删除函数 
{
 
 student *p=q->front;
 student *t;
 if(p==NULL)
         {
		 printf("\n\t\t***************");
         printf("\n\t\t***************"); 
         printf("\n\t\t***没有学生!***");
         printf("\n\t\t***************");
         printf("\n\t\t***************\n\n");
         } 
 else
 {   int j=0;
  while(p->number!=num&&p!=NULL)
  {
   p=p->next;
   ++j;
  }  
  student *p=q->front;
     while(j>=2)
   {
       p=p->next;
       --j;
   }
  t=p->next;
  p->next=t->next;
  delete t;
  printf("\n\t\t学号为%d的同学已删除\n",num);
  }
}

void ShowQueue(linkqueue *q) 
// 显示队列函数
{ 
 student *p=q->front;
    if(p==NULL)
    {
         printf("\n\n\t\t***************");
         printf("\n\t\t***************"); 
         printf("\n\t\t***没有学生!***");
         printf("\n\t\t***************");
         printf("\n\t\t***************");
    } 
	else
 {
       while(p!=NULL)
    {
     printf("\n\t\t 学号：%d   姓名： %s  班级：  %s",p->number,p->name,p->banji);
           p=p->next;
    }
       printf("\n");
 }
}

void main1()                               
 // 队列子系统主函数
{ 
 linkqueue *time1=new linkqueue,
 *time2=new linkqueue,
 *time3=new linkqueue;
    int i=1; 
	int m=0;
	int num;
    char w;
	int choice;
    time1->front=time1->rear=NULL;
    time2->front=time2->rear=NULL;
    time3->front=time3->rear=NULL;
     while (i)
 {
    printf("\n\n");
    printf("\n\t\t\t\t 实验室预约系统\n");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t* ------ 预约  :1. 时间一 2.时间二 3.时间三 --------*");
    printf("\n\t\t* ------ 删除  :4. 时间一 5.时间二 6.时间三 --------*");
    printf("\n\t\t* ------ 取消  :7. 时间一 8.时间二 9.时间三 --------*");
    printf("\n\t\t* ------ 查询  :10. 时间一 11.时间二 12.时间三 -----*");
    printf("\n\t\t* ------ 13.显示                               -----*");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t请选择菜单号\n");
    printf("\n\t\t\t(1,2,3为预约)\n");
    printf("\n\t\t\t(4,5,6为删除)\n");
    printf("\n\t\t\t(7，8，9为取消)\n");
    printf("\n\t\t\t(10,11,12为查询)\n");
    printf("\n\t\t\t(13为输出三个时间的学生名单)\n");
    printf("\n\t\t\t 请输入你要的操作:");
    scanf("%d",&choice);
    getchar();
    switch(choice)
 {
        case 1:
            InQueue1(time1);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***恭喜你，预约成功***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
        break;
        
        case  2:
            InQueue2(time2);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***恭喜你，预约成功***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
         break;
         
        case  3:
            InQueue3(time3);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***恭喜你，预约成功***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
         break;
         
     case 4:
         for(m=0;m<=4;m++)
   {
                ReadFront(time1);
                if(OutQueue(time1)!=0)
                 printf("\n\t\t 时间一预约前五名正在做实验，逐个出队\n");
               
   }
   
                   printf("\n\n\t\t时间一在队列里的同学名单:\n");
         ShowQueue(time1);
            break;
            
        case 5:
         for(m=0;m<=4;m++)
   {
                ReadFront(time2);
                if(OutQueue(time2)!=0)
                printf("\n\t\t 时间二预约前五名正在做实验，逐个出队\n");
   }
     
                   printf("\n\n\t\t时间二在队列里的同学名单:\n");
         ShowQueue(time2);
            break;
        case  6:
        	
         for(m=0;m<=4;m++)
   {
                ReadFront(time3);
                if(OutQueue(time3)!=0)   
				 printf("\n\t\t 时间三预约前五名正在做实验，逐个出队\n"); 
   }   
                
                   printf("\n\n\t\t时间三在队列里的同学名单:\n");
         ShowQueue(time3);
            break;
            
        case  7:
         printf("\n\t\t请输入时间一中需要取消的同学的学号");
         printf("\n\t\t            (前五位已经确定做实验的同学不能取消)");
         scanf("%d",&num);
         DeleteQueue(time1,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***该学号同学已经成功取消预约***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\t时间一:");
            ShowQueue(time1);
         break;
         
         case  8:
         printf("\n\t\t请输入时间二中需要取消的同学的学号");
         printf("\n\t\t            (前五位已经确定做实验的同学不能取消)");
         scanf("%d",&num);
         DeleteQueue(time2,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***该学号同学已经成功取消预约***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\t时间二:");
            ShowQueue(time2);
           break;
           
        case  9:
         printf("\n\t\t请输入时间三中需要取消的同学的学号");
         printf("\n\t\t            (前五位已经确定做实验的同学不能取消)");
         scanf("%d",&num);
         DeleteQueue(time3,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***该学号同学已经成功取消预约***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\t时间三:");
         ShowQueue(time3);
         break;
        case  10:
         printf("\n\t\t时间一:");
            ShowQueue(time1);
            break;
        case  11:
            printf("\n\t\t时间二:");
            ShowQueue(time2);
            break;
        case  12:
         printf("\n\t\t时间三:");
            ShowQueue(time3);
            break;
            
        case 13:         
		printf("\n\t\t时间一:");
         ShowQueue(time1);
         printf("\n\t\t时间二:");
         ShowQueue(time2);
         printf("\n\t\t时间三:");
         ShowQueue(time3);
         break;
         
       case '0':
            i=0;
            break;
      default:;
 }
    if(choice==0||choice==1
	||choice== 2||choice== 3
	||choice== 4||choice== 5
	||choice== 6||choice== 7
    ||choice== 8||choice== 9
    ||choice== 10||choice== 11
    ||choice== 12||choice== 13)
 { 

         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
         printf("\n\t\t***按回车键继续,按任意键返回登录界面***");
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
        w=getchar();
        if(w!='\xA')
  {
   getchar();
            i=0;
  }
 }
 }
}

void main2()                               
 // 学生队列子系统函数
{ printf("\n\n\t学生只能进行预约和取消操作，输入其他操作无效\n\n"); 
 linkqueue *time1=new linkqueue,
 *time2=new linkqueue,
 *time3=new linkqueue;
    int i=1; 
	int m=0;
	int num;
    char w;
	int choice;
    time1->front=time1->rear=NULL;
    time2->front=time2->rear=NULL;
    time3->front=time3->rear=NULL;
     while (i)
 {
    printf("\n\n");
    printf("\n\t\t\t\t 实验室预约系统\n");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t* ------ 预约  :1. 时间一 2.时间二 3.时间三 --------*");
    printf("\n\t\t* ------ 删除  :4. 时间一 5.时间二 6.时间三 --------*");
    printf("\n\t\t* ------ 取消  :7. 时间一 8.时间二 9.时间三 --------*");
    printf("\n\t\t* ------ 查询  :10. 时间一 11.时间二 12.时间三 -----*");
    printf("\n\t\t* ------ 13.显示                               -----*");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t请选择菜单号\n");
    printf("\n\t\t\t(1,2,3为预约)\n");
    printf("\n\t\t\t(4,5,6为删除)\n");
    printf("\n\t\t\t(7，8，9为取消)\n");
    printf("\n\t\t\t(10,11,12为查询)\n");
    printf("\n\t\t\t(13为输出三个时间的学生名单)\n");
    printf("\n\t\t\t 请输入你要的操作:");
    scanf("%d",&choice);
    getchar();
    switch(choice)
 {
        case 1:
            InQueue1(time1);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***恭喜你，预约成功***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
        break;
        
        case  2:
            InQueue2(time2);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***恭喜你，预约成功***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n"); 
         break;
         
        case  3:
            InQueue3(time3);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***恭喜你，预约成功***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
         break;
         
     case 4:
      shenfen(); 
            break;
            
        case 5:
      shenfen(); 
            break;
        case  6:
        	
          shenfen(); 
            break;
            
        case  7:
         printf("\n\t\t请输入时间一中需要取消的同学的学号");
         printf("\n\t\t            (前五位已经确定做实验的同学不能取消)");
         scanf("%d",&num);
         DeleteQueue(time1,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***该学号同学已经成功取消预约***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\t时间一:");
            ShowQueue(time1);
         break;
         
         case  8:
         printf("\n\t\t请输入时间二中需要取消的同学的学号");
         printf("\n\t\t            (前五位已经确定做实验的同学不能取消)");
         scanf("%d",&num);
         DeleteQueue(time2,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***该学号同学已经成功取消预约***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\t时间二:");
            ShowQueue(time2);
           break;
           
        case  9:
         printf("\n\t\t请输入时间三中需要取消的同学的学号");
         printf("\n\t\t            (前五位已经确定做实验的同学不能取消)");
         scanf("%d",&num);
         DeleteQueue(time3,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***该学号同学已经成功取消预约***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\t时间三:");
         ShowQueue(time3);
         break;
         
        case  10:
          shenfen(); 
            break;
            
        case  11:
            shenfen(); 
            break;
            
        case  12:
           shenfen(); 
            break;
            
        case 13:         
	 shenfen(); 
         break;
         
       case '0':
            i=0;
            break;
      default:;
 }
    if(choice==0||choice==1
	||choice== 2||choice== 3
	||choice== 4||choice== 5
	||choice== 6||choice== 7
    ||choice== 8||choice== 9
    ||choice== 10||choice== 11
    ||choice== 12||choice== 13)
 { 

         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
         printf("\n\t\t***按回车键继续,按任意键返回登录界面***");
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
        w=getchar();
        if(w!='\xA')
  {
   getchar();
            i=0;
  }
 }
 }
}
  void shenfen()
{
	char choose;
	printf("\t\t**********************************************\n");
    printf("\t\t**********************************************\n");
    printf("\n\n\t\t\t\t1.教师身份\n\n");
    printf("\n\n\t\t\t\t2.学生身份\n\n");
    printf("\t\t**********************************************\n");
    printf("\t\t**********************************************\n");
	printf("\n\t\t请选择身份登录"); 
	scanf(" %c",&choose);
	switch(choose) 
	//功能函数
  {
	  case'1':
	    Tlmain();
	    break;
	    system ("cls");
	  case'2':
	  	lmain();
	  	break;
	  	system("cls");
	  	//清屏函数 
    getch();
  	exit(0);
  	//正常退出 
  	system ("cls");
	break;
  }
}

int main()
{   shenfen(); 
	return 1 ;
	printf("/n/n/t/t/t欢迎再次使用实验室预约系统/n/n"); 
}


