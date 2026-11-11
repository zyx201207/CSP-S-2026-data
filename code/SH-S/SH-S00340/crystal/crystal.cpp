#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e3+5, M = 5e5+5;
ll n, m;
ll a[M];
ll s[M];
ll ans;

bool check(int j, int i)
{
	ll cur = (ll)a[i]*(i-j+1) - (s[i]-s[j-1]);
	return cur <= m;
}

int main()
{
//	bool isA = 1, isB = 1;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
//		if (a[i] != i) isA = 0;
//		if (i >= 3 && a[i-2]-a[i-1] != a[i-1]-a[i]) isB = 0;
		
	}
//	if (isA)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			if ((ll)i*(i-1)/2 > m)
//			{
//				printf("%lld\n", i-1);
//				return 0;
//			}
//		}
//	}
//	if (isB)
//	{
//		sort(a+1, a+n+1);
//		ll gc = a[2]-a[1];
//		for (int i = 1; i <= n; i++)
//		{
//			if ((gc + (ll)(i-1)*gc)*(i-1)/2 > m)
//			{
//				printf("%lld\n", i-1);
//				return 0;
//			}
//		}
//	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i-1]+a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int lf = 1, rt = i;
		while (lf<rt)
		{
			int mid = lf+((rt-lf)>>1);
			if (check(mid, i))
			{
				rt = mid;
			}
			else
			{
				lf = mid+1;
			}
		}
		ans = max((ll)i-rt+1, ans);
	}
	printf("%lld\n", ans);
	return 0;
}
/*
14:50 45pts BF
15:03 60pts BF+A
15:10 75pts 1-9,13-18
17:53 restart
18:15 AC all
rp++
*/

