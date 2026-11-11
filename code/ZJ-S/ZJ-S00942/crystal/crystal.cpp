#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 10;
ll n, m, a[maxn], ans;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (ll i = 2; i <= n; i++)
	{
		a[i] += a[i - 1];
	}
	for (ll i = 1, j = 1; i <= n; i++)
	{
		while (j <= i && (a[i] - a[i - 1]) * (i - j) - (a[i - 1] - a[j - 1]) > m)
		{
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}