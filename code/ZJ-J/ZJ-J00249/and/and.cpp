#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int n,m;
int a[maxn];
int ans;
bool f[maxn];
void dfs(int u)
{
    if(u==m+1)
    {
        int res=(1ll<<32ll)-1ll;
        for(int i=1;i<=n;++i)
        {
            if(f[i])
            {
                res&=a[i];
            }
        }
        ans=max(ans,res);
        return ;
    }
    for(int i=1;i<=n;++i)
    {
        if(f[i])
        {
            continue;
        }
        f[i]=1;
        dfs(u+1);
        f[i]=0;
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
    }
    if(n<=20)
    {
        dfs(1);
        printf("%lld",ans);
    }
    else
    {
        sort(a+1,a+n+1,greater<int>());
        printf("%lld",a[m]);
    }
    return 0;
}
