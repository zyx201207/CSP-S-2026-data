#include <bits/stdc++.h>
using namespace std;
int w[1000000];
int ki, sum;
int b[10000][10000];

struct zzz {
	int a;
	int t;
} k[10000];


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		sum += w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> ki;
		for (int j = 1; j <=  ki; j++) {
			cin >> k[j].a >> k[j].t ;
			b[i][j] = k[j].a;
		}
		int u, v;
		cin >> u >> v;
	}
	cout << sum;
	return 0;
}