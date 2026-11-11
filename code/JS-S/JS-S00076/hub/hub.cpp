#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,m;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i = 1;i < n;i++)
        {
            int u,v;
            cin>>u>>v;
        }
        m = (n - 1) / 2;
        if(k == n) cout<<0<<'\n';
        else if(k >= m) cout<<1<<'\n';
        else cout<<(m + 2 - k + 5) / 4<<'\n';
    }
    return 0;
}
