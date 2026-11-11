#include<bits/stdc++.h>
using namespace std;
char rzuo,xzuo;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    int rpai=0,xpai=0;
    rpai=(s1[0]-'0')*10+(s1[1]-'0');
    xpai=(s2[0]-'0')*10+(s2[1]-'0');
    rzuo=s1[2];
    xzuo=s2[2];
    if(xpai==rpai)
    {
        cout<<1;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if(rzuo=='A')
    {
        if(xzuo=='B'||xzuo=='C')
        {
            cout<<1;
        }
        else
        {
            cout<<0<<0;
            return 0;
        }
    }
    else if(rzuo=='B')
    {
        if(xzuo=='A'||xzuo=='C')
        {
            cout<<1;
        }
        else
        {
            cout<<0<<0;
            return 0;
        }
    }
    else if(rzuo=='C')
    {
        if(xzuo=='B'||xzuo=='A')
        {
            cout<<1;
        }
        else
        {
            cout<<0<<0;
            return 0;
        }
    }
    else if(rzuo=='D')
    {
        if(xzuo=='E')
        {
            cout<<1;
        }
        else
        {
            cout<<0<<0;
            return 0;
        }
    }
    else if(rzuo=='E')
    {
        if(xzuo=='D')
        {
            cout<<1;
        }
        else
        {
            cout<<0<<0;
            return 0;
        }
    }
    if(rzuo=='A')
    {

        if(xzuo=='B')
        {
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else if(rzuo=='B'){
        if(rzuo=='B')
        {
            if(xzuo=='A'||xzuo=='C')
            {
                cout<<1;
                return 0;
            }
            else{
                cout<<0;
                return 0;
            }
        }
    }
    else if(rzuo=='C')
    {
        if(xzuo=='B')
        {
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else if(rzuo=='D')
    {
        if(xzuo=='E')
        {
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else{
        if(xzuo=='D')
        {
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    return 0;
}
