#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<bitset>

using namespace std;
const int N = 500 + 1, M = 5e5 + 1, D = 21;
#define ll long long
#define endl '\n'
ll f[N][N]; // i < j
int t[M][D], idx[M][D], cnt[M], w[M], u, v, k, a, T;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a >> T;
			cnt[a]++;
			t[a][cnt[a]] = T;
			idx[a][cnt[a]] = i;
		}
		
		// ≥ı ºªØ f 
		for(int j = i + 1; j <= n; j++)
			f[i][j] = 4e18;
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j < cnt[i]; j++)
			for(int k = j+1; k <= cnt[i]; k++) {
				u = idx[i][j], v = idx[i][k];
				if(u > v) swap(u, v);
				f[u][v] = min(f[u][v], (ll)t[i][j] + t[i][k]);
			}
	}
	
	// Floyd
	for(int k = 1; k <= n; k++)
		for(int i = 1; i < n; i++)
			if(i != k)
				for(int j = i + 1; j <= n; j++)
					f[i][j] = min(f[i][j], f[min(i, k)][max(i, k)] + f[min(j, k)][max(j, k)]);
					
	// Query
	while(q--) {
		int x, y; cin >> x >> y;
		ll ans = 9e18;
		for(int i = 1; i <= cnt[x]; i++)
			for(int j = 1; j <= cnt[y]; j++) {
				u = idx[x][i], v = idx[y][j];
				if(u > v) swap(u, v);
				ans = min(ans, (ll)t[x][i] + t[y][j] + f[u][v]);
			}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}

