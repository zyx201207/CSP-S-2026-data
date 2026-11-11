// rp++
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct sta {
	int w;
	vector<int> a, t;
};
vector<sta> subway_map;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	subway_map.resize(m+1);
	for (int i=1; i<=m; i++) {
		cin >> subway_map[i].w;
	}
	for (int i=1; i<=n; i++) {
		int k;
		cin >> k;
		int cur_a, cur_t, lst_a, lst_t;
		cin >> lst_a >> lst_t;
		subway_map[lst_a].t.puch_back(lst.t);
		for (int j=1; j<=k; j++) {
			cin >> cur_a >> cur_t;
			subway_map[lst_a].a.push_back(cur_a);
			subway_map[cur_a].a.push_back(lst_a);
			subway_map[cur_a].t.puch_back(cur_t);
		}
	}
	return 0;
}
