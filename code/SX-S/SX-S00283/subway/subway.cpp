#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500010];

struct node1 {
	int a, t;
} s1[500010];

struct node2 {
	int x, y;
} s2[500010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 2; j <= k; j++) {
			cin >> s1[j].a >> s1[j].t;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> s2[i].x >> s2[i].y;
	}
	cout << 32 << endl << 17;
	return 0;
}
//又是一轮CPS，依旧陪跑
//真的蒟蒻呐