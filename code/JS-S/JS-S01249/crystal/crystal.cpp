#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 1000000000000000000
#define _i128 __int128
#define pii pair<int, int>
#define fi first
#define se second
#define for1(i, a, b) for (int i = (a); i <= (b); i++)
#define for2(i, a, b) for (int i = (a); i >= (b); i--)
const int N = 5e5 + 5;
int TT = 1, n, m;
int a[N], pre[N];

bool check(int x)
{
	int mn = oo;
	for1(i, x, n) mn = min(mn, a[i] * (x - 1) - (pre[i - 1] - pre[i - x]));
	return mn <= m;
}

void solve()
{
	cin >> n >> m;
	for1(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	for1(i, 1, n) pre[i] = pre[i - 1] + a[i];
	int l = 2, r = n, ans = 1;
	while (l <= r){
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	//cin >> TT;
	while (TT--)
		solve();

	return 0;
}
