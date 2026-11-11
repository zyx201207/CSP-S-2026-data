#include<bits/stdc++.h>
using namespace std;
int a,b,_c,_d;
char c[5],d[5],e[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    _c=c[2]-'A';
    _d=d[2]-'A';
    if(a==b)
        e[0]='1';
    else
        e[0]='0';
    if (a==b && c[0]==d[0] && c[1]==d[1])
        e[1]='1';
    else
        e[1]='0';
    if (a==b && c[0]==d[0] && c[1]==d[1] && ((_c<=2 && _d<=2) || (_c>=3 && _d>=3)))
        e[2]='1';
    else
        e[2]='0';
    if (a==b && c[0]==d[0] && c[1]==d[1] && (!(_c==2 && _d==3) && abs(_c-_d)==1))
        e[3]='1';
    else
        e[3]='0';
    cout<<e[0]<<e[1]<<e[2]<<e[3];
    return 0;
}
