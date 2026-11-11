#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
constexpr int maxB=30+10;
int n,m,ans,a[maxn],cnt[maxB];
vector<int>bit[maxn];
bool vis[maxn];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        for(int b=0;b<30;++b)
        {
            if(a[i]>>b&1)
            {
                ++cnt[b];
                bit[i].emplace_back(b);
            }
        }
    }
    for(int b=29;b>=0;--b)
    {
        if(cnt[b]>=m)
        {
            ans|=(1ll<<b);
            for(int i=1;i<=n;++i)
            {
                if((a[i]>>b&1)||vis[i])
                {
                    continue;
                }
                vis[i]=1;
                for(int x:bit[i])
                {
                    --cnt[x];
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
