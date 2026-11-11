#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)
        cout<<1;
    else
        cout<<0;
    int b1=b[0]-'0',b2=b[1]-'0',d1=d[0]-'0',d2=d[1]-'0';
    int bn=b1*10+b2,dn=d1*10+d2;
    if(bn==dn)
        cout<<1;
    else
        cout<<0;
    if(b[2]=='A'||b[2]=='B'||b[2]=='C')
    {
        if(d[2]=='A'||d[2]=='B'||d[2]=='C')
        {
            cout<<1;
        }
        else
        {
            cout<<0
        }
    }
    else
    {
        if(d[2]=='D'||d[2]=='F')
            cout<<1;
        else
            cout<<0;
    }
    if(bn==dn)
    {
        if(b[2]=='A')
        {
            if(d[2]=='B'||d[2]=='C')
                cout<<1;
            else
                cout<<0;
            return 0;
        }
        if(b[2]=='B')
        {
            if(d[2]=='A'||d[2]=='C')
                cout<<1;
            else
                cout<<0;
            return 0;
        }
        if(b[2]=='C')
        {
            if(d[2]=='B'||d[2]=='A')
                cout<<1;
            else
                cout<<0;
            return 0;
        }
        if(b[2]=='D')
        {
            if(d[2]=='F')
                cout<<1;
            else
                cout<<0;
            return 0;
        }
        if(b[2]=='F')
        {
            if(d[2]=='D')
                cout<<1;
            else
                cout<<0;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
