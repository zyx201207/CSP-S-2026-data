#include <bits/stdc++.h>
using namespace std;
map<int, int> t;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q; //测试点编号，地铁线数，地铁站数，一站至多被几条地铁线穿过，计划数
	int w[m + 3]; //每个地铁口走到站厅的时间
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int nn;
		cin >> nn;
		for (int j = 1; j <= nn; j++) {
			int ii, jj;
			cin >> ii >> jj;
			t[ii] = jj;
		}
	}




	return 0;
}
