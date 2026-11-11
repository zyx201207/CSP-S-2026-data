#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 505, M = 5e5 + 5;
const ll INF = 1e18;

int c, n, m, d, q, a[M];
pair<int, int> vis[M][25];
int ct[M];
ll f[N][N];

void chkmin(ll &x, ll y){
	x = min(x, y);
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		for(int j = 1, x, y; j <= k; j++){
			cin >> x >> y;
			vis[x][++ct[x]] = {i, y};
		}
	}
	fill(&f[0][0], &f[n][n] + 1, INF);
	for(int i = 1; i <= n; i++)
		f[i][i] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= ct[i]; j++)
			for(int k = 1; k <= ct[i]; k++)
				chkmin(f[vis[i][j].first][vis[i][k].first], vis[i][j].second + vis[i][k].second);
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++)
	// 		cout << f[i][j] << ' ';
	// 	cout << '\n';
	// }
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				chkmin(f[j][k], f[j][i] + f[i][k]);
	// for(int i = 1; i <= m; i++)
	// 	cout << ct[i] << ' ';
	// cout << '\n';
	for(int i = 1, x, y; i <= q; i++){
		cin >> x >> y;
		ll ans = INF;
		// assert(ct[x] <= d && ct[y] <= d);
		for(int j = 1; j <= ct[x]; j++)
			for(int k = 1; k <= ct[y]; k++)
				ans = min(ans, vis[x][j].second + vis[y][k].second + f[vis[x][j].first][vis[y][k].first]);
		// cout << ans << '\n';
		cout << ans + a[x] + a[y] << '\n';
	}
	return 0;
}