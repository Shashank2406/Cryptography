#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>

void choice();                                            //Function to display Choice
//void welcome();                                           //Function to display the Welcome Screen
void delay();                                             //Function to implement Delay
void caesar();                                            //Function to perform Caesar's Shift
void RSA();                                               //Function to perform RSA Technique

int main()
{
	choice();
    return(0);
}


void delay()
{
	int c=1,d=1;
	for (c=1;c<=32767/3;c++)
	for (d=1;d<=32767/3;d++)
	{}

}
void choice()
{
    printf("\n              ");
	printf("\n \t \t \t \t Menu");
	printf("\n              ");
	printf("\n \t \t \t1.Simple Cryptography");
	printf("\n              ");
	printf("\n \t \t \t2.Difficult Cryptography");
	printf("\n              ");
	printf("\n \t \t \t3.Exit");
	printf("\n              ");

    int ch,flag=1;
    printf("\n \t \t \tEnter the choice of Cryptography\n \t \t \t");
    scanf("%d",&ch);
    switch(ch)
     {
		case 1:caesar();
		       break;
		case 2:RSA();
		       break;
		case 3:exit(0);
		default: printf("\n \t \t \tInvalid Choice");
		         printf("\n              ");
		         flag=0;


     }
     if(flag==0)
      {
          int i;
          system("cls");                          //Used to clear the console
		  printf("\n \t \t \tInvalid Choice please wait");
		  for (i=0;i<4;i++)
		  {
		    delay();
		  	printf(".");

		  }
		  system("cls");
		  choice();
      }

}

void caesar()
{
  char wd[50];
  int shift=1;
  printf("\n \t \t \tEnter text to be encrypted : \n \t \t \t");
  scanf("%s",&wd);
  strupr(wd);
  int i = 0;
  char str1[50];
  strcpy(str1,wd);
  while (str1[i]!='\0')
  {
    if ((str1[i]+shift) >= 65&&(str1[i]+shift)<= 90)
    {
      str1[i]+=(shift);
    }
    else
    {
      str1[i]+=(shift-25);
    }
    i++;
  }
  system("cls");
  printf("\n \t \t \tThe Original text entered by user : %s", wd);
  printf("\n \t \t \tThe encrypted text after shift : %s", str1);
}

void RSA()
{
    int p,q,e,i=0,n=0,phi=0,d=0,c=0,v=0,s=0;
    int y=0,len;
    char msg[50];
    printf("\n \t \t \tEnter the text\n \t \t \t");
    scanf("%s",&msg);
    strupr(msg);
    printf("\n \t \t \tEnter first prime numbers\n \t \t \t");
    scanf("%d",&p);
    printf("\n \t \t \tEnter second prime numbers\n \t \t \t");
    scanf("%d",&q);
    printf("\n \t \t \tEnter any small prime exponent\n \t \t \t");
    scanf("%d",&e);
    n=p*q;
    phi=(p-1)*(q-1);
    d=((2*phi)+1)/e;
    while(msg[i]!='\0')
    {
     if(msg[i]>=65 && msg[i]<=90)
      {
        v=msg[i]-65;
        v=v+1;
        s=s*10+v;

      }
      i++;
    }
    system("cls");
    printf("\n \t \t \tpublic key which is genrated is(%d , %d)",n,e);
    printf("\n \t \t \tprivate key which is genrated is (%d ,%d)",d,n);
    y=pow(s,e);
    c=y%n ;//encryption
    printf("\n              ");
    printf("\n \t \t \tThe  message is %s",msg);
    printf("\n \t \t \tThe encrypted message is %d",c);
}
