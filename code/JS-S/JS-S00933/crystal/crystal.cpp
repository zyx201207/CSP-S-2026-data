#include <bits/stdc++.h>
using namespace std;
long long a[500005],p[500005],sum[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)p[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+p[i]*(i-1);
    int start=1;
    while(sum[start]<=m && start<=n)
    {
        start++;
    }
    int max1=0;
    int L=1;
    for(int i=1;i<=n;i++)
    {
        while(sum[i]-(a[i]-a[L])>m && L<=i)
        {
            L++;
        }
        max1=max(max1,i-L+1);

    }
    cout<<max1;
    return 0;
}
