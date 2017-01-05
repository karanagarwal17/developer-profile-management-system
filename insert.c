#include<stdio.h>
#include"struct.h"

void clear (void)
{
  while ( getchar() != '\n' );
}

void main() {
  dev d;
  char ch[3] = "yes";
  FILE *fp;
  fp = fopen("data.dat","a");
  while(ch[0] == 'y'){
    printf("Enter First Name\n");
    scanf("%s",d.fname);
    printf("Enter Last Name\n");
    scanf("%s",d.lname);
    printf("Enter Location\n");
    scanf("%s",d.location);
    printf("Enter Email\n");
    scanf("%s",d.email);
    printf("Enter Position\n");
    clear();
    scanf("%[^\n]s",d.position);
    printf("Enter skill 1\n");
    scanf("%s",d.skill1);
    printf("Enter skill 2\n");
    scanf("%s",d.skill2);
    fwrite(&d,sizeof(dev),1,fp);
    printf("Enter more data ? (yes/no)\n");
    scanf("%s",ch);
  }
  fclose(fp);
}
