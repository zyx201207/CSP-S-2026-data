#include <bits/stdc++.h>

// 15:18过小样例！ 
using namespace std;

#define int long long 

constexpr int N = 5e5 + 5,M = 505;

int f[M][M],c,n,m,d,q,w[N];
std::vector<std::pair<int,int> > e[N];

// e[i] -> (u,v) u号线，v时间 

signed main(){	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++ i){
		std::cin >> w[i];
	}
	for(int i = 1; i <= n; ++ i){
		int k,x,v;
		std::cin >> k;
		while(k -- ){
			std::cin >> x >> v;
			e[x].push_back(std::make_pair(i,v));
		}
	}
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	}
	for(int i = 1; i <= m; ++ i){
		for(auto u : e[i]){
			int x = u.first,val = u.second;
			for(auto v : e[i]){
				int y = v.first,val2 = v.second;
				f[x][y] = std::min(f[x][y],val + val2);
			}
		}
	}
	for(int k = 1; k <= n; ++ k){
		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= n; ++ j){
				f[i][j] = std::min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	while(q -- ){
		int x,y,ans = 1e18;
		std::cin >> x >> y;
		for(auto u : e[x]){
			int a = u.first,b = u.second;
			for(auto v : e[y]){
				int A = v.first,B = v.second;
				ans = std::min(ans,b + B + f[a][A]);
			}
		}
		std::cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
