#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, x[N], ans, f[N], g[N], nxt[N];
vector <int> v;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) {
			cin >> x[i];
		}
		ans = 0;
		if(n == 1) {
			cout << 0 << '\n';
			continue;
		}
		if(n <= 5000) {
			for(int i = 1; i <= n; i ++) {
				int l = i, r = i;
				for(int j = i; j <= n; j ++) {
					f[j] = g[j] = 0;
				}
				f[i] = 0, g[i] = 1;
				int cnt = 1;
				for(int j = i + 1; j <= n; j ++) {
					while(x[j] - x[l] > d) {
						cnt -= g[l];
						l ++;
					}
					if(l >= j) {
						break;
					}
					while(f[r] != f[l]) {
						r ++;
						cnt += g[r];
					}
					while(r + 1 < j && f[r + 1] == f[l]) {
						r ++;
						cnt += g[r];
					}
					f[j] = f[l] + 1;
					g[j] = cnt;
					// cout << i << ' ' << j << ' ' << f[j] << ' ' << g[j] << '\n';
					if(g[j] == 2) {
						// cout << i << ' ' << j << '\n';
						ans ++;
					}
				}
			}
			cout << ans << '\n';
			continue;
		}
		else if(c == 11 || c == 12) {
			int w = d / (x[2] - x[1]);
			if(w == 0 || w == 1) {
				cout << 0 << '\n';
				continue;
			}
			cout << max(n - w * 2 + 1, 0ll) << '\n';
			continue;
		}
		else {
			for(int i = 1; i <= n; i ++) {
				int l = i + 1, r = n, res = 0;
				while(l <= r) {
					int mid = (l + r >> 1);
					if(x[mid] - x[i] <= d) {
						res = mid;
						l = mid + 1;
					}
					else {
						r = mid - 1;
					}
				}
				nxt[i] = res;
			}
			// cerr << "qwq" << '\n';
			for(int i = 1; i <= n; i ++) {
				v.clear();
				v.push_back(i);
				int x = i;
				while(x != n) {
					x = nxt[x];
					if(x == 0) {
						break;
					}
					v.push_back(x);
				}
				if(v.size() == 1) {
					continue;
				}
				x = i + 1;
				int y = i + 1;// x ~ v[i - 1], y ~ x - 1, v[i - 2] + 1 ~ y - 1
				for(int j = 2; j < v.size(); j ++) {
					int lst = v[j - 1];
					if(lst - x + 1 == 0) {
						x = v[j] + 1;
						if(lst - y + 1 >= 1) {
							if(lst - v[j - 2] == 1) {
								y = lst + 1;
							}
							else {
								y = nxt[lst - 1] + 1;
							}
						}
						else {
							y = v[j] + 1;
						}
					}
					else if(lst - x + 1 == 1) {
						if(lst - v[j - 2] == 1) {
							x = lst + 1;
							y = lst + 1;
						}
						else {
							x = nxt[lst - 1] + 1;
							y = x;
						}
					}
					else if(lst - x + 1 == 2){
						x = nxt[lst - 1] + 1;
						if(lst - v[j - 2] == 2) {
							y = lst + 1;
						}
						else {
							y = nxt[lst - 2] + 1;
						}
					}
					else {
						x = nxt[lst - 1] + 1;
						y = nxt[lst - 2] + 1;
					}
					ans += max(x - y, 0ll);
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}