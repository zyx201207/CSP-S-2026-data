#include <bits/stdc++.h>
using namespace std;
vector<int> vj;
vector<int>vo;
int n, m, a[200005], d[200005], sum[200005], lastl, lastr, minn = INT_MAX;

bool cmp(int c, int d) {
	return c > d;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 1) {
			vj.push_back(a[i]);
		} else {
			vo.push_back(a[i]);
		}
	}
	sort(vj.begin(), vj.end(), cmp);
	sort(vo.begin(), vo.end(), cmp);
	int maxx = 0;
	int maxn = 0;
	if (vj.size() >= m) {
		maxx = vj[0];
		for (int i = 0; i < m; i++) {
			maxx &= vj[i];
		}
	}
	if (vo.size() >= m) {
		maxn = vo[0];
		for (int i = 0; i < m; i++) {
			maxn &= vo[i];
		}
	}
	sort(a + 1, a + n + 1);
	a[0] = a[1];
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = d[i] + sum[i - 1];
	}
	for (int l = 1; l <= n; l++) {
		if (l + m - 1 > n) {
			break;
		}
		int r = l + m - 1;
		if (minn > sum[r] - sum[l - 1]) {
			minn = sum[r] - sum[l - 1];
			lastl = l;
			lastr = r;
		}
	}
	int p = a[lastl];
	for (int i = lastl; i <= lastr; i++) {
		p &= a[i];
	}
	cout << max(maxn, max(p, maxx));
	return 0;
}