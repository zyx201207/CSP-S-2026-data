

#include <bits/stdc++.h>
using namespace std;
bool f(char x,char y)
{
    if(x=='A'&&y=='B')
        return true;
    if(x=='B'&&y=='C')
        return true;
        if(x=='D'&&y=='F')
        return true;
        if(x=='B'&&y=='A')
        return true;
        if(x=='C'&&y=='B')
        return true;
        if(x=='F'&&y=='D')
        return true;
        return false;
}
int rc;
int xc;
char rz[5];
char xz[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc;
    for(int i=1;i<=3;i++)
    cin>>rz;
    cin>>a.xc;
     for(int i=1;i<=3;i++)
    cin>>xz;
    if(rc==xc)
        cout<<'1';
    else
        cout<<'0';
    if(rc==xc&&rz[1]-'0'==xz[1]-'0'&&rz[2]-'0'==xz[2]-'0')
        cout<<'1';
    else
        cout<<'0';
    if(rc==xc&&rz[1]-'0'==xz[1]-'0'&&rz[2]-'0'==xz[2]-'0'&&abs((rz[3]-'0')-(xz[3]-'0'))<=2)
        cout<<'1';
    else
        cout<<'0';
    if(rc==xc&&rz[1]-'0'==xz[1]-'0'&&rz[2]-'0'==xz[2]-'0'&&abs((rz[3]-'0')-(xz[3]-'0'))<=2&&f(rz,xz))
        cout<<'1';
    else
        cout<<'0';
}

