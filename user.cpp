#include <stdio.h>

int main(void){
    FILE * fp = NULL;
    int n;

    //Mở file bằng hàm fopen_s 
    fp = fopen("C:\\Users\\Chi Bao\\Desktop\\dulieu.txt","r");
    fscanf(fp,"%d",&n);
    printf("%d",n);
    return 0;
}
