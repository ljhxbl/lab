#include <stdio.h>
#include <stdlib.h>//���а���system����
#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch������
#include <string.h>//�����ַ�����
#include <math.h>
#include<memory.h> 
#define LEN sizeof(struct land)//�йص�¼ϵͳ�Ľṹ��

struct Tland//��ʦ��¼��Ϣ
{
	int zhanghao;//�˺� 
	char password[20];//���� 
	struct Tland*next;
};

struct land//ѧ����¼��Ϣ
{
	int zhanghao;	//�˺� 
	char password[20];	//���� 
	struct land*next;
};

typedef struct QNode//�й�ѧ����Ϣ�Ľṹ�� 
{ 
  char name[10];//���� 
   char banji[10];//�༶ 
  int  number;//�༶ 
  struct QNode*next;
}student;

typedef struct//�й�ʱ���Ľṹ�� 
{
 QNode *front;
 QNode *rear;
}linkqueue;

void lmenu();      //��ʾѧ����¼�˵����� 
void main1();      // ѧ����ʵ����ԤԼ���溯�� 
void land();      //ѧ����¼����ϵͳ���� 
int xinjian(int,char[]);   //ѧ�������˺����뺯�� 
void xgmm();           //ѧ���޸����뺯�� 
void lmain();      //ѧ����¼���溯��
void Tlmenu();    //��ʦ����ʾ��¼�˵����� 
void main2();    // ��ʦ��ʵ����ԤԼ���溯�� 
void Tland();    //��ʦ�˵�¼����ϵͳ���� 
int Txinjian(int,char[] );    //��ʦ�˴����˺����뺯�� 
void Txgmm();    //��ʦ���޸����뺯�� 
void Tlmain();    //��ʦ�˵�¼���溯��
void shenfen();   //ѡ����ݺ��� 

int Ttj()
//ͳ����ʦ�˺������ı�����
{
FILE *fp;
//�ļ�ָ�� 
int zhao=0, n;
char mm[20]={'\0'};
fp=fopen("Tland.txt","r");
//���ļ�
for (n=0;!feof(fp);n++)
//������ļ�
fscanf(fp,"%d %s",&zhao,mm);
n--;
fclose(fp);
//�ر��ļ�
return (n);
//���ظ���
}

void Tlmenu()
//��ʾ��ʦ�˵�¼�˵����� 
{
printf("\n\n\t��ӭʹ�ý�ʦ��ʵ����ԤԼ��¼ϵͳ\n\n");
printf("**********************************************\n");
printf("**********************************************\n");
printf("\n\n\t\t1.��¼ϵͳ\n\n");
printf("\n\n\t\t2.�����˺�\n\n");
printf("\n\n\t\t3.�޸�����\n\n");
printf("\n\n\t\t4.�˳���¼ϵͳ\n\n");
printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
printf("**********************************************\n");
printf("**********************************************\n");
printf("\n\t\t��ѡ��1-4��"); 
return ;
}  

void Tlmain()
//��¼���ܺ���
{
	void Tland();
	//��¼����ϵͳ���� 
	void Txinjian();
	//�½��˺����뺯�� 
	char choose;
	Tlmenu();
	scanf(" %c",&choose);
	switch(choose) 
	//���ܺ���
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
	  	//�������� 
    getch();
  	exit(0);
  	//�����˳� 
  	system ("cls");
	break;
  }
}

