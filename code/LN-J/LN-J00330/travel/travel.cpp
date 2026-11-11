#include <bits/stdc++.h>
using namespace std;

char x1[3],x2[3],a[4],b[4];
bool f=true;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    scanf("%s",x1+1);
    scanf("%s",a+1);
    scanf("%s",x2+1);
    scanf("%s",b+1);
    int xa=(x1[1]-'0') *10+x1[2]-'0';
    int xb=(x2[1]-'0') *10+x2[2]-'0';
    if(xa==xb){
        printf("1");
    }
    else {
        printf("0");
        f=false;
    }

    int s1=(a[1]-'0')*10+a[2]-'0';
    int s2=(b[1]-'0')*10+b[2]-'0';
    char c1=a[3], c2=b[3];
    if(f && s1==s2){
        printf("1");
        if((c1<='C'&&c2<='C') || (c1>='D'&&c2>='D')){
            printf("1");
        }
        else {
            printf("0");
            f=false;
        }
    }
    else {
        printf("00");
        f=false;
    }
    if(f && ( (c1==c2+1)||(c2==c1+1) ) ){
        printf("1");
    }
    else printf("0");
    return 0;
}
