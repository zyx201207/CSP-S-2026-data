#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+100;
long long n,m;
long long a[N];
long long sum[N];
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(long long i=1;i<=n;i++)
	{
		long long l=0,r=i;
		while(l+1<r)
		{
			long long mid=(l+r)/2;
			long long len=(i-mid+1);
			if(len*a[i]-(sum[i]-sum[mid-1])<=m)
			r=mid;
			else
			l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
