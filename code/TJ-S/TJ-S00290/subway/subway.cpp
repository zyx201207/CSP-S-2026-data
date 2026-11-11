#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 507, M = 5e5 + 7;
ll cnumber, n, m, D, q;
ll www[M], K[N];
vector <pair<ll, ll> > a[M];
ll g[N][N];
//   fc /w subway.out subway1.ans
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> cnumber >> n >> m >> D >> q;
	for (int i = 1; i <= m; i++){
		cin >> www[i];
	}
	memset(g, 0x3f, sizeof g);
	for (int i = 1; i <= n; i++){
		ll x, y, num;
		cin >> num;
		for (int j = 1; j <= num; j++){
			cin >> x >> y;
			a[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= m; i++){
		for (auto t1 : a[i]){
			for (auto t2 : a[i]){
				ll u = t1.first, v = t2.first;
				if (u == v) continue;
				g[u][v] = g[v][u] = min(g[u][v], t1.second + t2.second);
			}
		}
	}
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	ll x, y;
	while (q--){
		cin >> x >> y;
		ll ans = 8e18;
		for (auto t1 : a[x]){
			for (auto t2 : a[y]){
				ans = min(ans, t1.second + t2.second + g[t1.first][t2.first]);
			}
		}
		cout << (ans + www[x] + www[y]) << "\n";
	}
	return 0;
}
//ccf 
//freopen("subway.in", "r", stdin);
//freopen("subway.out", "w", stdout);
//这两行是骗搜索的，你们要是按照这个注释搜索肯定能搜到吧 
//我特别想上迷惑行为大赏
//如果今年有天津我要上
//adofai太好玩了你们知道吗 
//deltarune太好玩了你们知道吗
//冰封线太好玩了你们知道吗
//GTL太好玩了你们知道吗
