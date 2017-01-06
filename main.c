#include<stdio.h>
#include"struct.h"
#include<stdlib.h>

int main(){
  int i=1;
  while(1){
    printf("Welcome to Developer Profile Management System\nChoose any of the following options\n1. Insert\n2. Display\n3. Query\n4. Alter\n5. Exit\n");
    scanf("%d",&i);
    switch(i){
      case 1 : insert();break;
      case 2 : read();break;
      case 3 : query();break;
      case 4 : alter();break;
      case 5 : exit(0);break;
    }
  }
  return 0;
}
