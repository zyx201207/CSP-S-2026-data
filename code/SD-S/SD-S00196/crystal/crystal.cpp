#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 5;
int n;
ll m, a[N], s[N], d[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	bool B = true;
	ll diff = a[2] - a[1];
	for (int i = 3; i <= n; i++)
		B &= a[i] - a[i - 1] == diff;
	if (B)
	{
		for (int i = 1; i <= n; i++)
			d[i] = (i - 1) * diff;
		partial_sum(d + 1, d + n + 1, s + 1);
		cout << upper_bound(s + 1, s + n + 1, m) - s - 1;
	}
	else
	{
		sort(a + 1, a + n + 1);
		partial_sum(a + 1, a + n + 1, s + 1);
		int ans = 1;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
			{
				int l = j - i + 1;
				if ((l - 1) * a[j] - (s[j - 1] - s[i - 1]) <= m)
					ans = max(ans, l);
			}
		cout << ans;
	}
	return 0;
}
