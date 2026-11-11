#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], s[500005], ss[500005], sss[500005];
bool check(int x)
{
	int sum = LLONG_MAX;
	for(int i = x + 1;i <= n;i++)
	{
		int ssss = 0;
		ssss = x * ss[i] - (sss[i - 1] - sss[i - x - 1]);
		sum = min(sum, ssss);
	}
	return sum <= m;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m >> a[1];
	int l = 1, r = n + 5;
	for(int i = 2;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i < n;i++)
	{
		s[i + 1] = a[i + 1] - a[i];
		ss[i + 1] = ss[i] + s[i + 1];
		sss[i + 1] = sss[i] + ss[i + 1];
	}
	while(l < r)
	{
		int mid = (l + r + 1) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l + 1;
	return 0;
} 
