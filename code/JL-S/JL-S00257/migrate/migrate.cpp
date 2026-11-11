#include <bits/stdc++.h>
using namespace std;
long long a[2000005],lmt[200005],dp[200005];
int n;
long long d;
int calc1(int i)
{
    int j=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
    if(j<=i)
        return 0;
    return (upper_bound(a+1,a+n+1,a[j]+d)-a-1)-(upper_bound(a+1,a+n+1,a[j-1]+d)-a-1);
}
int calc2(int i)
{
    int j=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
    if(j<=i+1)
        return 0;
    return (upper_bound(a+1,a+n+1,a[j-1]+d)-a-1)-(upper_bound(a+1,a+n+1,a[j-2]+d)-a-1);
}
void solve()
{
    int len=upper_bound(a+1,a+n+1,a[1]+d)-a-1;
    if(len==n||len<=2)
    {
        puts("0");
        return;
    }
    len--;
    len=2*len-1;
    printf("%d\n",max(0,n-len));
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        if(c==11||c==12)
        {
            solve();
            continue;
        }
        for(int i=1;i<=n;i++)
            lmt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1-i;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dp[j]=0;
            int l=i,r=i;
            dp[i]=1;
            while(1)
            {
                int nl=r+1,nr=r+lmt[r];
                if(lmt[r]==0)
                    break;
                for(int j=nl;j<=nr;j++)
                    for(int k=lower_bound(a+1,a+n+1,a[j]-d)-a;k<=r;k++)
                        dp[j]+=dp[k];
                for(int j=nl;j<=nr;j++)
                    if(dp[j]==2)
                        ans++;
                l=nl,r=nr;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
