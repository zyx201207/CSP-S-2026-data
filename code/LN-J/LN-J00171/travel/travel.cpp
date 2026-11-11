#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string sx,sy,sxx,syy;
    cin>>sx>>sy>>sxx>>syy;
    for(int i=0;i<2;i++)
    {
        int m=sx[i]-'0';
        int n=sxx[i]-'0';
        if(m!=n)
        {
            cout<<"0000";
            return 0;
        }
    }
    cout<<"1";
    for(int i=0;i<2;i++)
    {
        int m=sy[i]-'0';
        int n=syy[i]-'0';
        if(m!=n)
        {
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";
    char c=sy[2];
    char ch=syy[2];
    if(((c=='A'||c=='B'||c=='C')&&(ch=='A'||ch=='B'||ch=='C'))||((c=='D'||c=='F')&&(ch=='D'||ch=='F')))
    {
        cout<<"1";
    }
    else
    {
        cout<<"00"
        return 0;
    }
    if(c=='A'&&ch=='B')
    {
        cout<<"1";
    }
    else if(c=='B'&&ch=='A')
    {
        cout<<"1";
    }
    else if(c=='B'&&ch=='C')
    {
        cout<<"1";
    }
    else if(c=='C'&&ch=='B')
    {
        cout<<"1";
    }
    else if(c=='D'&&ch=='F')
    {
        cout<<"1";
    }
    else if(c=='F'&&ch=='D')
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
