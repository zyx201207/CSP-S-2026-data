#include <bits/stdc++.h>
using namespace std;
vector <int> mp[2000005];
int dep[100005],fa[100005][25];
void dfs(int u,int pa)
{
    dep[u]=dep[pa]+1;
    fa[u][0]=pa;
    for(int i=1;i<=20;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v:mp[u])
        if(v!=pa)
            dfs(v,u);
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])
        swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;i<=20;i++)
    {
        if(d&1)
            u=fa[u][i];
        d>>=1;
    }
    if(u==v)
        return u;
    for(int i=20;i>=0;i--)
    {
        if(fa[u][i]==fa[v][i])
            continue;
        u=fa[u][i];
        v=fa[v][i];
    }
    return fa[u][0];
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        vector <pair<int,int>> s;
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            s.push_back({u,v});
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        dfs(1,0);
        int ans=1e9;
        for(int i=0;i<(1<<n);i++)
        {
            if(__builtin_popcount(i)!=k)
                continue;
            int cnt=k;
            for(pair<int,int> tmp:s)
            {
                int u=tmp.first,v=tmp.second;
                if((i&(1<<(u-1)))&&(i&(1<<(v-1))))
                    cnt--;
            }
            if(cnt>2)
                continue;
            int res=-1e9;
            for(int j=1;j<=n;j++)
            {
                int d=1e9;
                for(int u=1;u<=n;u++)
                    if(i&(1<<(u-1)))
                        d=min(d,dep[j]+dep[u]-2*dep[lca(j,u)]);
                res=max(res,d);
            }
            ans=min(ans,res);
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            mp[i].clear();
    }
    return 0;
}
