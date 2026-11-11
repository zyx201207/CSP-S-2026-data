#include<bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define inf (LLONG_MAX>>1)

constexpr int maxn=2e6+10;

int c,T;

int n,d;
int x[maxn];
vector<int> gra[maxn];
int dis[maxn];
int cnt[maxn];

void bfs(int s)
{
    for(int i=s;i<=n;++i)
    {
        dis[i]=inf;
        cnt[i]=0;
    }
    dis[s]=0;
    queue<int> q;
    q.emplace(s);
    while(!q.empty())
    {
        int u=q.front();
        //printf("u:%lld d:%lld\n",u,dis[u]);
        q.pop();
        //if(vis[u]) continue;
        for(int v:gra[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                cnt[v]=1;
                q.emplace(v);
            }
            else if(dis[v]==dis[u]+1)
            {
                ++cnt[v];
                q.emplace(v);
            }
        }
    }
}

void sol1()
{
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",x+i);
        gra[i].clear();
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(x[j]-x[i]<=d)
            gra[i].emplace_back(j);
        }
    }

    int ans=0;
    for(int i=1;i<=n;++i)
    {
        bfs(i);
        //printf("%lld: \n",i);
        for(int j=i;j<=n;++j)
        {
            //printf("%lld %lld\n",dis[j],cnt[j]);
            if(cnt[j]==2) ++ans;
        }
    }
    printf("%lld\n",ans);
    //printf("---------------------------here-------------------------------\n");
}

void sol2()
{
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",x+i);
    }
    int D=x[2]-x[1];
    int p=d/D;
    if(p<=1)
    {
        printf("0\n");
    }
    else
    {
        int ans=max(0ll,n-2*p+1);
        printf("%lld\n",ans);
    }
}

void solve()
{
    if(c<=10) sol1();
    else if(c==11||c==12) sol2();
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%lld%lld",&c,&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
/*
3 4
1 *3* 6                         0
6 12
1 6 *11* *13* 17 19               1
9 13
1 3 5 7 *12* *14* 17 19 23        2
*/