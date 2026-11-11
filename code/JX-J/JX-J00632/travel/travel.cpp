#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2;
    bool tongche=false;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        tongche=true;
    }
    else
    {
        cout<<0;
    }
    bool tongpai=false;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&tongche)
    {
        tongpai=true;
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&tongche&&s2[2]<='C'&&tongpai)
    {
        cout<<1;
    }
    else if(s1[2]=='D'&& s2[2]=='F'&&tongpai&&tongche)
    {
        cout<<1;
    }
    else if(s1[2]=='F'&& s2[2]=='D'&&tongpai&&tongche)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(s1[2]>'C'&&s2[2]<='C'&&tongpai&&tongche)
    {
        cout<<0;
    }
    else if(s1[2]<='C'&&s2[2]>'C'&&tongpai&&tongche)
    {
        cout<<0;
    }
    else if(s1[2]=='D'&&s2[2]=='F'&&tongpai&&tongche)
    {
        cout<<1;
    }
    else if(s1[2]=='F'&&s2[2]=='D'&&tongpai&&tongche)
    {
        cout<<1;
    }
    else if((s1[2]-s2[2]==1 || s1[2]-s2[2]==-1)&&tongpai&&tongche)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}