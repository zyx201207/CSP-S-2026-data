#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    string t1=s1.substr(0,2),t2=s2.substr(0,2);
    if(t1==t2)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    char a1=s1[2],a2=s2[2];
    if(a1<='C'&&a2<='C')
    {
        cout<<'1';
    }
    else if(a1>='D'&&a2>='D')
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    if(a1<='C'&&a2<='C'&&abs(a1-a2)==1)
    {
        cout<<'1';
    }
    else if(a1>='D'&&a2>='D'&&abs(a1-a2)==1)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    return 0;
}
