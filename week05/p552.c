#include <stdio.h>

int main(){
    FILE *fp = fopen("mystory.txt", "w+");
    FILE *fa = fopen("mystory.txt", "a");
    FILE * fr = fopen("mystroy.txt","rt");

    fputs("#이름:윤성우\n", fp);
    fputs("#주민번호:900208-1012589\n", fp);
    fputs("#전화번호:010-1111-2222\n", fp);
    fclose(fp);

    fputs("#즐겨먹는 음식: 짬뽕, 탕수육\n", fa);
    fputs("#취미:축구\n", fa);
    fclose(fa);

   
    
    fclose(fr);

    char str[100];


    while(fgets(str,sizeof(str),fr)!=NULL)
        printf(str);
    fclose(fp);
    
    return 0;

   

    return 0;

}