#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > z[505];
vector<int> xl[500005];
int w[500005],vis[500005];
int c,n,m,d,q,mnans;
void dfs(int u,int v,int x,int ans)
{
    if(u==v)
    {
        mnans=min(mnans,ans);
        return;
    }
    if(ans>=vis[u]) return;
    vis[u]=ans;
    //cout<<u<<' '<<x<<' '<<ans<<'\n';
    for(auto zz:xl[u])
    {
        int ansi=ans;
        for(int i=0;i<z[zz].size();i++)
        {
            if(z[zz][i].first==u)
            {
                ansi+=z[zz][i].second;
                break;
            }
        }
        for(int i=0;i<z[zz].size();i++)
        {
            if(z[zz][i].first==u) continue;
            //cout<<z[zz][i].first<<' '<<v<<' '<<zz<<' '<<ansi+z[zz][i].second<<'\n';
            dfs(z[zz][i].first,v,zz,ansi+z[zz][i].second);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int ai,bi;
            cin>>ai>>bi;
            xl[ai].push_back(i);
            z[i].push_back(make_pair(ai,bi));
        }
    }
    for(int i=1;i<=q;i++)
    {
        memset(vis,0x7f,sizeof(vis));
        mnans=INT_MAX;
        int u,v;
        cin>>u>>v;
        dfs(u,v,-1,w[u]);
        mnans+=w[v];
        cout<<mnans<<'\n';
    }
    return 0;
}
