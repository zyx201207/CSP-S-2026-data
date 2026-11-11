/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sum[500010],ans=1,cnt,x=1;
signed main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=(n-1);i++)
    {
        sum[i]=a[i+1]-a[i];
    }
    for(int i=n-1;i>=1;i--)
    {
        sum[i]=sum[i]+sum[i+1];
    }
    for(int i=1,j=1;i<=j,i<n,j<=n;j++)
    {
        cnt+=((sum[j-1]-sum[j])*x);
        x=1;
        if(cnt<=m)
        {
            ans=max(ans,j-i+1);
            while(a[j+1]==a[j])
            {
                ans++;
                j++;
                x++;
            }
        }
        else
        {
            i++;
            cnt-=(sum[i]-sum[j]);
        }
    }
    printf("%lld",ans);
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sum[500010],ans=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        sum[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++)
    {
        sum[i]=sum[i]+sum[i-1];
    }
    for(int i=2;i<=n;i++)
    {
        sum[i]=sum[i]+sum[i-1];
    }
    for(int i=1,j=1;i<=j,i<n,j<=n;j++)
    {
        if(sum[j]-sum[i]<=m)
        {
            ans=max(ans,j-i+1);
            while(a[j+1]==a[j])
            {
                ans++;
                j++;
            }
        }
        else
        {
            i++;
        }
    }
    printf("%lld",ans);
    return 0;
}
