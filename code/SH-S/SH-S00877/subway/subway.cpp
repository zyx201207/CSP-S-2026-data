#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<pair<int, long long>> v[500005];
long long o[500005], g[505][505];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)cin >> o[i];
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%lld", &k);
		for(int j = 1;j <= k; j++){
			int t, c;
			scanf("%lld %lld", &t, &c);
			v[t].push_back({i, c});
		}
	}
	memset(g, 0x3f, sizeof g);
	for(int i = 1; i <= m; i++){
		int x = v[i].size();
		for(int j = 0; j < x; j++){
			for(int k = j+1; k < x; k++){
				g[v[i][j].first][v[i][k].first] = min(g[v[i][j].first][v[i][k].first], v[i][j].second+v[i][k].second);
				g[v[i][k].first][v[i][j].first] = g[v[i][j].first][v[i][k].first];
			}
		}
	}
	for(int i = 1; i <= n; i++)g[i][i] = 0;
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);
		long long res = 0x3f3f3f3f3f3f3f3f;
		for(auto x : v[a]){
			for(auto u : v[b]){
				res = min(g[x.first][u.first]+x.second+u.second, res);
			}
		}
		res += o[a]+o[b];
		printf("%lld\n", res);
	}
}
