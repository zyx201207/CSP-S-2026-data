#include <bits/stdc++.h>
using namespace std;
string a,b;
string c,d;
bool up1,up2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if (a[0]==b[0]&&a[1]==b[1])
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if (c[0]==d[0]&&c[1]==d[1])
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if (c[2]=='D'||c[2]=='F')
    {
        up1=1;
    }
    else
    {
        up1=0;
    }
    if (d[2]=='D'||d[2]=='F')
    {
        up2=1;
    }
    else
    {
        up2=0;
    }
    if (up1==up2)
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if (c[2]=='A'&&d[2]=='C')
    {
        cout<<0;return 0;
    }
    else if(c[2]=='C'&&d[2]=='A')
    {
        cout<<0;return 0;
    }
    else
    {
        cout<<1;return 0;
    }
    return 0;
}
