#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500015];
long long b[500015];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
    }
    long long ans=-1;
    for(long long i=1;i<=n;i++)
    {
        long long l=1,r=i;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(b[i]-(b[mid]+(a[i]-a[mid])*(mid-1))<=m)
            {
                ans=max(ans,i-mid+1);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
