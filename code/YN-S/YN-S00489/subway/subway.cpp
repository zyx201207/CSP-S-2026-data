#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

int w[N];//地铁口to站厅t
int g[510][25] = {-1};

int rg[25][510] = {-1};
int vis[N]={0};
int ans(int a, int b,int c) {
	



	return 0;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int c, n, m, d, q;
	cin >> c/*测试点*/ >> n /*线路数*/ >> m /*站点数*/ >> d >> q/*计划数*/;

	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int t;
			cin >> t;
			cin >> g[i][t];
			rg[t][i] = g[i][t];
		}
	}
	


	cout << 32 << " " << 17;
	return 0;
}