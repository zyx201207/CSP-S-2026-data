#include <bits/stdc++.h>

using namespace std;

constexpr int N = 50;
int c,t,f[N][N],fa[N],u[N],v[N];
std::vector<int> e[N];

inline int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
inline void merge(int u,int v){
	fa[find(u)] = find(v);
}
inline void solve(){
	int n,K;
	std::cin >> n >> K;
	for(int i = 1; i <= n; ++ i) e[i].clear();
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <=n;++ j) f[i][j] =1e9;
		f[i][i] = 0;
	}
	for(int i = 1; i < n; ++ i){
		std::cin>>u[i] >> v[i];
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
		f[u[i]][v[i]] =f[v[i]][u[i]]=1;
	}
	for(int k = 1; k <= n; ++ k){
		for(int i = 1; i <= n;++ i){
			for(int j = 1; j <= n; ++ j){
				f[i][j] = std::min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i < (1 << n); ++ i){
		int cnt = 0;
		for(int j = 0; j < n; ++ j){
			cnt += i >> j & 1;
		}
		if(cnt != K) continue;
		for(int j = 1; j <= n; ++ j) fa[j] = j;
		for(int j =1; j<n; ++ j){
			if((i >> (u[j] - 1) & 1) && (i >> (v[j] - 1) & 1)){
				merge(u[j],v[j]);
			}
		}
		int sz= 0;
		for(int j = 1; j <= n; ++ j){
			if((i >> (j - 1) & 1)){
				if(j == find(j)) ++sz;
			}
		}
		if(sz != 2) continue;
		int Max  = 0;
		for(int j = 1; j <= n; ++ j){
			if(!(i >> (j - 1) &1)){
				int Min = 1e9;
				for(int k = 1; k <= n; ++ k){
					if((i >> (k - 1) & 1)){
						Min = std::min(Min,f[j][k]);
					}
				}
				Max  = std::max(Max,Min);
			}
		}
		ans = std::min(ans,Max);
	}
	std::cout << ans << '\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> c >> t;
	while(t -- ){
		solve();
	}
	return 0;
}
