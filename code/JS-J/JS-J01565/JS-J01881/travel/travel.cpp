#include<bits/stdc++.h>
using namespace std;
inline bool is_l(const char &c){return c=='A'||c=='B'||c=='C';}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    char a[5],b[5];
    scanf("%d%s%d%s",&n,a+1,&m,b+1);
    if(n==m)printf("1");
    else{
        printf("0000");
        return 0;
    }if(a[1]==b[1]&&a[2]==b[2])printf("1");
    else{
        printf("000");
        return 0;
    }if(is_l(a[3])==is_l(b[3]))printf("1");
    else{
        printf("00");
        return 0;
    }printf((!is_l(a[3])||a[3]=='B'||b[3]=='B'?"1":"0"));
    return 0;
}