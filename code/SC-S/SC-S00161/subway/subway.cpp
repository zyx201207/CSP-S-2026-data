#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int floyd[N][N];
int c, n, m, d, q;
int w[N];
struct node {
	int a, t;
} s[N][N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			floyd[i][j] = 0x3f3f3f3f;
		}
	}
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> s[i][j].a >> s[i][j].t;
			for (int o = 1; o < j; o++) {
				floyd[s[i][j].a][s[i][o].a] = s[i][j].t + s[i][o].t;
				floyd[s[i][o].a][s[i][j].a] = s[i][j].t + s[i][o].t;
			//	cout<<s[i][j].a<<" "<<s[i][o].a<<"\n";
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				floyd[j][i] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << floyd[x][y]+w[x]+w[y] << "\n";
	}
	return 0;
}