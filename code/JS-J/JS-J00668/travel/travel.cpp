#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b; char s[5],t[5];
    scanf("%d%s%d%s",&a,s,&b,t);
    if(a!=b) puts("0000");
    else if(s[0]!=t[0] || s[1]!=t[1]) puts("1000");
    else if((s[2]<='C')!=(t[2]<='C')) puts("1100");
    else if(abs(s[2]-t[2])!=1 && s[2]<='C') puts("1110");
    else puts("1111");
    return 0;
}
