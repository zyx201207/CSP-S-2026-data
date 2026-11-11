#include <bits/stdc++.h>
using namespace std;
#define iny signed long long
constexpr int maxn=2e5+13;

int n;
int a[maxn];
char c[maxn];

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %c",&a[i],&c[i]);
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r)
    {
        int res=min(a[l],a[r]);
        if(c[l]!=c[r])
        {
            ans+=1ll*res;
        }
        a[l]-=res,a[r]-=res;
        if(!a[l])
        {
            ++l;
        }
        if(!a[r])
        {
            --r;
        }
    }
    printf("%lld\n",ans);

    return 0;
}

