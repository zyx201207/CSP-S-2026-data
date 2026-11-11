#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
    int t;
    int tim;
};
const int N=505;
const int M=5e4+5;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][M];
int t[N][M];
int vis[M];
vector<int> l[M];
int times[M][N];
int ans;
void dfs(int u,int y,int sum)
{
    if(sum+w[y]>=ans) return ;
    if(u==y)
    {
        ans=min(ans,sum+w[y]);
        return ;
    }
    for(int i:l[u])
    {
        for(int j=1;j<=k[i];j++)
        {
            if(a[i][j]==u) continue;
            if(vis[a[i][j]]) continue;
            vis[a[i][j]]=1;
            dfs(a[i][j],y,times[u][i]+sum+t[i][j]);
            vis[a[i][j]]=0;
        }
    }
}

int anss[N][N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) scanf("%lld%lld",&a[i][j],&t[i][j]),l[a[i][j]].push_back(i),times[a[i][j]][i]=t[i][j];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==j) continue;
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            ans=1e18;
            dfs(i,j,w[i]);
            anss[i][j]=ans+w[j];
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        memset(vis,0,sizeof(vis));
        vis[x]=1;
        ans=1e18;
        dfs(x,y,w[x]);
        cout<<ans<<' ';
    }
    return 0;
}

