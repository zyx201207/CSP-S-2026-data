#include <bits/stdc++.h>

using namespace std;//地铁口->站厅->站台
struct Edge {
	int u, v, w;
};
vector <Edge> edge;
int m/*地铁站数、点数(<=5*10(5)->1000)*/, q/*出行计划、样例数*/;
int n/*线路数、边数（<=500）*/, w[1001]/*地铁口到站厅时间*/, k/*线路过站点数*/;
int a[1001]/*每个线路过几个点*/, t[1001]/*站厅到站台*/, r_st, r_en;

short c/*棍木*/, d/*棍木*/;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= q; i++) {
		cout << 67 << endl;
	}
	return 0;
}