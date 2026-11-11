#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    int t1=0,t2=0;
    for(int i=0;i<s1.length()-1;i++)
    {
        t1*=10;
        t1+=(s1[i]-'0');
        t2*=10;
        t2+=(s2[i]-'0');
    }
    if(t1!=t2)
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(!((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')))
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(!((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&abs(s1[2]-s2[2])==1)||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&abs(s1[2]-s2[2])==2)))
    {
        cout<<"0";
        return 0;
    }
    cout<<1;
    return 0;
}
