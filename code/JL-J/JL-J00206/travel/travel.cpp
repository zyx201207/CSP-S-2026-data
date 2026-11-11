#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int a,b;
    string a1,b1;
    cin>>a>>a1>>b>>b1;
    bool flag=false;
    if((a1[2]-64<=3&&b1[2]-64<=3)||(a1[2]-64>3&&b1[2]-64>3)) flag=true;
    printf("%d %d %d %d",a==b,a==b&&b1[1]==a1[1],a==b&&b1[1]==a1[1]&&flag,a==b&&max(a1[2]-64,b1[2]-64)-min(a1[2]-64,b1[2]-64)<=1&&flag);
    return 0;
}
