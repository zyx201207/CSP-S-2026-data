#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 + 3 ,  M = 5e5 + 3;
int a[M] , d[N][N];
vector<pair<int , int> > pos[M]; 
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out", "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c , n , m , dd  ,q;
	cin >> c >> n >> m >> dd >> q;
	for(int i = 1; i <= m; ++ i) cin >> a[i]; 
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			if(i == j) d[i][j] = 0;
			else d[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= n ;++ i){
		int k; cin >> k;
		vector<pair<int , int> > v;
		for(int j = 1; j <= k; ++ j){
			int x , y; cin >> x >> y;
			pos[x] . emplace_back(i , y);
		}
	}
	for(int x = 1; x <= m; ++ x){
		int len = pos[x] . size();
		for(int i = 0; i < len; ++ i){
			for(int j = 0; j < len; ++ j){
				d[pos[x][i] . first][pos[x][j] . first] = min(d[pos[x][i] . first][pos[x][j] . first] , pos[x][i] . second + pos[x][j] .second);
			}
		}
	} 
	for(int k = 1; k <= n; ++ k){
		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= n; ++ j){
				d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
			}
		}
	}
	while(q --){
		int u , v; cin >> u >> v;
		int ans = 1e18;
		for(auto x : pos[u]){
			for(auto y : pos[v]){
				ans = min(ans , d[x . first][y . first] + x. second + y . second);		
			}
		}
		cout << ans + a[u] + a[v] << '\n';
	}
	return 0;
}