void Txinjian()
//�½��˻����뺯�� 
{
	FILE *fp;
	int zhanghao;
	//�˺� 
	char password[20];
	//���� 
	char password1[20];
	//����ȷ������ 
	char hit=0;
	if ((fp=fopen("Tland.txt","r"))==NULL)
	//���ļ�ֻ�� 
	{
      fp=fopen("Tland.txt","w");
      //�����µ��ļ���ֻ����д������ 
      fclose(fp);
      //�ر��ļ� 
    }
    system("cls");
    //�������� 
	fp=fopen("Tland.txt","a");
	//��"land"�ļ����������ļ�ĩβд������ 
	for(;;)
	//������������ȷ�ϣ�������ͬ����ȷ��
	{
	   printf("\n�밴���¸�ʽ�����˻�:\nѧ�� ����\n");
	   printf("������:");
	   scanf("%d %s",&zhanghao,password);
       printf("�ٴ���������:\n");
	   scanf("%s",password1);
	   if(strcmp(password,password1)==0)
	   //�Ƚ���������������Ƿ�һ�� 
	   {
	       fprintf(fp,"%d %s\n",zhanghao,password);
	       //������д���ļ� 
		   break;
       }
       else
	   {
	     printf("\n\t\t***************************************************");
         printf("\n\t\t***************************************************"); 
         printf("\n\t\t***�����������벻һ�£������������س����˳���ESC***");
         printf("\n\t\t***************************************************");
         printf("\n\t\t***************************************************");
	       hit=getch();
		   if(hit=27)
		   //�����ESC�� 
		   system("cls");
		   //�������� 
		   Tlmain();
	   }
   }
   fclose(fp);
   //�ر��ļ� 
         printf("\n\t\t****************************");
         printf("\n\t\t****************************"); 
         printf("\n\t\t***�����ɹ��������������***");
         printf("\n\t\t****************************");
         printf("\n\t\t****************************");
         getch();
         system("cls");
         Tlmain();
}

