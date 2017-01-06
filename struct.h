#include<stdio.h>
#include<string.h>

typedef struct dev {
  char fname[20];
  char lname[20];
  char location[40];
  char email[40];
  char position[40];
  char skill1[20];
  char skill2[20];
}dev;

void query();
void read();
void clear();
void insert();
void alter();


void insert() {
  dev d;
  FILE *fp;
  fp = fopen("data.dat","a");
  printf("Enter First Name\n");
  scanf("%s",d.fname);
  printf("Enter Last Name\n");
  scanf("%s",d.lname);
  printf("Enter Location\n");
  clear();
  scanf("%[^\n]s",d.location);
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
  fclose(fp);
}

void clear(){
  while ( getchar() != '\n' );
}

void alter() {
  int i=1;
  FILE *fp;
  dev d;
  char str[20];
  fp = fopen("data.dat","r+");
  printf("Enter the First Name of the person whose details you want to change\n");
  scanf("%s",str);
  while(1){
    i = fread(&d,sizeof(dev),1,fp);
    if(i != 1) break;
    if(strcmp(str,d.fname) == 0){
      printf("%-10s %-10s %-10s %-30s %-20s %-10s %-10s\n",d.fname, d.lname,d.location,d.email,d.position,d.skill1,d.skill2);
      printf("Enter First Name\n");
      scanf("%s",d.fname);
      printf("Enter Last Name\n");
      scanf("%s",d.lname);
      printf("Enter Location\n");
      clear();
      scanf("%[^\n]s",d.location);
      printf("Enter Email\n");
      scanf("%s",d.email);
      printf("Enter Position\n");
      clear();
      scanf("%[^\n]s",d.position);
      printf("Enter skill 1\n");
      scanf("%s",d.skill1);
      printf("Enter skill 2\n");
      scanf("%s",d.skill2);
      fseek(fp,-sizeof(dev),SEEK_CUR);
      fwrite(&d,sizeof(dev),1,fp);
      break;
    }
  }
  printf("\n");
  fclose(fp);
}

void read(){
  int i=1;
  FILE *fp;
  dev d;
  fp = fopen("data.dat","r");
  printf("\n");
  while(1){
    i = fread(&d,sizeof(dev),1,fp);
    if(i != 1) break;
    printf("%-10s %-10s %-10s %-30s %-20s %-10s %-10s\n",d.fname, d.lname,d.location,d.email,d.position,d.skill1,d.skill2);
  }
  printf("\n");
  fclose(fp);
}

void query(){
  int i=1,j=0,k;
  char str[40];
  FILE *fp;
  dev d;
  fp = fopen("data.dat","r");
  printf("What do you want to query?\n1. First Name\n2. Last Name \n3. Location\n4. Position\n");
  scanf("%d",&k);
  printf("Enter the string\n");
  clear();
  scanf("%[^\n]s",str);
  printf("\n");
  switch(k){

    case 1:
    while(1){
      i = fread(&d,sizeof(dev),1,fp);
      if(i != 1) break;
      if(strcmp(d.fname,str) != 0) continue;
      j = 1;
      printf("%-10s %-10s %-10s %-30s %-20s %-10s %-10s\n",d.fname, d.lname,d.location,d.email,d.position,d.skill1,d.skill2);
    }
    if(j == 0){
      printf("Sorry no such entry was found!!\n");
    }
    break;

    case 2:
    while(1){
      i = fread(&d,sizeof(dev),1,fp);
      if(i != 1) break;
      if(strcmp(d.lname,str) != 0) continue;
      j = 1;
      printf("%-10s %-10s %-10s %-30s %-20s %-10s %-10s\n",d.fname, d.lname,d.location,d.email,d.position,d.skill1,d.skill2);
    }
    if(j == 0){
      printf("Sorry no such entry was found!!\n");
    }
    break;

    case 3:
    while(1){
      i = fread(&d,sizeof(dev),1,fp);
      if(i != 1) break;
      if(strcmp(d.location,str) != 0) continue;
      j = 1;
      printf("%-10s %-10s %-10s %-30s %-20s %-10s %-10s\n",d.fname, d.lname,d.location,d.email,d.position,d.skill1,d.skill2);
    }
    if(j == 0){
      printf("Sorry no such entry was found!!\n");
    }
    break;

    case 4:
    while(1){
      i = fread(&d,sizeof(dev),1,fp);
      if(i != 1) break;
      if(strcmp(d.position,str) != 0) continue;
      j = 1;
      printf("%-10s %-10s %-10s %-30s %-20s %-10s %-10s\n",d.fname, d.lname,d.location,d.email,d.position,d.skill1,d.skill2);
    }
    if(j == 0){
      printf("Sorry no such entry was found!!\n");
    }
    break;

  }
  printf("\n");
  fclose(fp);
}
