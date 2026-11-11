#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int a1,a2,a3,a4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]==c[0] && a[1]==c[1]) a1=1;
    if((b[0]==d[0]) && (b[1]==d[1]) && a1) a2=1;
    else if((b[2]=='D' || b[2]=='F' && d[2]=='D' || d[2]=='F' )&& a1==1 && a2==1) a3=1;
    else if((b[2]=='A' || b[2]=='B' || b[2]=='C' && d[2]=='A' || d[2]=='B' || d[2]=='C') && a1==1 && a2==1) a3=1;
    else if(b[2]=='A' && a1 && a2 && a3)
    {
        if(d[2]=='B') a4=1;
    }
    else if(b[2]=='B' && a1&& a2 && a3)
    {
        if(d[2]=='A' || d[2]=='C') a4=1;
    }
    else if(b[2]=='C' && a1&& a2 && a3)
    {
        if(d[2]=='B') a4==1;
    }
    else if(b[2]=='D' && a1&& a2 && a3)
    {
        if(d[2]=='F') a4=1;
    }
    else if(b[2]=='F' && a1&& a2 && a3)
    {
        if(d[2]=='D') a4=1;
    }
    cout<<a1<<a2<<a3<<a4;
    return 0;
}
