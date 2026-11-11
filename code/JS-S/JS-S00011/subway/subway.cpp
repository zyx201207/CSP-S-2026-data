#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
ll w[500005],e[1005][1005];
struct pl{
    int no;
    ll t;
}a[405];
vector<int>g[1005];
ll dfs(int fa,int G,int E)
{
    ll res=1e18;
    for(int i=0;i<g[G].size();i++)
    {
        if(g[G][i]==E)
            res=min(res,e[g[G][i]][G]);
        else if(g[G][i]!=fa)
            res=min(res,e[g[G][i]][G]+dfs(G,g[G][i],E));
    }
    return res;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    int tp;
    memset(e,127,sizeof(e));
    for(int i=1;i<=n;i++)
    {
        cin>>tp;
        for(int j=1;j<=tp;j++)
        {
            cin>>a[j].no>>a[j].t;
            for(int k=1;k<j;k++)
            {
                g[a[j].no].push_back(a[k].no);
                g[a[k].no].push_back(a[j].no);
                e[a[k].no][a[j].no]=min(a[k].t+a[j].t,e[a[k].no][a[j].no]);
                e[a[j].no][a[k].no]=e[a[k].no][a[j].no];
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dfs(x,x,y)<<'\n';
    }
    return 0;
}
