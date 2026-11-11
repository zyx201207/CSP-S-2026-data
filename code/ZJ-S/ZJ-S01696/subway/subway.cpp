#include<bits/stdc++.h>
#define ll long long
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

int c, n, m, d, q;
int u, v;
int K;
int A;
ll T;
std::vector<int> a[505];
std::vector<ll> t[505];
ll w[500005];
int pass[500005][25];
ll mp[505][505];
ll t1, t2;
ll Ans;

void Floyd() {
	for(int k = 1; k <= n; k ++) 
		for(int i = 1; i <= n; i ++) 
			for(int j = 1; j <= n; j ++) 
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) std::cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		std::cin >> K;
		a[i].push_back(K), t[i].push_back(K);
		for(int j = 1; j <= K; j ++) {
			std::cin >> A >> T;
			a[i].push_back(A), t[i].push_back(T);
			pass[a[i][j]][++ pass[a[i][j]][0]] = i;
		}
	}
	
	for(int i = 1; i <= n; i ++) 
		for(int j = 1; j <= n; j ++) 
			if(i != j) 
				mp[i][j] = 1e18;
	for(int i = 1; i <= n; i ++) 
		for(int j = 1; j <= a[i][0]; j ++) 
			for(int k = 1; k <= pass[a[i][j]][0]; k ++) 
				if(pass[a[i][j]][k] != i) {
					int l;
					for(l = 1; l <= a[pass[a[i][j]][k]][0]; l ++) 
						if(a[pass[a[i][j]][k]][l] == a[i][j]) 
							break;
					mp[i][pass[a[i][j]][k]] = min(mp[i][pass[a[i][j]][k]], t[i][j] + t[pass[a[i][j]][k]][l]);
				}
	Floyd();
	
	while(q --> 0) {
		std::cin >> u >> v;
		Ans = 1e18;
		for(int i = 1; i <= pass[u][0]; i ++) 
			for(int j = 1; j <= pass[v][0]; j ++) {
				for(int k = 1; k <= a[pass[u][i]][0]; k ++) 
					if(a[pass[u][i]][k] == u) {
						t1 = t[pass[u][i]][k];
						break;
					}
				for(int k = 1; k <= a[pass[v][j]][0]; k ++) 
					if(a[pass[v][j]][k] == v) {
						t2 = t[pass[v][j]][k];
						break;
					}
				Ans = min(Ans, mp[pass[u][i]][pass[v][j]] + t1 + t2);
			}
		std::cout << Ans + w[u] + w[v] <<'\n';
	}
	return 0;
}
