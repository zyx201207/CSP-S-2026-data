#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 5e5 + 5;
int n; i64 m, a[N];

int main()
{
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	long long c = 0; int ans = 1;
	for (int i = 2, j = 1; i <= n; ++ i)
	{
		c += (a[i] - a[i - 1]) * (i - j);
		for (; m < c && j <= i; c -= (a[i] - a[j ++]));
		ans = max(ans, i - j + 1);
	}
	
	cout << ans << '\n';
	return 0;
}
