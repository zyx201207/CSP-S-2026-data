#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
typedef long long ll;

struct node {
	ll id, w, t, link[2000], s = 1;
} a[N]; //a代表m,id代表编号，w代表站口到站厅，t代表站厅到站台，link代表联通隧道,s代表联通站点数；
int c, n, m, d, q, lx = 1;

int qwe(int x, int y, int k) {
	if (x == y) {
		return k + a[x].w;
	}

	if (a[x].s == 1) {
		k += a[x].t;
		return qwe(a[x].link[1], y, k + a[x].t);
	}

	if (a[x].s == 2) {
		k += a[x].t;
		return min(qwe(a[x].link[1], y, k + a[x].t), qwe(a[x].link[2], y, k + a[x].t));

	}


}

int main() {//每条线路至多经过 2 个地铁站,ki ≤ 2,对于所有线路经过的所有地铁站，从站厅走到对应线路站台的步行时间都相同
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> a[i].w;
		a[i].id = i;
	}

	for (int i = 1; i <= n; i++) {

		int ki;
		cin >> ki;

		if (ki > 2)
			lx = 0;

		for (int j = 1; j <= ki; j++) {

			int y;
			cin >> y;
			a[y].link[a[y].s] = i;
			a[y].s++;
			cin >> a[y].t;

		}
	}

	if (lx == 0) { //特殊性质A;
		while (q--) {
			int x, y;
			cin >> x >> y;
			int ans = qwe(x, y, a[x].w);
			cout << ans << endl;
		}
	}




	return 0;
}