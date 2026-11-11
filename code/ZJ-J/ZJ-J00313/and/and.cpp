#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int a[maxn],vis[maxn];
vector<int> pos[35];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0,f=0;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        for(int j=31;j>=0;--j)
        {
            if((a[i]>>j)&1)
            {
                pos[j].emplace_back(i);
            }
        }
    }
    for(int i=31;i>=0;--i)
    {
        if(pos[i].size()<m) continue;
        int cnt=0;
        for(int j:pos[i])
        {
            if(vis[j]==f)
            {
                ++cnt;
            }
        }
        if(cnt>=m)
        {
            for(int j:pos[i])
            {
                if(vis[j]==f)
                {
                    ++vis[j];
                }
            }
            ++f;
            ans+=(1<<i);
        }
    }
    printf("%lld",ans);
    return 0;
}
