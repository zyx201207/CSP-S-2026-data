#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],sum[500005];
bool check(int x)
{
    for(int i=1;i+x-1<=n;i++)
    {
        int j=i+x-1;
        long long need=a[j]*x-(sum[j]-sum[i-1]);
        if(need<=m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
