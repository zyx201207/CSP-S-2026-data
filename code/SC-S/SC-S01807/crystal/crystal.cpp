#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
int n;
ll m;
ll a[N], pre[N];

bool check(int l, int r) // (l, r]
{
	ll nd = (r - l) * a[r];
	ll had = pre[r] - pre[l];
	return nd - had <= m;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = i, mid, res = i;
		while (l <= r)
		{
			mid = l + r >> 1;
			if (check(mid, i))
				res = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, i - res);
	}
	cout << ans << '\n';
	return 0;
}