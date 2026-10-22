#include <stdio.h>

void swap (int *a, int *b);

int main(void){
    int x =2;
    int y=3;
    swap(&x, &y);
    printf("%d,%d",x,y);
    



    return 0;
}
void swap (int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    printf("%p",*a);
    


}