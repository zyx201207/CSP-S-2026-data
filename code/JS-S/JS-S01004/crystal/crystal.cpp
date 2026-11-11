#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],sum[1000005],ans;
bool check(int x)
{
    long long now=0x3f3f3f3f;
    for (int i=x;i<=n;i++)
    {
        now=min(now,x*a[i]-sum[i]+sum[i-x]);
    }
    if (now<=m)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}
