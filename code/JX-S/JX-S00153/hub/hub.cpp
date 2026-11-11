#include <bits/stdc++.h>
using namespace std;
const int N=1000010,M=N*2,INF=0x3f3f3f3f;
int ooo,t,n,k,ans;
int head[N],e[M],ne[M],idx;
int f[N][22],dep[N];
bool used[N];
int fa[N];
int find(int x)
{
    if (fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void add(int x,int y)
{
    e[idx]=y,ne[idx]=head[x],head[x]=idx++;
}
void init()
{
    for (int i=1;i<=n;i++)head[i]=-1;
    idx=0;
    ans=INF;
}
void dfs1(int x,int fm)
{
    f[x][0]=fm;
    dep[x]=dep[fm]+1;
    for (int i=1;i<=20;i++)
        f[x][i]=f[f[x][i-1]][i-1];
    for (int i=head[x];i!=-1;i=ne[i])
    {
        int y=e[i];
        if (y==fm)continue;
        dfs1(y,x);
    }
}
int lca(int x,int y)
{
    if (dep[x]<dep[y])swap(x,y);
    for (int i=20;i>=0;i--)
        if (dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if (x==y)return x;
    for (int i=20;i>=0;i--)
        if (f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int dist(int x,int y)
{
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void dfs2(int x,int cnt)
{
    if (x==n+1&&cnt!=k)return ;
    if (x==n+1)
    {
        int tot=k;
        for (int i=1;i<=n;i++)fa[i]=i;
        for (int i=1;i<=n;i++)
            if (used[i])
            {
                for (int j=head[i];j!=-1;j=ne[j])
                {
                    int y=e[j];
                    if (!used[y])continue;
                    int a=find(i),b=find(y);
                    if (a==b)continue;
                    fa[a]=b;
                    tot--;
                }
            }
        if (tot!=2)return ;
        int res=0;
        for (int i=1;i<=n;i++)
        {
            int mind=INF;
            for (int j=1;j<=n;j++)
                if (used[j])
                    mind=min(mind,dist(i,j));

            res=max(res,mind);
        }
        ans=min(ans,res);
        return ;
    }
    used[x]=true;
    dfs2(x+1,cnt+1);
    used[x]=false;
    dfs2(x+1,cnt);
}   
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>ooo>>t;
    while (t--)
    {
        cin>>n>>k;
        init();
        for (int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b);add(b,a);
        }
        dfs1(1,-1);
        dfs2(1,0);
        cout<<ans<<endl;
    }
    return 0;
}