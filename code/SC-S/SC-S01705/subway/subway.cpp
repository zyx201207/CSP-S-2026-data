#include<bits/stdc++.h>
using namespace std;
struct ppppp {
	int a, t;
	ppppp(int x = 0, int y = 0) {
		a = x, t = y;
	}
};
long long c, n, m, d, q;
long long w[501], tiaon[200001];
vector<ppppp>a[501];
vector<int>e[501];
int b[501][501];
int f[501][501];//邻接表
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++)cin >> w[i];
	for (int i = 1; i <= m; i++) {
		cin >> tiaon[i];
		for (int j = 1, x, y; j <= tiaon[i]; j++) {
			cin >> x >> y;
			a[i].push_back(ppppp(x, y));
		}
		for (ppppp a1 : a[i])
			for (ppppp a2 : a[i])
				if (a1.a != a2.a)e[a2.a].push_back(a1.a), b[a1.a][a2.a] = (b[a1.a][a2.a] == 0 ? a1.t + a2.t : min(b[a1.a][a2.a], a1.t + a2.t));
	}
	for (int i = 1; i <= n; i++) {
		queue<int>ppp;
		ppp.push(i);
		while (!ppp.empty()) {
			int now = ppp.front();
			ppp.pop();
			for (int j : e[now]) {
				if (f[i][now] + b[now][j] < f[i][j] || f[i][j] == 0) {
					ppp.push(j);
					f[i][j] = f[i][now] + b[now][j];
				}
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << f[x][y] + w[x] + w[y] << endl;
	}
}