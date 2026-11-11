#include<bits/stdc++.h>
#define int ll
#define ll long long
#define el cout<<"\n"
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 500010;
int n, m, a[N], s, ans;
void init() {

}
void solve() {
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1;
	for (int r = 2; r <= n; r++) {
		s += (a[r] - a[r - 1]) * (r - l);
		while (s > m) {
			s -= (a[r] - a[l]);
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}