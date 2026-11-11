#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%2d %2d%c %2d %2d%c",&a,&b,&x,&c,&d,&y);
    if(a!=c){
        printf("0000");
        return 0;
    }
    printf("1");
    if(b!=d){
        printf("000");
        return 0;
    }
    printf("1");
    if(x<='C'&&y<='C'||x>='D'&&y>='D'){
        printf("1");
        if(x<='C'&&y<='C'){
            if(x-y==1||y-x==1) printf("1");
            else printf("0");
        }
        else printf("1");
    }
    else printf("00");
}
