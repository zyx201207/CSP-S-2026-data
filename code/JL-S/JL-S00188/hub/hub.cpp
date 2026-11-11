#include<bits/stdc++.h>
using namespace std;
vector<int>v[2200000];
int dis[1100][1100];
void dfs(int x,int fa,int id)
{
    for(auto y:v[x])
    {
        if(y==fa)continue;
        dis[id][y]=dis[id][x]+1;
        dfs(y,x,id);
    }
}
int pre[1100];
int fl;
int vis[1100];
void dfs1(int x,int fa,int to)
{
    if(x==to)
    {
        fl=1;
        return;
    }
    for(auto y:v[x])
    {
        if(y==fa)continue;
        pre[y]=x;
        dfs1(y,x,to);
        if(fl==1)
        {
            vis[x]=1;
            return;
        }
    }
}
int n,k;
int dp[1100];
int ff[1100];
void dfs2(int x)
{
    dp[x]=1;
    for(auto y:v[x])
    {
        if(vis[y]!=0)continue;
        vis[y]=2;
        ff[y]=x;
        dfs2(y);
        dp[x]=max(dp[x],dp[y]+1);
    }
}
priority_queue<pair<int,int> >q;
int solve(int x,int y)
{
    fl=0;
    for(int i=1;i<=n;i++)vis[i]=0;
    dfs1(x,-1,y);
    vis[x]=vis[y]=3;
    while(!q.empty())q.pop();
    for(auto i:v[x])
    {
        if(vis[i]==0)
        {
            ff[i]=x,vis[i]=2,dfs2(i),q.push(make_pair(dp[i],i));
        }
    }
    for(auto i:v[y])
    {
        if(vis[i]==0)
        {
            ff[i]=y,vis[i]=2,dfs2(i),q.push(make_pair(dp[i],i));
        }
    }
    int use=2;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=2&&vis[i]!=3)ans=max(ans,min(dis[i][x],dis[i][y]));
    }
    while(!q.empty()&&use<k)
    {
        int xx=q.top().second;
        q.pop();
        use++;
        for(auto yy:v[xx])
        {
            if(yy==ff[xx])continue;
            q.push(make_pair(dp[yy],yy));
        }
    }
    if(q.empty())return ans;
    return max(ans,q.top().first);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdin);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(n<=1000)
        {
            for(int i=1;i<=n;i++)v[i].clear();
            for(int i=1;i<n;i++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                v[x].push_back(y);
                v[y].push_back(x);
            }
            for(int i=1;i<=n;i++)
            {
                dis[i][i]=0;
                dfs(i,-1,i);
            }
            int ans=1000000000;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    ans=min(ans,solve(i,j));
                    if(solve(i,j)==1)cout<<i<<j<<" ";
                }
            }
            printf("%d\n",ans);
        }
    }
}
