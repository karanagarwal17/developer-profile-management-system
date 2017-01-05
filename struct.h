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

void read(){
  int i=1;
  FILE *fp;
  dev d;
  fp = fopen("data.dat","r");
  printf("\n");
  while(1){
    i = fread(&d,sizeof(dev),1,fp);
    if(i != 1) break;
    printf("%-10s %-10s %-10s %-20s %-10s %-10s %-10s\n",d.fname, d.lname,d.location,d.email,d.position,d.skill1,d.skill2);
  }
  printf("\n");
  fclose(fp);
}

void query(){
  int i=1;
  FILE *fp;
  dev d;
  fp = fopen("data.dat","r");
  printf("\n");
  while(1){
    i = fread(&d,sizeof(dev),1,fp);
    if(i != 1) break;
    if(strcmp(d.fname,"karan") != 0) continue;
    printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s\n",d.fname, d.lname,d.location,d.email,d.position,d.skill1,d.skill2);
  }
  printf("\n");
  fclose(fp);
}
