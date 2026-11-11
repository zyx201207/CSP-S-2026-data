#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define mp(a, b) make_pair(a, b)
#define pr pair<int, int>
#define fir first
#define sec second
#define iosfst ios::sync_with_stdio(false);cin.tie(0), cout.tie(0)
using namespace std;
const int N = 5e5 + 10;
int n, m, res, a[N], pre[N];
bool check(int x, int len) {
	int ress = 0;
	//x - len + 1 ~ x
	ress = a[x] * len - pre[x] + pre[x - len];
	return (ress <= m);
}
signed main() {
	iosfst;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep (i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	rep (i, 1, n) pre[i] = pre[i - 1] + a[i];
	rep (i, 1, n) {
		int l = 1, r = i, ans = 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(i, mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		res = max(ans, res);
	}
	cout << res;
	return 0;
}
