#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second
#define y1 csps300
#define stp(x) fixed << setprecision(x)

using namespace std;

const int N = 2e6 + 50, p = 998244353, inf = 1 << 29;

int id, n, pre[N], nxt[N];
ll m, a[N], cl[N], cr[N], fl[N], fr[N];
vector <int> L[N], R[N];

void init() {
	
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int r = 1;
	for (int i = 1; i <= n; i++) {
		if (r < i) r = i;
		while (r < n && a[r + 1] - a[i] <= m) ++r;
		nxt[i] = r;
		R[nxt[i]].push_back(i);
	}
	int l = n;
	for (int i = n; i; i--) {
		if (l > i) l = i;
		while (l > 1 && a[i] - a[l - 1] <= m) --l;
		pre[i] = l;
		L[pre[i]].push_back(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++) {
			int x = i, y = j;
			vector <int> v1, v2;
			v1.push_back(x);
			bool ok = 1;
			while (x < j) {
				if (nxt[x] == x) {
					ok = 0;
					break;
				}
				x = nxt[x];
				v1.push_back(x);
			}
			if (!ok) continue;
			v2.push_back(y);
			while (y > i) {
				y = pre[y];
				v2.push_back(y);
			}
			reverse(v2.begin(), v2.end());
			if (v1.size() != v2.size()) continue;
			if (v1.size() < 3) continue;
			// for (auto k : v1) cerr << k << " ";
			// cerr << endl;
			// for (auto k : v2) cerr << k << " ";
			// cerr << endl;
			int cnt = 0;
			for (int k = 1; k < v1.size() - 1; k++) 
				if (v2[k] < v1[k] - 1) {
					ok = 0;
					break;
				} else if (v2[k] == v1[k] - 1) {
					++cnt;
					if (cnt >= 2) {
						ok = 0;
						break;
					}
				} else if (v2[k] > v1[k]) {
					ok = 0;
					break;
				}
			if (!ok) continue;
			if (cnt == 1) ++ans;
		}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) pre[i] = nxt[i] = 0;
	for (int i = 1; i <= n; i++) cl[i] = cr[i] = fl[i] = fr[i] = 0;
	for (int i = 1; i <= n; i++) L[i].clear(), R[i].clear();
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t = 1;
	cin >> id >> t;
	while (t--) solve();
	return 0;
}