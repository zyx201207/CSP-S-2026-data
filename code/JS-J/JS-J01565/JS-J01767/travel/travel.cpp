#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a!=x)
    {
        cout<<"0000";
        return 0;
    }
    if(!(b[0]==y[0]&&b[1]==y[1]))
    {
        cout<<"1000";
        return 0;
    }
    if(int(b[2])<=67&&int(y[2])<=67)
        ;
    else if(int(b[2])>=68&&int(y[2])>=68)
    {
        cout<<"1111";
        return 0;
    }
    else
    {
        cout<<"1100";
        return 0;
    }
    if((b[2]=='A'&&y[2]=='C')||(b[2]=='C'&&y[2]=='A'))
    {
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
//
