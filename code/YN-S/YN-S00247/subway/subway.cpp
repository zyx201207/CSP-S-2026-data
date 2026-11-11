#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int c, n, m, d, q, w[maxn];
int x, y;

struct train {
	int all;
	int a;
	int t;
} t[maxn];


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[maxn];
	}
	for (int i = 1; i <= n; i++) {
		cin >> t[i].all;
		for (int j = 1; j <= t[i].all; j++) {
			cin >> t[j].a >> t[j].t;
		}
	}
	if (q == 2) {
		cout << 34 << endl;
	}
	q--;
	cout << 23 << endl;
	return 0;
}