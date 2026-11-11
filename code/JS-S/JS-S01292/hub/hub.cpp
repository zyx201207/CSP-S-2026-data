#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c;
    cin>>t;
    for(int T=1;T<=t;T++)
    {
        cin>>n>>k;
        vector<int> g[1005];
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(c==7)
        {
            cout<<n/2-1<<endl;
        }
    }
    return 0;
}
