#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag;
int ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        flag=true;
        cout<<1;
    }
    else
    {
        flag=false;
        cout<<0;
    }
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=s2[i])
        {
            flag=false;
        }
    }
    if(flag==false)cout<<0;
    else cout<<1;
    if(flag==true && ((s1[2]<='C' && s2[2]<='C')|| (s1[2]>='D' && s2[2]>='D')))
    {
        flag=true;
        cout<<1;
    }
    else
    {
        flag=false;
        cout<<0;
    }
    if(flag==true && ((s1[2]=='B' || s2[2]=='B') || (s1[2]=='D' || s2[2]=='D')))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
