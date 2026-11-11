#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
ll n, m;
ll a[MAXN];
ll ans;
void dfs(ll nw, ll nm, ll nans)
{
	if (nm == 0)
	{
		ans = max(ans, nans);
		return;
	}
	if (nm > n - nw)
	{
		return;
	}
	for (ll i = nw + 1; i <= n; i++)
	{
		dfs(i, nm - 1, (nans & a[i]));
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(0, m, (1LL << 31) - 1);
	cout << ans;
	return 0;
}