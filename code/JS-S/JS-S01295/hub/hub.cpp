#include<bits/stdc++.h>
#define int long long
using namespace std;
int number,T,n,k;
vector<int> g[4005];
int dep[4005],md[4005];
void dfs(int u,int fa)
{
    dep[u]=md[u]=dep[fa]+1;
    for(int v:g[u])
        if(v!=fa)
        {
            dfs(v,u);
            md[u]=max(md[u],md[v]);
        }
    return;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>number>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        int l=0,r=n,mid;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(!solve(mid))l=mid+1;
            else r=mid;
        }
        cout<<l<<'\n';
    }
    return 0;
}
