#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node
{
    int v,l,o,i;
};
vector<node> e[N];
int c,m,n,d,q,y,ans,w[N],dis[N];
bool vis[N];
void dfs(node x,int sum)
{
    int u=x.v,line=x.l;
    if (vis[u])
        return;
    if (u==y)
    {
        ans=min(ans,sum+x.o);
        return;
    }
    for (auto c:e[u])
    {
        if (c.l==line)
            dfs(c,sum);
        else
            dfs(c,sum+x.o+c.i);
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for (int i=1;i<=n;i++)
        cin>>w[i];
    for (int i=1;i<=m;i++)
    {
        int k,last=0,lastt;
        cin>>k;
        for (int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            if (last!=0)
            {
                e[a].push_back({last,i,t,lastt});
                e[last].push_back({a,i,lastt,t});
            }
            last=a;
            lastt=t;
        }
    }
    while (q--)
    {
        int x;
        cin>>x>>y;
        memset(vis,false,sizeof vis);
        ans=1e9;
        dfs({x,0,0,0},0);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}