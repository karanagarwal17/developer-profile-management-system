#include<stdio.h>
#include"struct.h"
#include<string.h>

void main(){
  int i=1;
  FILE *fp;
  dev d;
  fp = fopen("data.dat","r");
  printf("\n");
  while(1){
    i = fread(&d,sizeof(dev),1,fp);
    if(i != 1) break;
    if(strcmp(d.field,"webdev") != 0) continue;
    printf("%-10s %-10s %-10s %-10s %-20s %-10s %-10s %-10s %-10s\n",d.fname, d.lname,d.field,d.location,d.email,d.position,d.language1,d.language2,d.language3);
  }
  printf("\n");
  fclose(fp);
}