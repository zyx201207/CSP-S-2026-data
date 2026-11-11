#include<bits/stdc++.h>
using namespace std;
char a[100],b[100],c[100],d[100];
int x,y,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",a,b,c,d);
    for(int i=0;i<2;i++){
        x=x*10;
        x+=a[i]-'0';
        y=y*10;
        y+=c[i]-'0';
    }
    for(int i=0;i<2;i++){
        e=e*10;
        f=f*10;
        e+=b[i]-'0';
        f+=d[i]-'0';
    }
    if(x==y){
        printf("1");
    }
    else{
        printf("0");
    }
    if(e==f and x==y){
        printf("1");
    }
    else{
        printf("0");
    }
    if(e==f and x==y and b[2]<'D' and d[2]<'D'){
        printf("1");
    }
    else if(e==f and x==y and b[2]>='D' and d[2]>='D'){
        printf("1");
    }
    else{
        printf("0");
    }
    if(e==f and x==y and b[2]<'D' and d[2]<'D' and abs(b[2]-d[2])==1){
        printf("1");
    }
    else if(e==f and x==y and b[2]>='D' and d[2]>='D' and abs(b[2]-d[2])==1){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}
