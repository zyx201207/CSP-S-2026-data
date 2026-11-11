#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '\n'
const int N = 5e2 + 10, M = 5e5 + 10;
int c, n, m, d, p, w[M], k[N], a[N][M], t[N][M], x, y;
vector<int>G[M];

//int find(int a, int b) {
//	for (int i = 1; i <= n; i++) {
//		bool flag = 0, fl = 0, e, f;
//		for (int j = 1; j <= k[i]; j++) {
//			if (a[i][j] == x)
//				flag = 1, e = j, start = (start ? 0 : 1);
//			if (a[i][j] == y)
//				fl = 2, f = j, start = (start ? 0 : 1);
//		}
//		if (flag && fl) {
//			return a[i][e] + a[i][f];
//		}
//	}
//}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k; j++)
			cin >> a[i][j] >> t[i][j], G[a[i][j]].push_back(i);
	}
	while (p--) {
		cin >> x >> y;
		cout << w[x] + w[y] << endl;
	}
	return 0;
}
