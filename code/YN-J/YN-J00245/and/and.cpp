// c - j - c 2026 10 31 csp T3
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
long long n, m, sum, a[N], tot;
long long ic = 30;
vector<int>e[50];

void solve() {
	for (int i = 1; i <= tot; i++) {
		long long x = a[i], cnt = 0;
		while (x) {
			if (x & 1)
				e[cnt].push_back(a[i]);
			cnt++;
			x >>= 1;
		}
	}
	int k = -1;
	for (int i = ic; i >= 0; i--) {
		if (e[i].size() >= m) {
			k = i;
			break;
		}
	}
	ic = k - 1;
	if (ic == -2)
		return;
	tot = 0;
	for (int i = 0; i < e[k].size(); i++)
		a[++tot] = e[k][i];
	for (int i = 30; i >= 0; i--)
		e[i].clear();
}

int main(void) {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	tot = n;
	while (ic >= 0)
		solve();
	long long res = a[1];
	for (int i = 1; i <= tot; i++)
		res &= a[i];
	cout << res;
	return 0;
}