#include <bits/stdc++.h>
#define int long long
using namespace std;
int sum[500005];
int n,m;
int a[500005];
bool check(int x)
{
	int ci = 2e18;
	for(int i=x;i<=n;i++)
	{
		int sum1 = sum[i]-sum[i-x];
		int sum2 = a[i]*x;
		ci = min(ci,sum2-sum1);
		//printf("sum1:%lld sum2:%lld\n",sum1,sum2);
	}
	//printf("%lld %lld\n",x,ci);
	if(ci>m) return 0;
	return 1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
	int l = 1,r = n+1;
	while(l<=r)//二分合成宝石数量
	{
		int mid = (l+r)>>1;
		//printf("%lld\n",mid);
		if(check(mid))
		{
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	printf("%lld\n",l-1);
}//100(25min)