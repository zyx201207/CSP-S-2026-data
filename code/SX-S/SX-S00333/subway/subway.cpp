#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[100005];
int k[550][100005];
int cnt = 0;

struct node {
	int a;
	int t;
} ki[500005];
int x1[100005];
int y2[100005];


int zdt(int x, int y) {

}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; k++) {
			cin >> ki[j].a >> ki[j].t;

		}
	}
	for (int jh = 1; jh <= q; jh++) {
		cin >> x1[jh] >> y2[jh];
		int x = x1[jh];
		int y = y2[jh];
		cnt = w[x] + w[y];
		int lo = zdt(x, y);
		cout << cnt << endl;
	}


	return 0;
}