#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long maxn=0;
    for(long long i=1;i<=n;i++)
    {
        sum[i]=a[i]+sum[i-1];
        long long l=1,r=i;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
            {
                r=mid-1;
            }
            else l=mid+1;
        }
        maxn=max(maxn,i-l+1);
    }
    cout<<maxn;
    return 0;
}
