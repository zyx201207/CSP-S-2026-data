#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iny signed long long
constexpr int maxn=1e6+13;
constexpr int maxm=2e3+13;

int c,t;
int n,k;
vector<int>gra[maxn];
int vis[maxn];
int fa_[maxn];
inline int fin(int x)
{
    return x==fa_[x]?x:fa_[x]=fin(fa_[x]);
}
int bfs0(int s)
{
    for(int i=1;i<=n;++i)
    {
        vis[i]=n+1;
    }
    queue<int>q;
    q.push(s);
    vis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(fa_[u])
        {
            return vis[u];
        }
        for(int v:gra[u])
        {
            if(vis[v]==n+1)
            {
                vis[v]=vis[u]+1;
                q.push(v);
            }
        }
    }
    return n+1;
}

void sol_small0()
{
    int up=1<<n;
    int ans=n;
    for(int i=0;i<up;++i)
    {
        if(__builtin_popcount(i)^k)
        {
            continue;
        }
        for(int j=1;j<=n;++j)
        {
            if(i>>(j-1)&1)
            {
                fa_[j]=j;
            }
            else
            {
                fa_[j]=0;
            }
        }
        for(int j=1;j<=n;++j)
        {
            if(!fa_[j])
            {
                continue;
            }
            for(int x:gra[j])
            {
                if(fa_[x])
                {
                    fa_[fin(x)]=fin(j);
                }
            }
        }
        int cnt=0;
        for(int j=1;j<=n;++j)
        {
            if(fa_[j]&&fin(j)==j)
            {
                ++cnt;
            }
        }
        if(cnt>2)
        {
            continue;
        }
        int res=0;
        for(int j=1;j<=n;++j)
        {
            if(!fa_[j])
            {
                res=max(res,bfs0(j));
            }
        }
        ans=min(ans,res);
    }
    printf("%d\n",ans);
}
int dis1[maxn],dis2[maxn];
void bfs11(int s)
{
    queue<int>q;
    q.push(s);
    dis1[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:gra[u])
        {
            if(dis1[v]>dis1[u]+1)
            {
                dis1[v]=dis1[u]+1;
                q.push(v);
            }
        }
    }
}
void bfs12(int s)
{
    queue<int>q;
    q.push(s);
    dis2[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:gra[u])
        {
            if(dis2[v]>dis2[u]+1)
            {
                dis2[v]=dis2[u]+1;
                q.push(v);
            }
        }
    }
}
void sol_small_k2()
{
    int ans=n;
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            for(int l=1;l<=n;++l)
            {
                dis1[l]=1e9;
                dis2[l]=1e9;
            }
            bfs11(i);
            bfs12(j);
            int res=0;
            for(int l=1;l<=n;++l)
            {
                res=max(res,min(dis1[l],dis2[l]));
            }
        }
    }
    printf("%d\n",ans);
}
int cnt[maxn];
void dfs0(int u,int p,int d,int h)
{
    ++cnt[u];
    if(d==h)
    {
        return ;
    }
    for(int v:gra[u])
    {
        if(v==p)
        {
            continue;
        }
        dfs0(v,u,d+1,h);
    }
}
bool check(int h)
{
    for(int i=1;i<=n;++i)
    {
        cnt[i]=0;
    }
    for(int i=1;i<=n;++i)
    {
        dfs0(i,0,0,h);
    }
    int need=0;
    for(int i=1;i<=n;++i)
    {
        if(cnt[i]>=n/2)
        {
            ++need;
        }
    }
    return need<=k;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    //剩一个小时但只有240
    //什么都调不出来

    while(t--)
    {
        for(int i=1;i<=n;++i)
        {
            gra[i].clear();
        }
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            gra[u].push_back(v);
            gra[v].push_back(u);
        }
        if(n<=10)
        {
            sol_small0();
            continue;
        }
        if(n<=1000&&k==2)
        {
            sol_small_k2();
            continue;
        }
        if(n==k)
        {
            printf("0\n");
            continue;
        }
        int l=0,r=n;
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

