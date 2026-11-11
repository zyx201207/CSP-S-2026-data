#include<bits/stdc++.h>
#define ll long long
#define ls(i) i<<1
#define rs(i) i<<1|1

using namespace std;

const int N = 2e5+5;
ll n, d;
ll x[N], diff[N], ji[N];
bool vis1[N];
vector<int> doublel;
void solve() {
	cin >> n >> d;
	int ans = 0;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 2; i <= n; i++) {
		diff[i] = x[i] - x[i - 1];
		if (diff[i] != diff[i - 1] && i > 2) {
			flag = false;
		}
	}
	if (n < 4) {
		cout << 0 << "\n";
		return ;
	}
	if (flag) {
		if (d / diff[3] == 2) {
			cout << n - 3 << "\n";
		} else {
			cout << 0 << "\n";
		}
		return ;
	}
	for (int i = 1; i < n; i++) {
		while (x[i + ji[i]] - x[i] <= d && i + ji[i] <= n) {
			ji[i]++;
		}
		ji[i]--;
		if (ji[i] >= 2) {
			doublel.push_back(i);
		}
	}
	for (auto u : doublel) {
		int v = u + ji[u] + 1;
		int cnt = 0;
		if (v <= n) {
			ans++;
			for (int i = u + 1; i <= v; i++) {
				if (x[i] - x[u] <= d && x[v] - x[i] <= d) {
					cnt++;
				}
				if (cnt > 2) {
					break;
				}
			}
			if (cnt != 2) {
				ans--;
			}
			if (ji[v - 1] == 1) {
				while (ji[v] == 1 && v + ji[v] <= n) {
					ans++;
					v++;
				}
			}
		}
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i++) {
		ji[i] = 0;
		while (!doublel.empty()) {
			doublel.clear();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}