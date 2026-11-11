#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define p_b push_back

const int N = 5e2+5, M = 1e3+5, Q = 1e5+5;
const ll MAX = 1e14;
int c, n, m, d, q, k[N], a[N][M], x[Q], y[Q];
ll t[N][M], st[N][M], D[M][M], w[M];

signed main() 
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >>	w[i];
	for (int i = 1; i <= n; ++i) { 
		cin >> k[i]; 
		for (int j = 1; j <= k[i]; ++j) {
			cin >> a[i][j] >> t[i][j]; 
			st[i][j] = st[i][j-1] + t[i][j];
		}
	}
	for (int i = 1; i <= q; ++i) cin >> x[i] >> y[i];
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= m; ++j) D[i][j] = -1;
	for (int i = 1; i <= m; ++i) D[i][i] = 0;
	for (int z = 1; z <= n; ++z) 
		for (int i = 1; i <= k[z]; ++i) for (int j = i+1; j <= k[z]; ++j) {
			int u = a[z][i], v = a[z][j];
			if (D[u][v] == -1) D[u][v] = t[z][j] + t[z][i];
			else D[u][v] = min(D[u][v], t[z][j] + t[z][i]);
			if (D[v][u] == -1) D[v][u] = t[z][j] + t[z][i];
			else D[v][u] = min(D[v][u], t[z][j] + t[z][i]);
		}
	for (int i = 1; i <= m; ++i) for (int k = 1; k <= m; ++k) for (int j = 1; j <= m; ++j) {
		if (D[i][k]!=-1 && D[k][j]!=-1 && D[i][j]!=-1) D[i][j] = min(D[i][j], D[i][k] + D[k][j]); 
		if (D[i][k]!=-1 && D[k][j]!=-1 && D[i][j]==-1) D[i][j] = D[i][k] + D[k][j];
	}
	for (int i = 1; i <= q; ++i) printf("%lld\n", D[x[i]][y[i]] + w[x[i]] + w[y[i]]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}









/*

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define p_b push_back

const int N = 5e2+5, M = 1e3+5, Q = 1e5+5;
const ll MAX = 1e14;
int c, n, m, d, q, k[N], a[N][M], x[Q], y[Q], Au[N][N], Av[N][N];
ll t[N][M], D[N][N], w[M];
vector <int> wy[N], wyi[N];

signed main() 
{
	freopen("subway1.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >>	w[i];
	for (int i = 1; i <= n; ++i) { 
		cin >> k[i]; 
		for (int j = 1; j <= k[i]; ++j) {
			cin >> a[i][j] >> t[i][j]; 
			wy[a[i][j]].p_b(i);
			wyi[a[i][j]].p_b(j);
		}
	}
	for (int i = 1; i <= q; ++i) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) D[i][j] = -1;
	for (int i = 1; i <= n; ++i) D[i][i] = 0;
	for (int z = 1; z <= m; ++z) {
		for (int i = 0; i < wy[z].size(); ++i) for (int j = i+1; j < wy[z].size(); ++j) {
			
			int u = wy[z][i], v = wy[z][j];
			D[u][v] = D[u][v] == -1 ? t[u][wyi[z][i]] + t[v][wyi[z][j]] : min(D[u][v], t[u][wyi[z][i]] + t[v][wyi[z][j]]);
//			Au[u][v] = D[u][v] == -1 || (D[u][v] && t[u][wyi[z][i]] + t[v][wyi[z][j]]) ? z : A[u][v];
//			Av[u][v] = D[u][v] == -1 || (D[u][v] && t[u][wyi[z][i]] + t[v][wyi[z][j]]) ? z : A[u][v];
			D[v][u] = D[v][u] == -1 ? t[u][wyi[z][i]] + t[v][wyi[z][j]] : min(D[v][u], t[u][wyi[z][i]] + t[v][wyi[z][j]]);
//			Au[v][u] = D[v][u] == -1 || (D[v][u] && t[u][wyi[z][i]] + t[v][wyi[z][j]]) ? z : A[v][u];
//			Av[v][u] = D[v][u] == -1 || (D[v][u] && t[u][wyi[z][i]] + t[v][wyi[z][j]]) ? z : A[v][u];
		}
	}
	
//	printf("%d %d %d %d\n", D[1][2], D[2][1]);
	
	
	
	for (int k = 1; k <= n; ++k) for (int u = 1; u <= n; ++u) for (int v = 1; v <= n; ++v) {
		D[u][v] = D[u][v] == -1 ? D[u][k] + D[k][v] : min(D[u][v], D[u][k] + D[k][v]);
//		Au[u][v] = D[u][v] == -1 || (D[u][v] && t[u][wyi[z][i]] + t[v][wyi[z][j]]) ? z : A[u][v];
	}
	
		
	for (int u = 1; u <= n; ++u) for (int v = 1; v <= n; ++v) printf("%d %d %lld\n", u, v, D[u][v]);
	for (int z = 1; z <= q; ++z) {
		ll res = LLONG_MAX;
		for (int i = 0; i < wy[x[z]].size(); ++i) for (int j = 0; j < wy[y[z]].size(); ++j) {
			int u = wy[z][i], v = wy[z][j];
			res = min(res, D[u][v] + w[x[z]] + w[y[z]] + t[u][wyi[x[z]][i]] + t[v][wyi[y[z]][j]]);
		}
			
		printf("%lld\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


*/