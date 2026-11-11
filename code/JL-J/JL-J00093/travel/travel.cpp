#include <bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int main(){
    freopen("trevel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",a+1,b+1,c+1,d+1);
    if(a[1]==c[1]&&a[2]==c[2]){
        printf("1");
        if(b[1]==d[1]&&b[2]==d[2]){
            printf("1");
            int x=b[3]-'A';
            int y=d[3]-'A';
            if (x==2&&y==3||y==2&&x==3)
                printf("00");
            else{
                printf("1");
                    if((x==0&&y==2)||(x==2&&y==0))
                        printf("0");
                    else
                        printf("1");
            }
        }
        else
            printf("000");
    }
    else
        printf("0000");
}
