#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll a[N], b[N], m;
int n;
bool check(ll mid, ll now)
{
	int k = b[now] - b[mid - 1];
	if (a[now] * (now - mid + 1) - k <= m)
		return true;
	return false;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int res = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i, ans = 0;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (check(mid, i))
				r = mid - 1, ans = mid;
			else
				l = mid + 1;
		}
		res = max(res, i - ans + 1);
	}
	cout << res;
	return 0;
}
