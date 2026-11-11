#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>e[N];
int C,T,n,k,ans,p[N],d[N],f[N];
int dis(int x,int y)
{
    int res=0;
    if(d[x]<d[y])swap(x,y);
    while(d[f[x]]>=d[y])res++,x=f[x];
    if(x==y)return res;
    while(f[x]!=f[y])x=f[x],y=f[y],res+=2;
    return res+2;
}
void dfs(int t,int cnt)
{
    if(t>n)
    {
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i])continue;
            int tmp=1e9;
            for(int j=1;j<=n;j++)if(p[j])tmp=min(tmp,dis(i,j));
            res=max(res,tmp);
        }
        ans=min(ans,res);
        return;
    }
    if(n-t+1>k-cnt)p[t]=0,dfs(t+1,cnt);
    p[t]=1,dfs(t+1,cnt+1);
    return;
}
void DFS(int u,int fa)
{
    d[u]=d[fa]+1,f[u]=fa;
    for(int v:e[u])DFS(v,u);
    return;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--)
    {
        scanf("%d%d",&n,&k),ans=1e9;
        for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
        DFS(1,0);
        dfs(1,0);
        for(int i=1;i<=n;i++)e[i].clear();
    }
    return 0;
}