#include<bits/stdc++.h>
using namespace std;
#define int long long
string x1,y12,x2,y2;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>x1>>y12>>x2>>y2;
    for(int i=0;i<2;i++)
    {
        if(x1[i]!=x2[i])
        {
            cout<<"0000";
            return 0;
        }
    }
    cout<<"1";
    for(int i=0;i<2;i++)
    {
        if(y12[i]!=y2[i])
        {
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";
    if(y12[2]=='F'&&y2[2]=='D'||y12[2]=='D'&&y2[2]=='F')
    {
        cout<<"11";
        return 0;
    }
    if(y12[2]=='F'||y2[2]=='F'||y12[2]=='D'||y2[2]=='D')
    {
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(y12[2]=='A'&&y2[2]=='C'||y12[2]=='C'&&y2[2]=='A')
    {
        cout<<"0";
        return 0;
    }
    cout<<"1";
    return 0;
}
