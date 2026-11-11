#include <bits/stdc++.h>
using namespace std;

long long n, m, num = pow(2, 30), r, ans;
vector<long long> a, d, opt;
vector<bool> vis;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	d.resize(n);
	vis.resize(n);
	opt.assign(m + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	opt[0] = 0;
	opt[1] = *a.end();
	for (int h = 2; h <= m; h++) {
		num = pow(2, 30);
		d.resize(n + 2 - h);
		if (h == 2) {
			for (int i = 1; i < n; i++) {
				if (vis[i] || vis[i - 1])
					continue;
				d[i - 1] = a[i] - a[i - 1];
				if (d[i - 1] < num) {
					num = d[i - 1];
					r = i - 1;
				} else if (d[i - 1] == num) {
					if (a[i - 1] > a[num]) {
						num = d[i - 1];
						r = i - 1;
					}
				}
				vis[r] = true;
				vis[r + 1] = true;
				ans = (a[r] & a[r + 1]);
				opt[2] = max(opt[2], ans);
			}
		} else {
			long long u = 0, k = (a[0] & ans);
			for (int i = 0; i < n; i++) {
				if (vis[i])
					continue;
				vis[u] = false;
				if ((a[i]&ans) > k) {
					k = (a[i] & ans);
					u = i;
				}
				vis[u] = true;
			}
			ans = k;
			opt[h] = max(opt[h], ans);
		}
	}
	cout << opt[m] << endl;
	return 0;
}