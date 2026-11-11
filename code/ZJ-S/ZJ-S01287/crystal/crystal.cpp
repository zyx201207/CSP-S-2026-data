#include <bits/stdc++.h>
#define Int long long
using namespace std;

const int N = 5e5 + 10;

Int a[N];

void solve()
{
	int n, l, ans = 0; Int m, sum = 0; 
	cin >> n >> m;
	l = n + 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int r = n; r >= 1; r--)
	{
		while ((r - l + 2) * a[r] - (sum + a[l - 1]) <= m && l - 1 >= 1) l--, sum += a[l];
		ans = max(ans, r - l + 1);
		sum -= a[r];
	}
	cout << ans << '\n';
	return;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T = 1;
	while (T--) solve();
	return 0;
}

//What a Mestery!
