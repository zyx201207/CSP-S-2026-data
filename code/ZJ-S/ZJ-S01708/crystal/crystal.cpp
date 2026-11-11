#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define sz(x) ((int)x.size())
#define pb push_back
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MLE cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
using namespace std;
bool Mbe;
const int N = 5e5 + 5;
int n, m, a[N], ans, s[N];
bool check(int l, int r) {
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]) <= m;
}
void sol() {
	cin >> n >> m;
	F(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	F(i, 1, n) s[i] = s[i - 1] + a[i];
	F(i, 1, n) {
		int l = 1, r = i, mid = i, res = i;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid, i)) {
				res = mid, r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << '\n';
}
bool Med;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	FIO
	int T = 1; 
	while (T--) sol();
//	MLE;
	return 0;
}
