#include <stdio.h>
#include<conio.h>

void fun (char wd[], int shift);

int main ()
{
  char wd[50];
  int shift=1;

  printf("Enter text to be encrypted : \n");
  gets(wd);
  strupr(wd);
  fun (wd, shift);

  return (0);
}

void fun (char wd[], int shift)
{
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
  printf("\nThe Original text entered by user : %s", wd);
  printf("\nThe encrypted text after shift : %s", str1);
}
