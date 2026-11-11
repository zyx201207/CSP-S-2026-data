#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans=-1e18;
bool cmp(long long u,long long v)
{
    return u<v;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >>m;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for(long long i=n;i>=1;i--)
    {
        for(long long j=1;j<min(i,i-ans+1);j++)
        {
            if(sum[i]-sum[j-1]+m>=(i-j+1)*a[i])
            {
                ans = max(ans,i-j+1);

                break;
            }
        }

    }

    cout << ans;
    return 0;
}
