#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool M1;
const int N = 2e6 + 10;
int c, T, n, to[N], f[N], g[N];
ll d, x[N], res;
vector<int> vec[N];
void solve(){
	cin >> n >> d, res = 0;
	for (int i = 1; i <= n; cin >> x[i ++] ) ;
	for (int i = 1, j = 1; i <= n; i++){
		while (j < n && x[j + 1] <= x[i] + d) j ++ ;
		to[i] = j, vec[j].push_back(i);
	}
	for (int i = 1; i <= n; i++){
		if (! vec[i].size()) continue;
		f[i] = vec[i].size();
		if (to[vec[i][0] - 1] < i) f[i] += f[vec[i][0]];
	}
	for (int i = n; i >= 1; i--){
		g[i] = to[i] - to[i - 1];
		if (to[i - 1] < to[i]) g[i] += g[to[i]];
	}
	for (int i = 2; i < n; i++){
		if (to[i] == i || ! vec[i].size()) continue;
		int o = vec[i].front(), x = vec[i].size();
		if (to[o - 1] < i - 1) x += f[o];
		int y = to[i - 1] - max(i, to[i - 2]);
		if (to[i - 1] == to[i] && to[i - 2] < to[i]) y += g[to[i]];
		res += 1ll * x * y;
	}
	cout << res << '\n' ;
	for (int i = 1; i <= n; i++){
		f[i] = g[i] = 0, vec[i].clear();
	} 
}
bool M2;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T --> 0) solve();
	cerr << 1000 * clock() / CLOCKS_PER_SEC << " MS\n" ;
	cerr << 1.0 * fabs(&M1 - &M2) / 1024 / 1024 << " MB\n" ;
	return 0;
}
