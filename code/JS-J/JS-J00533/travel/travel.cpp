#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y,k,l;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    x=((int)a[0]-'0')*10+((int)a[1]-'0');
    y=((int)c[0]-'0')*10+((int)c[1]-'0');
    if(x==y)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    k=((int)b[0]-'0')*10+((int)b[1]-'0');
    l=((int)d[0]-'0')*10+((int)d[1]-'0');
    if(l==k)cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(b[b.size()-1]=='A')
    {
        if(d[d.size()-1]=='B')
        {
            cout<<11;
            return 0;
        }
        if(d[d.size()-1]=='C')
        {
            cout<<10;
            return 0;
        }
        if(d[d.size()-1]=='D'||d[d.size()-1]=='F')
        {
            cout<<"00";
            return 0;
        }
    }
    if(b[b.size()-1]=='B')
    {
        if(d[d.size()-1]=='A'||d[d.size()-1]=='C')
        {
            cout<<11;
            return 0;
        }
        if(d[d.size()-1]=='D'||d[d.size()-1]=='F')
        {
            cout<<"00";
            return 0;
        }
    }
    if(b[b.size()-1]=='C')
    {
        if(d[d.size()-1]=='B')
        {
            cout<<11;
            return 0;
        }
        if(d[d.size()-1]=='A')
        {
            cout<<10;
            return 0;
        }
        if(d[d.size()-1]=='D'||d[d.size()-1]=='F')
        {
            cout<<"00";
            return 0;
        }
    }
    if(b[b.size()-1]=='D')
    {
        if(d[d.size()-1]=='A'||d[d.size()-1]=='C'||d[d.size()-1]=='B')
        {
            cout<<"00";
            return 0;
        }
        if(d[d.size()-1]=='F')
        {
            cout<<11;
            return 0;
        }
    }
    if(b[b.size()-1]=='F')
    {
        if(d[d.size()-1]=='A'||d[d.size()-1]=='C'||d[d.size()-1]=='B')
        {
            cout<<"00";
            return 0;
        }
        if(d[d.size()-1]=='D')
        {
            cout<<11;
            return 0;
        }
    }
}
