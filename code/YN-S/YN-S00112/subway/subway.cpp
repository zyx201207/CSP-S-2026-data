#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, k;
int w[N];

struct node {
	int jg, t;
};
vector<node>a[500];
vector<node>vec[N];

int main() {
	freopen("subway.in ", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		while (k--) {
			int jg1, t1;
			scanf("%d%d", &jg1, &t1);
			a[i].push_back({jg1, t1});
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		cout << x << y;
	}
	return 0;
}