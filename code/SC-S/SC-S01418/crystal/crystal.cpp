#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, arr[500005];

// RP++
int main()
{
	freopen("crystal.in", "r", stdin);
//	freopen("..\\csps\\down\\crystal\\crystal4.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("..\\csps\\down\\crystal\\crystal.out", "w", stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	
	scanf("%lld%lld", &n, &m);
	for (ll i = 0; i < n; i++)
		scanf("%lld", arr + i);
	sort(arr, arr + n);
	
	ll l = 0, r = 0, sum = 0, maxn = 0;
	while (r < n)
	{
		while (r < n)
		{
			r++;
			sum += (r - l - 1) * (arr[r - 1] - arr[max<ll>(r - 2, 0)]);
			if (sum > m)
				break;
			maxn = max(maxn, r - l);
		}
		while (l < r)
		{
			sum -= arr[r - 1] - arr[l];
			l++;
			if (sum <= m)
				break;
		}
		maxn = max(maxn, r - l);
	}
	
	printf("%lld", maxn);
	
	return 0;
}