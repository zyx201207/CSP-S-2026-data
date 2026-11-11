#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int a[maxn];
char c[maxn];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld %c",&a[i],&c[i]);
    }
    int l=1,r=n;
    for(;l<=r;++l)
    {
        while(a[l]>=a[r]&&l<=r)
        {
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            a[l]-=a[r];
            --r;
        }
        if(l<=r)
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[r]-=a[l];
        }
    }
    printf("%lld",ans);
    return 0;
}
