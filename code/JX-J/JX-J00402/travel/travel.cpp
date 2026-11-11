#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
bool a()
{
    bool p=0;
    if(a2[2]=='A')
    {
        if(b2[2]=='B'||b2[2]=='C')
        {
            p=1;
        }
    }
    if(a2[2]=='B')
    {
        if(b2[2]=='A'||b2[2]=='C')
        {
            p=1;
        }
    }
    if(a2[2]=='C')
    {
        if(b2[2]=='A'||b2[2]=='B')
        {
            p=1;
        }
    }
    if(a2[2]=='D')
    {
        if(b2[2]=='E')
        {
            p=1;
        }
    }
    if(a2[2]=='E')
    {
        if(b2[2]=='D')
        {
            p=1;
        }
    }
    return p;
}
bool b()
{
    bool p=0;
    if(a2[2]=='A')
    {
        if(b2[2]=='B')
        {
            p=1;
        }
    }
    if(a2[2]=='B')
    {
        if(b2[2]=='A'||b2[2]=='C')
        {
            p=1;
        }
    }
    if(a2[2]=='C')
    {
        if(b2[2]=='B')
        {
            p=1;
        }
    }
    if(a2[2]=='D')
    {
        if(b2[2]=='E')
        {
            p=1;
        }
    }
    if(a2[2]=='E')
    {
        if(b2[2]=='D')
        {
            p=1;
        }
    }
    return p;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    bool q=((a1==b1)?(1):(0));
    bool w=(((a2[1]==b2[1])&&(a2[0]==b2[0]))?(1):(0));
    cout<<q<<(w&&q)<<(a()&&w&&q)<<(b()&&a()&&w&&q);
    return 0;
}
