#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long n,m,l,r,mid,cnt,ans,a[500005],sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    	sum[i]=sum[i-1]+a[i];
    for(int i=2;i<=n;i++)
    {
    	l=1,r=i-1;
    	while(l<=r)
    	{
    		mid=(l+r)/2;
    		if((i-mid)*a[i]-sum[i-1]+sum[mid-1]<=m)
    		{
    			cnt=mid;
    			r=mid-1;
			}
			else
				l=mid+1;
		}
		ans=max(ans,i-cnt+1);
    }
    cout<<ans;
    return 0;
}
