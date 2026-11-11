#include<bits/stdc++.h>
using namespace std;
bool f;
int rc,xc;
string r,x;
int pd1()
{
    if(rc!=xc || (rc==1 || rc==16 || xc==1 || xc==16))
    {
        f=1;
        return 0;
    }
    int a=r[0]-0,s=x[0]-0;
    a*=10,s*=10;
    a+=r[1]-0,s+=x[1]-0;
    if(a>18 || s>18)
    {
        f=1;
        return 0;
    }
    bool o=0,u=0;
    for(char i='A';i<='F';i++)
    {
        if(r[2]==i) o=1;
        if(x[2]==i) u=1;
    }
    if(u!=1 || o!=1)
    {
        f=1;
        return 0;
    }
    return 1;
}
int pd2()
{
    if(f==1) return 0;
    int a=r[0]-0,s=x[0]-0;
    a*=10,s*=10;
    a+=r[1]-0,s+=x[1]-0;
    if(a!=s)
    {
        f=1;
        return 0;
    }
    return 1;
}
int pd3()
{
    bool g=0,h=0;
    if(f==1) return 0;
    for(char i='A';i<='C';i++)
    {
        if(r[2]==i) g=1;
        if(x[2]==i) h=1;
    }
    if(g!=h)
    {
        f=1;
        return 0;
    }
    return 1;
}
int pd4()
{
    if(f==1) return 0;
    if(r[2]-x[2]==1 || x[2]-r[2]==1) return 1;
    return 0;
}
int main()
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>rc>>r>>xc>>x;
    cout<<pd1()<<pd2()<<pd3()<<pd4();
    return 0;
}
