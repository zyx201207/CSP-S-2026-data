#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ca,cb,sa,sb;
    cin>>ca>>sa>>cb>>sb;
    if(ca==cb)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(sa[0]==sb[0]&&sa[1]==sb[1])
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    int a=-1,b=-1;
    if(sa[2]<='C')
        a=0;
    else
        a=1;
    if(sb[2]<='C')
        b=0;
    else
        b=1;
    if(a==b&&a!=-1)
        cout<<"1";
    else
    {
        cout<<"00";
        return 0;
    }
    if(a==1)
    {
        cout<<"1";
        return 0;
    }
    else if(abs(sa[2]-sb[2])==1)
    {
        cout<<"1";
        return 0;
    }
    else
        cout<<"0";
    return 0;}
