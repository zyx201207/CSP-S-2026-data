#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travl.in","r",stdin)
    freopen("travl.out","w",stdout)
    int a1,b1,a2,b2;
    string c1,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if(a1!=a2) cout<<0000;
    else if(b1!=b2) cout<<1000;
    else if(c1=="A")
    {
        if(c2=="B") cout<<1111;
        else if(c2=="C") cout<<1110;
        else cout<<1100;
    }
    else if(c1=="B")
    {
        if(c2=="A"&&c2=="C") cout<<1111;
        else cout<<1100;
    }
    else if(c1=="C")
    {
        if(c2=="B") cout<<1111;
        else if(c2=="A") cout<<1110;
        else cout<<1100;
    }
    else if(c1=="D")
    {
        if(c2=="F") cout<<1111;
        else cout<<1100;
    }
    else if(c1=="F")
    {
        if(c2=="D") cout<<1111;
        else cout<<1100;
    }
    return 0;
}
