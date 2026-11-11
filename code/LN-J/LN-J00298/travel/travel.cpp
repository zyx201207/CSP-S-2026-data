#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="";
char a()
{
    if(c1==c2)
    {
        return '1';
    }
    else
    {
        return'0';
    }
}
char b()
{
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&a()=='1')
    {
        return '1';
    }
    else
    {
        return '0';
    }
}
char c()
{
    if((abs(s1[2]-s2[2])==1 || abs(s1[2]-s2[2])==2) && b()=='1')
    {
        if((s1[2]=='C' && s2[2]=='D')||(s1[2]=='D' && s2[2]=='D'))
        {
            return '0';
        }
        return '1';
    }
    else
    {
        return '0';
    }
}
char d()
{
    if(c()=='1' && abs(s1[2]-s2[2])==1)
    {
        return '1';
    }
    else
    {
        if((s1[2]=='D' && s2[2]=='F')||(s1[2]=='F' && s2[2]=='D'))
        {
            return '1';
        }
        return '0';
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    ans+=a();
    ans+=b();
    ans+=c();
    ans+=d();
    cout<<ans;
    return 0;
}
