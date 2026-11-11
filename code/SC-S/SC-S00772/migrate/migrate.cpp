#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t, cnt = 0, Minlen = 0x3f3f3f3f;
const int N = 2e6 + 5;
vector<int> Gr[N];
vector<bool> f(N, false);
vector<int> way(114, 0);
void dfs(int now, int len, int z) {
	way[len] = now;
	if (now == z)  {
		if (len < Minlen) {
			//cout << Minlen << ' ';
			Minlen = len;
			// cout << Minlen << '\n';
			cnt = 1;
		} else if (len == Minlen) {
			cnt++; /* cout << "DDD!!!\n";*/
		}
		//for (int i = 0; i <= len; i++) cout << way[i] << ">\n"[i == len];
		return;
	}
	if (len >= Minlen) return;
	for (int i : Gr[now]) {
		if (f[i]) continue;
		f[i] = true;
		dfs(i, len + 1, z);
		f[i] = false;
	}
}
void Solve() {
	bool f = true;
	ll n, ans = 0, d, dis;
	cin >> n >> d;
	vector<ll> x(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (i > 2) dis = x[i] - x[i - 1];
	}
	if (c == 12 || c == 11) {
		int k = 1;
		while (true) {
			if (3 * d - (k - 1) * dis < d) k++;
			else break;
		}
		if (3 * d - (k - 1) * dis < 0) ans = 0;
		else for (int i = 1; i + k <= n; i++) ans ++;
	} else {
		for (int i = 1; i <= n; i++) Gr[i].clear();
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] > d) break;
				else {
					Gr[i].push_back(j);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cnt = 0, Minlen = 0x3f3f3f3f;
				dfs(i, 0, j);
				if (cnt == 2) ans++;
				//cout << cnt << "\n\n";
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0), cout.tie(0);
	cin >> c >> t;
	while (t--) Solve();
	return 0;
}