#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool M1;
const int N = 510;
const int M = 5e5 + 10;
const ll Linf = 1e18;
int c, n, m, d, q, w[M];
ll f[N][N];
vector<pair<int, int> > vec[M];
bool M2;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; cin >> w[i ++] ) ;
	for (int i = 1, k; i <= n; i++){
		cin >> k;
		for (int j = 1, a, t; j <= k; j++){
			cin >> a >> t, vec[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; f[i][j ++] = Linf) ;
		f[i][i] = 0;
	}
	for (int x = 1; x <= m; x++){
		for (int i = 0; i < vec[x].size(); i++){
			for (int j = i + 1; j < vec[x].size(); j++){
				int idx, tx, idy, ty;
				tie(idx, tx) = vec[x][i]; tie(idy, ty) = vec[x][j];
				f[idx][idy] = min(f[idx][idy], (ll)tx + ty);
				f[idy][idx] = min(f[idy][idx], (ll)tx + ty);
			}
		}
	}
	for (int k = 1; k <= n; k++){
		for (int x = 1; x <= n; x++){
			for (int y = 1; y <= n; y++){
				f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
			}
		}
	}
	for (int i = 1, x, y; i <= q; i++){
		cin >> x >> y;
		ll res = Linf;
		for (auto px : vec[x]) for (auto py : vec[y]){
			int idx, tx, idy, ty; tie(idx, tx) = px; tie(idy, ty) = py; 
			res = min(res, tx + ty + f[idx][idy]);
		}
		cout << res + w[x] + w[y] << '\n' ;
	}
	cerr << 1000 * clock() / CLOCKS_PER_SEC << " MS\n" ;
	cerr << 1.0 * fabs(&M1 - &M2) / 1024 / 1024 << " MB\n" ;
	return 0;
}
