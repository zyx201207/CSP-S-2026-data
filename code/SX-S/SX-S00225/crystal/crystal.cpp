#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
long long m,a[N],sum[N];
bool check(int mid)
{
	for (int i = mid;i <= n;i++)
	{
		long long cnt = sum[i]-sum[i-mid];
		if(a[i]*mid-cnt <= m)
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
	scanf("%d%lld",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i = 1;i <= n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l = 1,r = n,ans;
	while (l <= r)
	{
		int mid = (l+r)/2;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}