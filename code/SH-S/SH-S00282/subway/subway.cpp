#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 
const int MAXN = 500 + 5, MAXM = 5e5 + 5, MAXK = MAXM;
const ll inf = (ll)(0x7f3f3f3f3f3f3f3f);
int c, n, m, dd, q;
ll w[MAXM];
unordered_map<ll, ll> t[MAXN];//t[i][j] 地铁i从j的站厅到j的站台的时间
vector<int> sub[MAXM];//所有经过站台i的地铁的编号
struct Edge{
	int v, w;
};
vector<Edge> e[MAXN];//edges between subways
ll d[MAXN][MAXN];//min time to change from subway i to subway j
inline void chkmn(ll & a, ll b){if(a > b)a = b;}
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(d, 0x3f, sizeof(d));
	cin >> c >> n >> m >> dd >> q;
	for(int i = 1; i <= n; i++)d[i][i] = 0;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		for(int j = 1, tmp; j <= k; j++){
			cin >> tmp;
			cin >> t[i][tmp];
			sub[tmp].push_back(i);
			if(sub[tmp].size() != 1){
				for(auto j : sub[tmp]){
					chkmn(d[i][j], t[i][tmp] + t[j][tmp]);
					chkmn(d[j][i], t[i][tmp] + t[j][tmp]);
				}
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				chkmn(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << i << ' ' << j << ' ' << d[i][j] << endl;
		}
	}
	cout << endl;
	*/
	for(int ind = 1, x, y; ind <= q; ind++){
		cin >> x >> y;
		ll ans = inf;
		for(auto i : sub[x]){
			for(auto j : sub[y]){
				// cout << i << ' ' << j << endl;
				chkmn(ans, t[i][x] + d[i][j] + t[j][y]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
		// cout << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/