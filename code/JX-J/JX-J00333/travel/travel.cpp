#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long n=0,m=0,o=0,p=0;
char x,y;
bool che(int x,int y)
{
    if(x==y)
    {
        return 1;
    }
    return 0;
}
bool lei(int x,int y)
{
    if(x==y)
    {
        return 1;
    }
    return 0;
}
bool qu(char x,char y,int z1,int z2)
{
    if(z1!=z2)
    {
        return 0;
    }
    if(x<='C'&&y<='C')
    {
        return 1;
    }
    if(x>'C'&&y>'C')
    {
        return 1;
    }
    return 0;
}
bool lie(char x,char y)
{
    if(x=='C'&&y=='D')
    {
        return 0;
    }
    if(char(x+1)==y)
    {
        return 1;
    }
    if(x=='D'&&y=='F')
    {
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    for(int i=0;i<a.size();i++)
    {
        n*=10;
        n+=int(a[i]-'0');
    }
    for(int i=0;i<c.size();i++)
    {
        m*=10;
        m+=int(c[i]-'0');
    }
    for(int i=0;i<b.size();i++)
    {
        if(b[i]>='0'&&b[i]<='9')
        {
            o*=10;
            o+=int(b[i]-'0');
        }
        else
        {
            x=b[i];
        }
    }
    for(int i=0;i<d.size();i++)
    {
        if(d[i]>='0'&&d[i]<='9')
        {
            p*=10;
            p+=int(d[i]-'0');
        }
        else
        {
            y=d[i];
        }
    }
    if(che(n,m)==0)
    {
        cout<<"0000";
    }
    else
    {
        cout<<"1";
        if(lei(o,p))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        if(qu(x,y,o,p))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        if(lie(x,y))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}
