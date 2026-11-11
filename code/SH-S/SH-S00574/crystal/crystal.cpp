#include<bits/stdc++.h>
using namespace std;
long long a[500011];
long long sum[500011];
//2:30~2:39 thinking&coding:10min
//hope to be->100
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		long long l=0,r=i,mid;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if(a[i]*((long long)i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld\n",ans);
}
