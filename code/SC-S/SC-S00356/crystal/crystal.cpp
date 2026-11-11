#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],sum[N]; 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,res=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
			{
				r=mid-1;
				res=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	printf("%lld",ans);
	return 0;
}
//RP++
/*
forest114514(高二)上身祝我一臂之力 
*/