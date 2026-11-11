#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2;
    string b1,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(b1[0]==b2[0]&&b1[1]==b2[1]) cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(b1[2]>='A'&&b1[2]<='C'&&(b2[2]>='A'&&b2[2]<='C')) cout<<1;
    else if(b1[2]>='D'&&b1[2]<='F'&&(b2[2]>='D'&&b2[2]<='F')) cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(abs(b1[2]-b2[2])==1&&(b1[2]!='C'&&b2[2]!='D')) cout<<1;
    else
    {
        cout<<"0";
        return 0;
    }
    return 0;
}
