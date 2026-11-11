#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q;

struct node {
	int u, v, w;
};
vector<node> g[N];
int a[N], t[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	while (c--) {
		cin >> n >> m >> d >> q;
		for (int i = 1; i <= m; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			for (int j = 1; j <= x; j++)
				cin >> a[i] >> t[i];
		}
	}
	return 0;
}