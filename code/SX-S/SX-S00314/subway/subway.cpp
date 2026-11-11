#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define Inf 0x3f3f3f3f3f3f3f3f
ll c;//测试点
ll n;//地铁线路数
ll m;//地铁站数
ll d;//每个地铁站最多被几条线路经过
ll q;//出行计划数
ll w[500010];//地铁口<-->站厅 需要的时间
ll k[510];
ll a[1010][1010];
ll zh[510][1010], t[510][1010];
ll zd[1010][1010];

struct cxk {
	ll x, step;
};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(a, 0x3f, sizeof(a));
	memset(zd, 0x3f, sizeof(zd));
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		cin >> k[i];
		for (ll j = 1; j <= k[i]; j++) {
			cin >> zh[i][j] >> t[i][j];
		}
		for (ll j = 1; j <= k[i]; j++) {
			for (ll j1 = j + 1; j1 <= k[i]; j1++) {
				zd[zh[i][j]][zh[i][j1]] = zd[zh[i][j1]][zh[i][j]] = a[zh[i][j]][zh[i][j1]] = a[zh[i][j1]][zh[i][j]] = min(
				                              a[zh[i][j]][zh[i][j1]], t[i][j] + t[i][j1]);
			}
		}
	}
	for (ll i = 1; i <= m; i++) {
		for (ll k = i + 1; k + 1 <= m; k++) {
			for (ll j = k + 1; j <= m; j++) {
				if (zd[i][j] > zd[i][k] + zd[k][j]) {
					zd[i][j] = zd[j][i] = zd[i][k] + zd[k][j];
				}
			}
		}
	}

	while (q--) {
		ll xxx, yyy;
		cin >> xxx >> yyy;
		cout << zd[xxx][yyy] + w[xxx] + w[yyy] << endl;
	}
	return 0;
}