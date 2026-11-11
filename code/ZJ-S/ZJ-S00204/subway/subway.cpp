// O(n^3+qd^2),<=4e8.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int c, n, m, d, q, x, y;
int w[500005], k[505];
vector<pii> v[500505]; //u->v,w
ll dis[505][505];
void floyd() {
	for(int i = 1; i <= n; i++)
		dis[i][i] = 0;
//	for(int i = 1; i <= n; i++, cerr << '\n')
//		for(int j = 1; j <= n; j++)
//			cerr << dis[i][j] << ' ';
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//	for(int i = 1; i <= n; i++, cerr << '\n')
//		for(int j = 1; j <= n; j++)
//			cerr << dis[i][j] << ' ';
	return ;
}
ll calc(int x, int y) {
	ll minx = 1e18;
	for(pii i : v[x])
		for(pii j : v[y])
			minx = min(minx, i.second + j.second + dis[i.first - m][j.first - m]);
	return minx;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 0; j < k[i]; j++) {
			cin >> x >> y;
			v[i + m].push_back({x, y});
			v[x].push_back({i + m, y});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++)
		for(pii j : v[i + m])
			for(pii k : v[j.first])
				dis[i][k.first - m] = min(dis[i][k.first - m], (ll)j.second + k.second);
	floyd();
//	cerr << dis[3][5];
	while(q--)
		cin >> x >> y, cout << w[x] + w[y] + calc(x, y) << '\n';
	return 0;
}
/*
input:

ans:

*/
