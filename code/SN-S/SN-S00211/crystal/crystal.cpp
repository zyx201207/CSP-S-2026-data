//SN-S00211 shi jia lin xi bei gong ye da xue fu shu zhong xue
// < O(nlongn)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 10;

int n;

ll m, a[maxn], pre[maxn], minn = 1e18l + 10;

bool check (ll len)
{
	ll res = 1e18l + 10;
	for (int i = 1; i + len - 1 <= n; i++)
	{
		res = min(res, a[i + len - 1] * len - (pre[i + len - 1] - pre[i - 1]));
	}
	if (res > m) return 0;
	return 1;
}


int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	if (minn < 0)
	{
		minn = -minn;
		for (int i = 1; i <= n; i++)
		{
			a[i] += minn;
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
	}
	ll l = 0, r = n, ans = 0, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		ll chk = check(mid);
		if (chk == 1)
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
