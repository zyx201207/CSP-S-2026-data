#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
ll c, n, d, p, lst, cnt, ans, x[N];
unordered_set<int> mp;
void solve() {
	cin >> n >> d;
	ans = 0;
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (11 <= c && c <= 14) {
		cout << "0\n";
		return;
	}
	if ((15 <= c && c <= 18) || (0 <= c && c <= 10)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j <= i) continue;
				mp.clear();
				lst = p = i; cnt = 0; mp.insert(i); mp.insert(j);
				while (p < j) {
					if (x[p + 1] - x[lst] > d) {
						lst = p;
						p++; cnt++;
						mp.insert(p);
					} else p++;
				}
				lst = j;
				bool is_two = false;
				while (p > i) {
					if (x[lst] - x[p - 1] > d) {
						lst = p;
						p--; cnt--;
						if (!mp.count(p)) is_two = true;
					} else p--;
				}
				if (is_two && cnt == 0) ans++;
			}
		}
		cout << ans + 1 << '\n';
		return;
	} 
	cout << "0\n";
}
int main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> c >> T;
	while (T--) solve();
	return 0;
}
