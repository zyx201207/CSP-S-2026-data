#include <bits/stdc++.h>
using namespace std;

int tt[500005];

int a[500005], t[500005];
struct edge {
	int x, y, z;
} e[500005];

int flag[500005] = {0};
int from = 0, to = 0;
int ie = 1;

bool cmp(const edge &a, const edge &b) {
	return a.z < b.z;
}

int hs(int tp, int sum, int i) {
	if (tp == to) {
		return sum;
	}
	if (i > ie) {
		return sum;
	}
	if (e[i].x == tp && flag == 0 ) {
		flag[i] = 1;
		return hs(e[ie].y, sum + e[ie].z, ++i);
	}
	if (e[i].y == tp && flag == 0 ) {
		flag[i] = 1;
		return hs(e[ie].x, sum + e[ie].z, ++i);
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	int sum = 0;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> tt[i];
	}
	for (int i = 1; i <= n; i++) {
		int k = 0;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j <= k; j++) {
			for (int b = j + 1; b <= k; b++) {
				e[ie].x = min(a[j], a[b]);
				e[ie].y = max(a[j], a[b]);
				e[ie].z = t[j] + t[b];
				ie++;
			}
		}
	}
	sort(e, e + ie + 1, cmp);
	while (q--) {
		cin >> from >> to;
		sum += tt[from] + tt[to];
		flag[500005] = {0};
		sum = hs(from, sum, 1);
	}
	cout << sum;
	return 0;
}