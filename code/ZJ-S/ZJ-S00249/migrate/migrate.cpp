#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=2e6+10;
constexpr int maxm=5e3+10;
constexpr int INF=1e18;
int c,t,n,d,x[maxn],sum[maxn];
vector<int> gra[maxn];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        for(int i=1;i<=n;++i) gra[i].clear();
        fill(sum,sum+1+n,0);
        scanf("%lld%lld",&n,&d);
        int f=1;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",x+i);
        }
        for(int i=3;i<=n;++i)
        {
            if(x[i]-x[i-1]!=x[i-1]-x[i-2]) f=0;
        }
        int res=0;
        if(f)
        {
            if(n<=3) printf("0");
            else
            {
                int pos=d/(x[2]-x[1]);
                if(pos<=1) printf("0");
                else
                {
                    int len=(pos)*2-1;
                    printf("%lld",max(n-len,0ll));
                }
            }
        }
        else
        {
            int res=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=i+1;j<=n;++j)
                {
                    if(x[j]-x[i]<=d) gra[i].emplace_back(j);
                }
            }
            for(int s=1;s<=n;++s)
            {
                vector<int> d(n+1,INF),cnt(n+1);
                queue<int> q;
                q.emplace(s);
                d[s]=0;
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    for(auto& v:gra[u])
                    {
                        if(d[u]+1==d[v]) ++cnt[v],q.emplace(v);
                        else if(d[v]>d[u]+1)
                        {
                            d[v]=d[u]+1;
                            cnt[v]=1;
                            q.emplace(v);
                        }
                    }
                }
                for(int i=1;i<=n;++i)
                {
                    if(cnt[i]==2) ++res;
                }
            }
            printf("%lld",res);
        }
        printf("\n");
    }
    return 0;
}