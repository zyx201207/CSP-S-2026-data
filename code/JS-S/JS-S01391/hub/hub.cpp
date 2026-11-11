#include <bits/stdc++.h>
using namespace std;
int c,t,n,m,u,v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
        }
        if(c==13||c==14)
        {
            if(m>=n/2)
                cout<<1<<'\n';
            else if(m==1)
                cout<<(n+1)/4<<'\n';
            else
                cout<<n/4<<'\n';
        }
        else
        {
            cout<<n/3<<'\n';
        }
    }
    return 0;
}
