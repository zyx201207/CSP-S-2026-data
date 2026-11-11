#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a1,a2;
bool f[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    a1=s1[0]+s1[1],a2=s2[0]+s2[1];
    if(a1!=a2)
    {
        cout<<1000;
        return 0;
    }
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') f[3]=1;
    else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') f[3]=1;
    if(!f[3])
    {
        cout<<1100;
        return 0;
    }
    if(s1[2]>s2[2]) swap(s1,s2);
    if(s1[2]=='A'&&s2[2]=='B') f[4]=1;
    if(s1[2]=='B'&&s2[2]=='C') f[4]=1;
    if(s1[2]=='D'&&s2[2]=='F') f[4]=1;
    cout<<111<<f[4];
    return 0;
}
