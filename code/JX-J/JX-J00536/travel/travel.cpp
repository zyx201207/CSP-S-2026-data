#include <iostream>
#include <cstdio>
using namespace std;
int abs(int a)
{
    if(a<0)
    {
        return -a;
    }
    return a;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rs,xc,xs;
    cin>>rc>>rs>>xc>>xs;
    if(rc==xc)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if((rc==xc)&&(rs[0]==xs[0])&&(rs[1]==xs[1]))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    bool r=((rs[2]=='A')||(rs[2]=='B')||(rs[2]=='C'));//true is left
    bool x=((xs[2]=='A')||(xs[2]=='B')||(xs[2]=='C'));
    if((rc==xc)&&(rs[0]==xs[0])&&(rs[1]==xs[1])&&(r==x))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if((rc==xc)&&(rs[0]==xs[0])&&(rs[1]==xs[1])&&(r==x)&&(abs(rs[2]-xs[2])==1))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}