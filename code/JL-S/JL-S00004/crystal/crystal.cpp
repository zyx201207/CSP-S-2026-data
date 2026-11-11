#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int sum[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out" ,"w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i-1;
		int nw=LLONG_MAX;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m)
			{
				nw=min(nw,mid);
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		// if(i-nw+1>ans)
		// {
		// 	printf("%lld %lld\n",nw,i);
		// }
		ans=max(ans,i-nw+1);
	}
	printf("%lld\n",ans);

}