#include<stdio.h>
#include"struct.h"

void main() {
  dev d;
  char ch[3] = "yes";
  FILE *fp;
  fp = fopen("data.dat","a");
  while(ch[0] == 'y'){
    printf("Enter fname lname field location email\n");
    scanf("%s %s %s %s %s",d.fname,d.lname,d.field,d.location,d.email);
    printf("Enter position\n");
    scanf("%s",d.position);
    printf("Enter languages 1 2 3\n");
    scanf("%s %s %s",d.language1,d.language2,d.language3);
    fwrite(&d,sizeof(dev),1,fp);
    printf("Enter more data ? (yes/no)\n");
    scanf("%s",ch);
  }
  fclose(fp);
}
