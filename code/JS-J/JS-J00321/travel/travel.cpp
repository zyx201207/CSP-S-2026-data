#include<bits/stdc++.h>
using namespace std;
int f[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    string k1="0000",k2="1000",k3="1100",k4="1110",k5="1111";
    int a1;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1])
    {
        cout<<k1;
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<k2;
        return 0;
    }
    if(s1[2]>='D'&&s2[2]<='C'||s1[2]<='C'&&s2[2]>='D')
    {
        cout<<k3;
        return 0;
    }
    if(s1[2]-s2[2]!=1&&s2[2]-s1[2]!=1)
    {
        cout<<k4;
        return 0;
    }
    if(s1[2]!='C'&&s2[2]!='D'||s2[2]!='C'&&s1[2]!='D')
    {
        cout<<k5;
        return 0;
    }
    return 0;
}