int Tmatch(int m,char a[20])
//ƥ�����ݿ��е��˺����뺯�� 
{
	FILE*fp;
	//�ļ�ָ�� 
	int n=0,i=0,zhanghao;
	char password[20];
	if ((fp=fopen("Tland.txt","r"))==NULL)
	//��������ʦ��Ϣ�ļ�
	  {
         system ("cls");
		 printf("\n ");
		 printf("\n\t\t*****************************");
         printf("\n\t\t*****************************"); 
         printf("\n\t\t***��δ�����û�!���½��˻�***");
         printf("\n\t\t*****************************");
         printf("\n\t\t*****************************");
		 getch();
	 	system("cls");
		Tlmain();
      }
        for(;!feof(fp);)
      {
        fscanf(fp,"%d%s",&zhanghao,password);
        //���ļ������� 
        if(m==zhanghao)
        {
        	if(strcmp(a,password)==0)
        	//�Ƚ������Ƿ���ͬ 
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
//�����˻�����ĵ�¼����
{
	int zhanghao;
	char password[20];
	int i=2, j, k, n;
	char hit=0;
	system("cls");
	do
	{
	   printf("\n�������˺�:\n");
       scanf("%d",&zhanghao);
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
         printf("\n\t\t***ȷ�������밴�س������������밴ECS***");
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
       hit=getch();
	   //��ͣ����i���պ������һ��ָ��
       for (;hit!=13&&hit!=27;)
	   //��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
       {
	        hit=getch();
	   }
    }
    while(hit==27);
	 printf("\n����������:\n");
	 scanf("%s",password);
     i=Tmatch(zhanghao,password);
     //����"match"�����Ƿ��˺ź������Ƿ������ 
     if(i==1)
	 {
         printf("\n\t\t***************************");
         printf("\n\t\t***************************");
         printf("\n\t\t***��½�ɹ�!�����������***");
         printf("\n\t\t***************************");
         printf("\n\t\t***************************");
	   getch();
	   system ("cls");
	   //�������� 
	   main1();
	   Tlmain();
	 }
	 else
	 {
	 	if(i==-1)
		 {
		 printf("\n\t\t************************");
         printf("\n\t\t************************"); 
         printf("\n\t\t***������˼���������***");
         printf("\n\t\t************************");
         printf("\n\t\t************************");
		 getch();
         Tland();
		 }
		 if(i==0)
		 printf("\n\t\t****************************************");
         printf("\n\t\t****************************************"); 
         printf("\n\t\t***�����ڴ��û���ȷ���˺�����������½***");
         printf("\n\t\t****************************************");
         printf("\n\t\t****************************************\n\n\n");
		 getch();
		 system("cls");
		 Tlmain();
	 }
}

void Txg(int z,char m[20])
//�޸ĺ���
{
	FILE *fp;
	//�ļ�ָ�� 
	int zhanghao1,n,j,k;
	char mima1[20];
	struct land *head,*p,*p1,*p2;
	 fp=fopen("Tland.txt","r");
	 //���ļ�ֻ�� 
	   j =Ttj();
	   for (k=0;k<=j;k++)
       {
	       fscanf(fp,"%d %s",&zhanghao1,mima1);
	       //���ļ�����˺ź����� 
           if (z!=zhanghao1)
		   //�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
          {
	            n++;
				//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ��ѧ����Ϣ����������
	            if (n==1)
				//��������
                {
		          p1=p2=(struct land*)malloc(LEN);
		          //����ռ� 
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct land*)malloc(LEN);
				  //�½�����
                }
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);
				//�����˺�����
          }
       }
        if (n==0)
			 {
			 head=NULL;
			 }
			 else
			 //������������ʣ��һ������ռ䣬���Է��
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 //�ر��ļ� 
			 }
			  fp=fopen("Tland.txt","w");
			  //����ļ���ֻд�򿪣�Ȼ��ر�
              fclose(fp);
              fp=fopen("Tland.txt","a");
			  //׷���ļ�
              p=head;
            for (;p!=NULL;)
			//���������ݸ��ǵ��ļ�
   			{
   	   		 	fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   		 	//д�����ݵ��ļ� 
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s\n",z,m);
            fclose(fp);
            //�ر��ļ� 
         printf("\n\t\t******************");
         printf("\n\t\t******************"); 
         printf("\n\t\t***�޸�����ɹ�***");
         printf("\n\t\t******************");
         printf("\n\t\t******************");
            

}

   void Txgmm()
   //�޸����뺯�� 
{

	   FILE *fp;
	   //�ļ�ָ�� 
       int zh=0,k=0,many=0;
	   int m=0,n=0, chazhao;
	   int hit;
       char mima[20]={'\0'};
	   char password1[20]={'\0'};
       char  mm[20]={'\0'};
       char i;
       if ((fp=fopen("Tland.txt","r"))==NULL)
	   //���ļ�
       {
	       system ("cls");
         printf("\n\t\t*********************************");
         printf("\n\t\t*********************************"); 
         printf("\n\t\t***��¼�ļ�������!�����������***");
         printf("\n\t\t*********************************");
         printf("\n\t\t*********************************");
  		   getch();
  		   system("cls");
		   Tlmain();
       }
	   system("cls");
       printf("����������ʺź;����룺\n");
       scanf("%d %s",&chazhao,mima);
	   m =Ttj();
	   for (n=0;n<=m;n++)
	   {
	    fscanf(fp,"%d %s",&zh,mm);
        if(zh==chazhao)
        {
        	if(!strcmp(mm,mima))
        	//�Ƚ��������� 
        	{
        		printf("�������µ�����");
        		scanf("%s",mima);
       		    printf("�ٴ���������:\n");
	            scanf("%s",password1);
	             if(strcmp(mima,password1)==0)
	            //�Ƚ��������� 
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
         printf("\n\t\t***�����������벻һ��,��������˳�***");
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
         printf("\n\t\t***��������󣬰����������***");
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
         printf("\n\t\t***�����ڴ��˺ţ������������***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
		fclose(fp);
		//�޸Ľ���
		getch();
		system("cls");
		Tlmain();
}

int tj()
//ͳ���˺������ı�����
{
FILE *fp;
//�ļ�ָ�� 
int zhao=0; 
int n;
char mm[20]={'\0'};
fp=fopen("land.txt","r");
//���ļ�
for (n=0;!feof(fp);n++)
//������ļ�
fscanf(fp,"%d %s",&zhao,mm);
n--;
fclose(fp);
//�ر��ļ�
return (n);
//���ظ���
}

void lmenu()
//��ʾ��¼�˵����� 
{
printf("\n\n\t��ӭʹ��ѧ��ʵ����ԤԼ��¼ϵͳ\n\n");
printf("**********************************************\n");
printf("**********************************************\n");
printf("\n\n\t\t1.��¼ϵͳ\n\n");
printf("\n\n\t\t2.�����˺�\n\n");
printf("\n\n\t\t3.�޸�����\n\n");
printf("\n\n\t\t4.�˳���¼ϵͳ\n\n");
printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
printf("**********************************************\n");
printf("**********************************************\n");
printf("\n\t\t��ѡ��1-4��"); 
return ;
}  

void lmain()
//��¼���ܺ���
{
	void land();
	//��¼����ϵͳ���� 
	void xinjian();
	//�½��˺����뺯�� 
	char choose;
	lmenu();
	scanf(" %c",&choose);
	switch(choose) 
	//���ܺ���
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
	  	//�������� 
    getch();
  	exit(0);
  	//�����˳� 
  	system ("cls");
	break;
  }
}


void xinjian()
//�½��˻����뺯�� 
{
	FILE *fp;
	int zhanghao;
	//�˺� 
	char password[20];
	//���� 
	char password1[20];
	//����ȷ������ 
	char hit=0;
	if ((fp=fopen("land.txt","r"))==NULL)
	//���ļ�ֻ�� 
	{
      fp=fopen("land.txt","w");
      //�����µ��ļ���ֻ����д������ 
      fclose(fp);
      //�ر��ļ� 
    }
    system("cls");
    //�������� 
	fp=fopen("land.txt","a");
	//��"land"�ļ����������ļ�ĩβд������ 
	for(;;)
	//������������ȷ�ϣ�������ͬ����ȷ��
	{
	   printf("\n�밴���¸�ʽ�����˻�:\nѧ�� ����\n");
	   printf("������:");
	   scanf("%d %s",&zhanghao,password);
       printf("�ٴ���������:\n");
	   scanf("%s",password1);
	   if(strcmp(password,password1)==0)
	   //�Ƚ���������������Ƿ�һ�� 
	   {
	       fprintf(fp,"%d %s\n",zhanghao,password);
	       //������д���ļ� 
		   break;
       }
       else
	   {
	     printf("\n\t\t***************************************************");
         printf("\n\t\t***************************************************"); 
         printf("\n\t\t***�����������벻һ�£������������س����˳���ESC***");
         printf("\n\t\t***************************************************");
         printf("\n\t\t***************************************************");
	       hit=getch();
		   if(hit=27)
		   //�����ESC�� 
		   system("cls");
		   //�������� 
		   lmain();
	   }
   }
   fclose(fp);
   //�ر��ļ� 
         printf("\n\t\t****************************");
         printf("\n\t\t****************************"); 
         printf("\n\t\t***�����ɹ��������������***");
         printf("\n\t\t****************************");
         printf("\n\t\t****************************");
   getch();
   system("cls");
   lmain();
}

int match(int m,char a[20])
//ƥ�����ݿ��е��˺����뺯�� 
{
	FILE*fp;
	//�ļ�ָ�� 
	int n=0;
	int i=0;
	int zhanghao;
	char password[20];
	if ((fp=fopen("land.txt","r"))==NULL)
	//������ѧ����Ϣ�ļ�
	  {
         system ("cls");
		 printf("\n ");
		 printf("\n\t\t*****************************");
         printf("\n\t\t*****************************"); 
         printf("\n\t\t***��δ�����û�!���½��˻�***");
         printf("\n\t\t*****************************");
         printf("\n\t\t*****************************");
		 getch();
	 	 system("cls");
		 lmain();
      }
        for(;!feof(fp);)
      {
        fscanf(fp,"%d%s",&zhanghao,password);
        //���ļ������� 
        if(m==zhanghao)
        {
        	if(strcmp(a,password)==0)
        	//�Ƚ������Ƿ���ͬ 
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
//�����˻�����ĵ�¼����
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
	   printf("\n�������˺�:\n");
       scanf("%d",&zhanghao);
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
         printf("\n\t\t***ȷ�������밴�س������������밴ECS***");
         printf("\n\t\t***************************************");
         printf("\n\t\t***************************************");
       hit=getch();
	   //��ͣ����i���պ������һ��ָ��
       for (;hit!=13&&hit!=27;)
	   //��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
       {
	        hit=getch();
	   }
    }
    while(hit==27);
	 printf("\n����������:\n");
	 scanf("%s",password);
     i=match(zhanghao,password);
     //����"match"�����Ƿ��˺ź������Ƿ������ 
     if(i==1)
	 {
         printf("\n\t\t***************************");
         printf("\n\t\t***************************");
         printf("\n\t\t***��½�ɹ�!�����������***");
         printf("\n\t\t***************************");
         printf("\n\t\t***************************");
	   getch();
	   system ("cls");
	   //�������� 
	   main2();
	   lmain();
	 }
	 else
	 {
	 	if(i==-1)
		 {
		 printf("\n\t\t************************");
         printf("\n\t\t************************"); 
         printf("\n\t\t***������˼���������***");
         printf("\n\t\t************************");
         printf("\n\t\t************************");
		 getch();
         land();
		 }
		 if(i==0)
		 printf("\n\t\t****************************************");
         printf("\n\t\t****************************************"); 
         printf("\n\t\t***�����ڴ��û���ȷ���˺�����������½***");
         printf("\n\t\t****************************************");
         printf("\n\t\t****************************************\n\n\n");
		 getch();
		 system("cls");
		 lmain();
	 }
}

void xg(int z,char m[20])
//�޸ĺ���
{
	FILE *fp;
	//�ļ�ָ�� 
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
	 //���ļ�ֻ�� 
	   j =tj();

	   for (k=0;k<=j;k++)
       {
	       fscanf(fp,"%d %s",&zhanghao1,mima1);
	       //���ļ�����˺ź����� 
           if (z!=zhanghao1)
		   //�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
          {
	            n++;
				//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ��ѧ����Ϣ����������
	            if (n==1)
				//��������
                {
		          p1=p2=(struct land*)malloc(LEN);
		          //����ռ� 
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct land*)malloc(LEN);
				  //�½�����
                }
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);
				//�����˺�����
          }
       }
        if (n==0)
			 {
			 head=NULL;
			 }
			 else
			 //������������ʣ��һ������ռ䣬���Է��
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 //�ر��ļ� 
			 }
			  fp=fopen("land.txt","w");
			  //����ļ���ֻд�򿪣�Ȼ��ر�
              fclose(fp);
              fp=fopen("land.txt","a");
			  //׷���ļ�
              p=head;
            for (;p!=NULL;)
			//���������ݸ��ǵ��ļ�
   			{
   	   		 	fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   		 	//д�����ݵ��ļ� 
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s\n",z,m);
            fclose(fp);
            //�ر��ļ� 
             system ("cls");

}

   void xgmm()
   //�޸����뺯�� 
{
	   FILE *fp;
	   //�ļ�ָ�� 
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
	   //���ļ�
       {
	       system ("cls");
         printf("\n\t\t*********************************");
         printf("\n\t\t*********************************"); 
         printf("\n\t\t***��¼�ļ�������!�����������***");
         printf("\n\t\t*********************************");
         printf("\n\t\t*********************************");
  		   getch();
  		   system("cls");
		   lmain();
       }
	   system("cls");
       printf("����������ʺź;����룺\n");
       scanf("%d %s",&chazhao,mima);
	   m =tj();
	   for (n=0;n<=m;n++)
	   {
	    fscanf(fp,"%d %s",&zh,mm);
        if(zh==chazhao)
        {
        	if(!strcmp(mm,mima))
        	//�Ƚ��������� 
        	{
        		printf("�������µ�����");
        		scanf("%s",mima);
       		    printf("�ٴ���������:\n");
	            scanf("%s",password1);
	             if(strcmp(mima,password1)==0)
	            //�Ƚ��������� 
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
         printf("\n\t\t***�����������벻һ��,��������˳�***");
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
         printf("\n\t\t***��������󣬰����������***");
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
         printf("\n\t\t***�����ڴ��˺ţ������������***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
		fclose(fp);
		//�޸Ľ���
		getch();
		system("cls");
		lmain();
}

void InQueue1(linkqueue *q) 
// ���Ӻ��� 
{
	FILE *fp;
	fp= fopen("shijian1.txt","a");
    int x;
    char y[10];
    char z[20];
    student *p=new student;
    printf("\n\t\t������ѧ�ź������Ͱ༶��");
    scanf("%d%s%s",&x,y,z);
    fprintf(fp,"%d %s %s",x,y,z);
    fclose(fp);
    getchar(); 
    p->number=x;
    strcpy(p->name,y);
    //���� 
    strcpy(p->banji,z);
    p->next=NULL;
    if(q->front==NULL)
        q->front=p;
    else
        q->rear->next=p;
        q->rear=p;
    if(p)
       printf("\n\t\tѧ�ţ�%d  ������ %s  �༶��%s  \n",x,y,z);
}

void InQueue2(linkqueue *q) 
// ���Ӻ��� 
{
	FILE *fp;
	fp= fopen("shijian2.txt","a");
    int x;
    char y[10];
    char z[20];
    student *p=new student;
    printf("\n\t\t������ѧ�ź������Ͱ༶��");
    scanf("%d%s%s",&x,y,z);
    fprintf(fp,"%d %s %s",x,y,z);
    fclose(fp);
    getchar(); 
    p->number=x;
    strcpy(p->name,y);
    //���� 
    strcpy(p->banji,z);
    p->next=NULL;
    if(q->front==NULL)
        q->front=p;
    else
        q->rear->next=p;
        q->rear=p;
    if(p)
       printf("\n\t\tѧ�ţ�%d  ������ %s  �༶��%s  \n",x,y,z);
}

void InQueue3(linkqueue *q) 
// ���Ӻ��� 
{
	FILE *fp;
	fp= fopen("shijian3.txt","a");
    int x;
    char y[10];
    char z[20];
    student *p=new student;
    printf("\n\t\t������ѧ�ź������Ͱ༶��");
    scanf("%d%s%s",&x,y,z);
    fprintf(fp,"%d %s %s",x,y,z);
    fclose(fp);
    getchar(); 
    p->number=x;
    strcpy(p->name,y);
    //���� 
    strcpy(p->banji,z);
    p->next=NULL;
    if(q->front==NULL)
        q->front=p;
    else
        q->rear->next=p;
        q->rear=p;
    if(p)
       printf("\n\t\tѧ�ţ�%d  ������ %s  �༶��%s  \n",x,y,z);
}

void ReadFront(linkqueue *q) // ������Ԫ�غ���
{ 
 
 if(q==NULL||q->front==NULL)
         { 
         printf("\n\t\t****************************");
         printf("\n\t\t****************************"); 
         printf("\n\t\t***����Ϊ��!û�жӶ�Ԫ��!***");
         printf("\n\t\t****************************");
         printf("\n\t\t****************************");
         }
	else
    printf("\n\t\t����Ԫ���ǣ�%d     %s     %s\n",q->front->number,q->front->name,q->front->banji);
}

int OutQueue(linkqueue *q) // ���Ӻ���
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
//ɾ������ 
{
 
 student *p=q->front;
 student *t;
 if(p==NULL)
         {
		 printf("\n\t\t***************");
         printf("\n\t\t***************"); 
         printf("\n\t\t***û��ѧ��!***");
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
  printf("\n\t\tѧ��Ϊ%d��ͬѧ��ɾ��\n",num);
  }
}

void ShowQueue(linkqueue *q) 
// ��ʾ���к���
{ 
 student *p=q->front;
    if(p==NULL)
    {
         printf("\n\n\t\t***************");
         printf("\n\t\t***************"); 
         printf("\n\t\t***û��ѧ��!***");
         printf("\n\t\t***************");
         printf("\n\t\t***************");
    } 
	else
 {
       while(p!=NULL)
    {
     printf("\n\t\t ѧ�ţ�%d   ������ %s  �༶��  %s",p->number,p->name,p->banji);
           p=p->next;
    }
       printf("\n");
 }
}

void main1()                               
 // ������ϵͳ������
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
    printf("\n\t\t\t\t ʵ����ԤԼϵͳ\n");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t* ------ ԤԼ  :1. ʱ��һ 2.ʱ��� 3.ʱ���� --------*");
    printf("\n\t\t* ------ ɾ��  :4. ʱ��һ 5.ʱ��� 6.ʱ���� --------*");
    printf("\n\t\t* ------ ȡ��  :7. ʱ��һ 8.ʱ��� 9.ʱ���� --------*");
    printf("\n\t\t* ------ ��ѯ  :10. ʱ��һ 11.ʱ��� 12.ʱ���� -----*");
    printf("\n\t\t* ------ 13.��ʾ                               -----*");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t��ѡ��˵���\n");
    printf("\n\t\t\t(1,2,3ΪԤԼ)\n");
    printf("\n\t\t\t(4,5,6Ϊɾ��)\n");
    printf("\n\t\t\t(7��8��9Ϊȡ��)\n");
    printf("\n\t\t\t(10,11,12Ϊ��ѯ)\n");
    printf("\n\t\t\t(13Ϊ�������ʱ���ѧ������)\n");
    printf("\n\t\t\t ��������Ҫ�Ĳ���:");
    scanf("%d",&choice);
    getchar();
    switch(choice)
 {
        case 1:
            InQueue1(time1);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***��ϲ�㣬ԤԼ�ɹ�***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
        break;
        
        case  2:
            InQueue2(time2);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***��ϲ�㣬ԤԼ�ɹ�***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
         break;
         
        case  3:
            InQueue3(time3);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***��ϲ�㣬ԤԼ�ɹ�***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
         break;
         
     case 4:
         for(m=0;m<=4;m++)
   {
                ReadFront(time1);
                if(OutQueue(time1)!=0)
                 printf("\n\t\t ʱ��һԤԼǰ����������ʵ�飬�������\n");
               
   }
   
                   printf("\n\n\t\tʱ��һ�ڶ������ͬѧ����:\n");
         ShowQueue(time1);
            break;
            
        case 5:
         for(m=0;m<=4;m++)
   {
                ReadFront(time2);
                if(OutQueue(time2)!=0)
                printf("\n\t\t ʱ���ԤԼǰ����������ʵ�飬�������\n");
   }
     
                   printf("\n\n\t\tʱ����ڶ������ͬѧ����:\n");
         ShowQueue(time2);
            break;
        case  6:
        	
         for(m=0;m<=4;m++)
   {
                ReadFront(time3);
                if(OutQueue(time3)!=0)   
				 printf("\n\t\t ʱ����ԤԼǰ����������ʵ�飬�������\n"); 
   }   
                
                   printf("\n\n\t\tʱ�����ڶ������ͬѧ����:\n");
         ShowQueue(time3);
            break;
            
        case  7:
         printf("\n\t\t������ʱ��һ����Ҫȡ����ͬѧ��ѧ��");
         printf("\n\t\t            (ǰ��λ�Ѿ�ȷ����ʵ���ͬѧ����ȡ��)");
         scanf("%d",&num);
         DeleteQueue(time1,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***��ѧ��ͬѧ�Ѿ��ɹ�ȡ��ԤԼ***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\tʱ��һ:");
            ShowQueue(time1);
         break;
         
         case  8:
         printf("\n\t\t������ʱ�������Ҫȡ����ͬѧ��ѧ��");
         printf("\n\t\t            (ǰ��λ�Ѿ�ȷ����ʵ���ͬѧ����ȡ��)");
         scanf("%d",&num);
         DeleteQueue(time2,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***��ѧ��ͬѧ�Ѿ��ɹ�ȡ��ԤԼ***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\tʱ���:");
            ShowQueue(time2);
           break;
           
        case  9:
         printf("\n\t\t������ʱ��������Ҫȡ����ͬѧ��ѧ��");
         printf("\n\t\t            (ǰ��λ�Ѿ�ȷ����ʵ���ͬѧ����ȡ��)");
         scanf("%d",&num);
         DeleteQueue(time3,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***��ѧ��ͬѧ�Ѿ��ɹ�ȡ��ԤԼ***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\tʱ����:");
         ShowQueue(time3);
         break;
        case  10:
         printf("\n\t\tʱ��һ:");
            ShowQueue(time1);
            break;
        case  11:
            printf("\n\t\tʱ���:");
            ShowQueue(time2);
            break;
        case  12:
         printf("\n\t\tʱ����:");
            ShowQueue(time3);
            break;
            
        case 13:         
		printf("\n\t\tʱ��һ:");
         ShowQueue(time1);
         printf("\n\t\tʱ���:");
         ShowQueue(time2);
         printf("\n\t\tʱ����:");
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
         printf("\n\t\t***���س�������,����������ص�¼����***");
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
 // ѧ��������ϵͳ����
{ printf("\n\n\tѧ��ֻ�ܽ���ԤԼ��ȡ����������������������Ч\n\n"); 
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
    printf("\n\t\t\t\t ʵ����ԤԼϵͳ\n");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t* ------ ԤԼ  :1. ʱ��һ 2.ʱ��� 3.ʱ���� --------*");
    printf("\n\t\t* ------ ɾ��  :4. ʱ��һ 5.ʱ��� 6.ʱ���� --------*");
    printf("\n\t\t* ------ ȡ��  :7. ʱ��һ 8.ʱ��� 9.ʱ���� --------*");
    printf("\n\t\t* ------ ��ѯ  :10. ʱ��һ 11.ʱ��� 12.ʱ���� -----*");
    printf("\n\t\t* ------ 13.��ʾ                               -----*");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t��ѡ��˵���\n");
    printf("\n\t\t\t(1,2,3ΪԤԼ)\n");
    printf("\n\t\t\t(4,5,6Ϊɾ��)\n");
    printf("\n\t\t\t(7��8��9Ϊȡ��)\n");
    printf("\n\t\t\t(10,11,12Ϊ��ѯ)\n");
    printf("\n\t\t\t(13Ϊ�������ʱ���ѧ������)\n");
    printf("\n\t\t\t ��������Ҫ�Ĳ���:");
    scanf("%d",&choice);
    getchar();
    switch(choice)
 {
        case 1:
            InQueue1(time1);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***��ϲ�㣬ԤԼ�ɹ�***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n");
        break;
        
        case  2:
            InQueue2(time2);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***��ϲ�㣬ԤԼ�ɹ�***");
             printf("\n\t\t**********************");
             printf("\n\t\t**********************\n\n\n"); 
         break;
         
        case  3:
            InQueue3(time3);
             printf("\n\t\t**********************");
             printf("\n\t\t**********************");
             printf("\n\t\t***��ϲ�㣬ԤԼ�ɹ�***");
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
         printf("\n\t\t������ʱ��һ����Ҫȡ����ͬѧ��ѧ��");
         printf("\n\t\t            (ǰ��λ�Ѿ�ȷ����ʵ���ͬѧ����ȡ��)");
         scanf("%d",&num);
         DeleteQueue(time1,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***��ѧ��ͬѧ�Ѿ��ɹ�ȡ��ԤԼ***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\tʱ��һ:");
            ShowQueue(time1);
         break;
         
         case  8:
         printf("\n\t\t������ʱ�������Ҫȡ����ͬѧ��ѧ��");
         printf("\n\t\t            (ǰ��λ�Ѿ�ȷ����ʵ���ͬѧ����ȡ��)");
         scanf("%d",&num);
         DeleteQueue(time2,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***��ѧ��ͬѧ�Ѿ��ɹ�ȡ��ԤԼ***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\tʱ���:");
            ShowQueue(time2);
           break;
           
        case  9:
         printf("\n\t\t������ʱ��������Ҫȡ����ͬѧ��ѧ��");
         printf("\n\t\t            (ǰ��λ�Ѿ�ȷ����ʵ���ͬѧ����ȡ��)");
         scanf("%d",&num);
         DeleteQueue(time3,num);
         printf("\n\t\t********************************");
         printf("\n\t\t********************************");
         printf("\n\t\t***��ѧ��ͬѧ�Ѿ��ɹ�ȡ��ԤԼ***");
         printf("\n\t\t********************************");
         printf("\n\t\t********************************\n\n");
         printf("\n\t\tʱ����:");
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
         printf("\n\t\t***���س�������,����������ص�¼����***");
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
    printf("\n\n\t\t\t\t1.��ʦ���\n\n");
    printf("\n\n\t\t\t\t2.ѧ�����\n\n");
    printf("\t\t**********************************************\n");
    printf("\t\t**********************************************\n");
	printf("\n\t\t��ѡ����ݵ�¼"); 
	scanf(" %c",&choose);
	switch(choose) 
	//���ܺ���
  {
	  case'1':
	    Tlmain();
	    break;
	    system ("cls");
	  case'2':
	  	lmain();
	  	break;
	  	system("cls");
	  	//�������� 
    getch();
  	exit(0);
  	//�����˳� 
  	system ("cls");
	break;
  }
}

int main()
{   shenfen(); 
	return 1 ;
	printf("/n/n/t/t/t��ӭ�ٴ�ʹ��ʵ����ԤԼϵͳ/n/n"); 
}


