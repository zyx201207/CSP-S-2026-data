#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int c,t;
int n,d;
int a[N];
int minn[N],sum[N];
int ans;
void dfs(int x,int summ)
{
    if(summ<minn[x])
    {
        minn[x]=summ;
        sum[x]=1;
    }
    else if(summ==minn[x])
    {
        sum[x]++;
    }
    else
        return;
    for(int i=x+1;i<=n;++i)
    {
        if(a[i]-a[x]<=d)
        {
             dfs(i,summ+1);
        }
        else
            break;
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&d);
        ans=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                 sum[j]=0;
                minn[j]=0x5f5f5f5f5f5f;
            }
            dfs(i,0);
            for(int i=1;i<=n;++i)
                if(sum[i]==2)
                ans++;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
