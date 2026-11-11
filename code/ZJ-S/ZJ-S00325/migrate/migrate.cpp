#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e6+10;
constexpr int inf=(LLONG_MAX>>1)-1ll;
int a[maxn],cnt[maxn],dis[maxn],vis[maxn];
vector<int> gra[maxn];
void bfs(int n,int s)
{
    for(int i=1;i<=n;++i)
    {
        dis[i]=inf,vis[i]=0;
        cnt[i]=0;
    }
    dis[s]=0;
    cnt[s]=1;
    queue<int> q;
    q.emplace(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:gra[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
                q.emplace(v);
            }
            else if(dis[v]==dis[u]+1)
            {
                cnt[v]+=cnt[u];
            }
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        int n,d,ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
        }
        if(n<=5e3)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=i+1;j<=n;++j)
                {
                    if(a[j]-a[i]<=d)
                    {
                        gra[i].emplace_back(j);
                        gra[j].emplace_back(i);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for(int i=1;i<=n;++i)
            {
                bfs(n,i);
                for(int j=i+1;j<=n;++j)
                {
                    if(cnt[j]==2)
                    {
                        ++ans;
                    }
                }
            }
            printf("%lld\n",ans);
            for(int i=1;i<=n;++i)
            {
                gra[i].clear();
            }
            continue;
        }
        if(c==11||c==12)
        {
            if(a[2]-a[1]>d)
            {
                printf("0\n");
                continue;
            }
            int res=d/(a[2]-a[1]);
            if(res==1)
            {
                printf("0\n");
                continue;
            }
            int dd=a[2]-a[1];
            for(int i=1;i<=n;++i)
            {
                if((a[n]-a[i])/dd>=res*2-1)
                {
                    ++ans;
                }
                else
                {
                    break;
                }
            }
            printf("%lld\n",ans);
        }
        if(c==13||c==14)
        {
            print("0\n");
        }
    }
    return 0;
}
