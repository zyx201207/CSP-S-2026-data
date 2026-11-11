#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
long long sum[500005];
int ff(int i)
{
	long long ss=m+sum[i];
	int l=1,r=i,mid,res=i;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(sum[mid-1]+a[i]*(i-mid+1)<=ss)
		{
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return res;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=ff(i);
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
