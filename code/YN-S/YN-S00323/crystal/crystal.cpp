#include <bits/stdc++.h>
using namespace std;

bool MST;
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
template<class _T>
void ckmax(_T &x, _T y) {
	x = max(x, y);
}
#define N 500010
int n, m;
int a[N], ans = 0;
void solve_() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int vis = 1, res = 0;
	rep(i, 2, n) {
		res += (i - vis) * (a[i] - a[i - 1]);
		while (res > m) {
			res -= a[i] - a[vis];
			vis++;
		}
		ckmax(ans, i - vis + 1);
	}
	cout << ans << "\n";
}
bool MED;
signed main() {
//	cerr << abs(&MST - &MED) / 1024 / 1024 << "MB\n";
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve_();
	return 0;
}
