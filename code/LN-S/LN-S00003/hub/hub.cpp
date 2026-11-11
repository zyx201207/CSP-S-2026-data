#include<bits/stdc++.h>
using namespace std;
bool e[15][15];
int n,k;
int a[15];
int fa[15];
int dis[15];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
bool check()
{
    for(int i = 1;i <= k;i++)
        fa[a[i]]=a[i];
    for(int i = 1;i <= k;i++)
        for(int j = i+1;j <= k;j++)
            if(e[i][j]&&find(i)!=find(j))
                fa[find(i)]=find(j);
    sort(fa+1,fa+k+1);
    int cnt=0;
    for(int i = 1;i < k;i++)
        if(fa[i]!=fa[i+1])
            cnt++;
    return (cnt==2);
}
bool vis[15],vis1[15];
struct node
{
    int x,w;
};
bool operator<(node a,node b)
{
    return a.w>b.w;
}
int calc()
{
    priority_queue<node>pq;
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    for(int i = 1;i <= k;i++)
    {
        vis1[a[i]]=1;
        pq.push({a[i],0});
    }
    while(!pq.empty())
    {
        int x = pq.top().x,w=pq.top().w;
        pq.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(int i = 1;i <= n;i++)
        {
            if(dis[i]>dis[x]+1)
            {
                dis[i]=dis[x]+1;
                pq.push({x,dis[x]});
            }
        }
    }
    int ans=0;
    for(int i = 1;i <= n;i++)
        if(!vis1[i])
            ans=max(ans,dis[i]);
    return ans;
}
int ans=0;
void dfs(int step,int cnt)
{
    if(step>n)
    {
        if(cnt==k&&check())
            ans=min(ans,calc());
        return ;
    }
    dfs(step+1,cnt);
    a[cnt+1]=step;
    dfs(step+1,cnt+1);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i = 1,a,b;i < n;i++)
        {
            cin>>a>>b;
            e[a][b]=e[b][a]=1;
        }
        dfs(1,0);
        cout<<ans;
    }
    return 0;
}
