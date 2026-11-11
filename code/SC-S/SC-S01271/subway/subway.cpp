#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 5e5+5;
ll c, n, m, d, q;
ll mp[5005][5005];
//void floyd(ll u, ll v) {
//	for (int i = 1; i <= 3 * m; i++)
//		for (int j = 1; j <= 3 * m; j++)
//			for (int k = 1; k <= 3 * m; k++)
//				if (mp[i][j] > mp[i][k] + mp[k][j])
//					mp[i][j] = mp[i][k] + mp[k][j];
//	cout << mp[u][v] << "\n";
//}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	memset(mp, 0x3f, sizeof(mp));
	for (int i = 1; i <= m; i++) {
		ll a;
		cin >> a;
		mp[i][m + i] = a;
		mp[m + i][i] = a;
	}
	for (int i = 1; i <= n; i++) {
		ll ki;
		cin >> ki;
		while (ki--) {
			ll a, t;
			cin >> a >> t;
			mp[a + m][2 * m + a] = t;
			mp[2 * m + a][a + m] = t;
		}
	}
	for (int k = 1; k <= 3 * m; k++)
		for (int i = 1; i <= 3 * m; i++)
			for (int j = 1; j <= 3 * m; j++)
				if (mp[i][j] > mp[i][k] + mp[k][j])
					mp[i][j] = mp[i][k] + mp[k][j];
	while (q--) {
		ll u, v;
		cin >> u >> v;
		cout << mp[u][v] << "\n";
	}
	return 0;
}