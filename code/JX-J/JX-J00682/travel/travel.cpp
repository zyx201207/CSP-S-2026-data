#include<bits/stdc++.h>
using namespace std;
string s1,s2,x1,x2;
int s,x;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>x1>>x2;
    if(s1==x1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s2[0]==x2[0]&&s2[1]==x2[1])
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
    {
        s=1;
    }
    else
    {
        s=2;
    }
    if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C')
    {
        x=1;
    }
    else
    {
        x=2;
    }
    if(s==x)
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(s==2)
    {
        cout<<"1";
        return 0;
    }
    else
    {
        if(s2[2]=='A'&&x2[2]=='B'||s2[2]=='B'&&x2[2]=='C'||s2[2]=='B'&&x2[2]=='A'||s2[2]=='C'&&x2[2]=='B')
        {
            cout<<"1";
            return 0;
        }
        else
        {
            cout<<"0";
            return 0;
        }
    }
    return 0;
}
