#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool f[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
    }
    memset(f,1,sizeof(f));
    for(int k=29;k>=0;k--)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(f[i]&&(a[i]&(1<<k)))cnt++;
        }
        if(cnt>=m)
        {
            ans+=(1<<k);
            for(int i=1;i<=n;i++)
            {
                f[i]=(f[i]&&(a[i]&(1<<k)));
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
