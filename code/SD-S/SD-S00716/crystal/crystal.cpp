#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;

ll n, m;
ll a[N], pre[N];

bool check(int x)
{
	for (int i = 1, j = x; j <= n; i++, j++)
		if (a[j] * x - (pre[j] - pre[i - 1]) <= m) return true;
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int l = 1, r = n, ans = 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}

/*
5 5
1 2 4 8 9
*/

