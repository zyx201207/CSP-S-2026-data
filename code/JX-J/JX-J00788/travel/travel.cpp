#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool a,b,c,d;
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1)a=1;
    else a=0;
    if(r2[0]==x2[0]&&x2[1]==r2[1]&&a==1)b=1;
    else b=0;
    if(((r2[2]<='C'&&r2[2]>='A'&&x2[2]>='A'&&x2[2]<='C')||(r2[2]<='F'&&r2[2]>='E'&&x2[2]<='F'&&x2[2]>='E'))&&b==1)c=1;
    else c=0;
    if(c==1&&abs(r2[2]-x2[2])==1)d=1;
    else d=0;
    cout<<a<<b<<c<<d;
    return 0;
}
