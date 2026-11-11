#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=2e5+10;
constexpr int maxk=32;
int n,m,a[maxn],cnt[maxk],vis[maxn];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        for(int j=0;j<maxk;++j)
        {
            if(a[i]>>j&1)
            {
                ++cnt[j];
            }
        }
    }
    int res=0;
    for(int i=maxk-1;i>=0;--i)
    {
        if(cnt[i]>=m)
        {
            res+=1ll<<i;
            for(int j=1;j<=n;++j)
            {
                if(!(a[j]>>i&1)) vis[j]=1;
            }
            fill(cnt,cnt+maxk,0);
            for(int j=1;j<=n;++j)
            {
                if(!vis[j])
                {
                    for(int k=0;k<maxk;++k)
                    {
                        if(a[j]>>k&1) ++cnt[k];
                    }
                }
            }
        }
    }
    printf("%lld",res);
    return 0;
}