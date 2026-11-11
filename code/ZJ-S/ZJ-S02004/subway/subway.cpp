#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1005, N = 505; 
int c, n, m, d, q;
int w[20005], a[M], s, r;
ll t[N][M], dis[M][M];
bool gt[N][M];
void dijskra () {
	//
}
void bfs (int st, int en) {
	//for (int i = 1; i <= n)
	
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= 1e3; i++) {
		for (int j = 1; j <= 1e3; j++) dis[i][j] = LLONG_MAX;
		dis[i][i] = 0;
	}
	int k, sizBx;
	bool sizB = true;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j];
			cin >> t[i][a[j]];
			if (i == 1 && j == 1) sizBx = t[i][a[j]];
			if (i != 1 && j != 1 && t[i][a[j]] != sizBx) sizB = false;
			gt[i][a[j]] = 1;
		//	for (int l = 1; l <= j; l++) dis[a[l]][a[j]] = dis[a[j]][a[l]] = 0;
		}
	}
	if (sizB) {
		for (int i = 1; i <= q; i++) {
			cin >> s >> r;
		//	dfs(s, r);
			cout << 2 * sizBx + w[r] + w[s] << "\n";
		}
		return 0;
	}
	for (k = 1; k <= n; k++) 
		for (int i = 1; i <= m; i++) 
			for (int j = 1; j <= m; j++) 
				if (gt[k][i] && gt[k][j]) dis[i][j] = min(dis[i][j], t[k][i] + t[k][j]);
	for (k = 1; k <= m; k++) 
		for (int i = 1; i <= m; i++) 
			for (int j = 1; j <= m; j++) 
				if (dis[i][k] < LLONG_MAX && dis[j][k] < LLONG_MAX) 
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= q; i++) {
		cin >> s >> r;
		cout /*<< dis[s][r] << " " << w[s] << " " << w[r] << " "*/<< dis[s][r] + w[s] + w[r] << "\n";
	}/*
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) cout << dis[i][j] << " ";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << t[i][j] << " ";
		cout << "\n";
	}*/
 	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
