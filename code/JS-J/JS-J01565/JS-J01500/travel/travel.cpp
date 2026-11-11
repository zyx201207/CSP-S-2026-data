#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
int n=0,m=0;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
        if(b[0]==d[0] && b[1]==d[1])
        {
            cout<<1;
            if(b[2]=='A' || b[2]=='B' || b[2]=='C') n=1;
            if(d[2]=='A' || d[2]=='B' || d[2]=='C') m=1;
            if(n==m)
            {
                cout<<1;
                if(n==0) cout<<1;
                else
                {
                    if(b[2]=='A' && d[2]=='C' || b[2]=='C' && d[2]=='A') cout<<0;
                    else cout<<1;
                }
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
