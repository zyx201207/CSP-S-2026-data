#include <bits/stdc++.h>
using namespace std;
const int M = 5 * 10e5+10, N = 510, D = 30;
int c, n, m, d,
    q, ans; //分别是测试点(无实际意义），路线数，地铁站总数，每个站点至多被d个路线经过），旅游计划数（即第几站到第几站
int w[M];//每个地铁口的出站的时间

struct sw {
	int num;//该路线的地铁站数
	int zc[D], ti[D]; //zc：第几站 ti：地铁口至大厅的时间
} a[N];

struct zsw {
	int lu[D];
} b[N];


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num;
		for (int j = 1; j <= a[i].num; j++) {
			int z, t;
			cin >> z >> t;
			a[i].zc[z] = z;
			a[i].ti[z] = t;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ans = w[x] + w[y];
//		int xw, yw; //x,y分别所在线路
		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= a[i].num; j++) {
				if (a[i].zc[j] == x) {
					b[x].lu[i] = i;
				}
				if (a[i].zc[j] == y) {
					b[y].lu[i] = i;
				}
			}
		}
		int l;
		for (int i = 1; i <= m; i++) {
			if (b[x].lu[i] == b[y].lu[i] && b[x].lu[i] != 0 && b[y].lu[i] != 0) {
				l = b[x].lu[i];
//				cout << l << "\n";

			}
		}
		ans += a[l].ti[x] + a[l].ti[y];
		cout << ans << "\n";
	}

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/