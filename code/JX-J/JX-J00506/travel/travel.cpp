#include <bits/stdc++.h>
using namespace std;
int a1,a2;
string b1,b2;
int p1,p2;
char z1,z2;
bool flag=true;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    p1=(b1[0]-'0')*10+b1[1]-'0';
    z1=b1[2];
    p2=(b2[0]-'0')*10+b2[1]-'0';
    z2=b2[2];
    if (a1!=a2)flag=false;
    cout<<(int)flag;
    if (p1!=p2)flag=false;
    cout<<(int)flag;
    if ((z1<='C' && z2>='D') || (z1>='D' && z2<='C'))flag=false;
    cout<<(int)flag;
    if ((z1=='A' && z2=='C') || (z1=='C' && z2=='A'))flag=false;
    cout<<(int)flag;
    cout<<'\n';
    return 0;
}
