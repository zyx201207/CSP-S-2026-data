#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    cin>>a>>b>>e>>c>>d>>f;
    if(a!=c)
    {
    cout<<"0000";
    return 0;
    }
    else
    cout<<1;
    if(b!=d)
    {
    cout<<"000";
    }
    if(b==d)
    {
    cout<<1;
    if(e=='A')
    {
        if(f=='B')
        cout<<"11";
        if(f=='C')
        cout<<"10";
        if(f=='D'||f=='F')
        cout<<"00";
    }
    if(e=='B')
    {
        if(f=='A'||f=='C')
        cout<<"11";
        if(f=='D'||f=='F')
        cout<<"00";
    }
    if(e=='C')
    {
        if(f=='B')
        cout<<"11";
        if(f=='A')
        cout<<"10";
        if(f=='D'||f=='F')
        cout<<"00";
    }
    if(e=='D')
    {
        if(f=='A'||f=='B'||f=='C')
        cout<<"00";
        if(f=='F')
        cout<<"11";
    }
    if(e=='F')
    {

        if(f=='A'||f=='B'||f=='C')
        cout<<"00";
        if(f=='D')
        cout<<"11";
    }
    }
    if(b!=d)
    return 0;
}
