#include<bits/stdc++.h>
using namespace std;

#define int long long


const int N = 507, M = 500007, inf = 1e16 + 7;
int c, n, m, D, q;
int etr[M];
vector<int> stp[M], w[M];
int d[N][N];


signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	cin >> c >> n >> m >> D >> q;
	for(int i=1; i<=m; i++) cin >> etr[i];
	for(int i=1; i<=n; i++) {
		int k; cin >> k;
		while(k--) {
			int s, wst; cin >> s >> wst;
			stp[s].push_back(i);
			w[s].push_back(wst);
		}
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(i != j) d[i][j] = inf;
	for(int s=1; s<=m; s++) {
		for(int i=0; i<stp[s].size(); i++)
			for(int j=i+1; j<stp[s].size(); j++) {
				d[stp[s][i]][stp[s][j]] = min(d[stp[s][i]][stp[s][j]], w[s][i] + w[s][j]);
				d[stp[s][j]][stp[s][i]] = min(d[stp[s][j]][stp[s][i]], w[s][i] + w[s][j]);
			}
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//	for(int i=1; i<=n; i++, cout<<endl)
//		for(int j=1; j<=n; j++)
//			cout << d[i][j] << ' ';
	while(q--) {
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for(int i=0; i<stp[x].size(); i++)
			for(int j=0; j<stp[y].size(); j++) 
				ans = min(ans, etr[x] + w[x][i] + d[stp[x][i]][stp[y][j]] + w[y][j] + etr[y]);
		cout << ans << '\n';
	}
	return 0;
}
