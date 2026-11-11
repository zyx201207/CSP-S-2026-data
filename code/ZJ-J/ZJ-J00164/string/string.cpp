#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int n,ans,a[maxn];
char c[maxn];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld %c",&a[i],&c[i]);
    }
    for(int l=1,r=n;l<=r;)
    {
        if(a[l]<a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[r]-=a[l];
            a[l]=0;
            ++l;
        }
        else if(a[l]==a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[l]=a[r]=0;
            ++l,--r;
        }
        else
        {
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            a[l]-=a[r];
            a[r]=0;
            --r;
        }
    }
    printf("%lld",ans);
    return 0;
}
