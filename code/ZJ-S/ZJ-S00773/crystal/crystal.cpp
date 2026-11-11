#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500001];
int s[500001];

#undef int
int main()
{
#define int long long
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int maxn = 0;
	for(int i = 1;i <= n;i++)
	{
		s[i] = s[i-1]+a[i];
		int l = 0;
		int r = i;
		int tans = i;
		while(l <= r)
		{
			int mid = (l+r)/2;
			if(s[i]-s[mid]-(i-mid)*a[i]+m >= 0)
			{
				r = mid-1;
				tans = mid;
			}
			else
			{
				l = mid+1;
			}
		}
		maxn = max(maxn,i-tans);
	}
	printf("%lld\n",maxn);
	return 0;
}
//dp[i] = max((i-j)*[s[i]-s[j]-(i-j)*a[i]+m >= 0]);
