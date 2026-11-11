#include <bits/stdc++.h>
#define go(i,l,r) for(int i = l; i <= r; i++)
#define re(i,r,l) for(int i = r; i >= l; i--)
using namespace std;
using ll = long long;

const int N = 505, M = 5e5+5;
//  测试点 线数 站数 max n(交) 问数
int c,    n,  m,  D,        q;
int w[M]; //起止固定花费
ll d[N][N]; //两线互通花费
vector<pair<int,int>> g[M]; //各站包含的线路，以及到站台距离

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> c >> n >> m >> D >> q;
	go(i,1,m) cin >> w[i];
	go(i,1,n){
		int k; cin >> k;
		while(k--){
			int a, t;
			cin >> a >> t;
			g[a].push_back({i,t});
		}
	}
	
	memset(d, 0x3f, sizeof d);
	go(i,1,n) d[i][i] = 0;
	go(i,1,m){
		for(auto A: g[i])
			for(auto B: g[i]){
				int a = A.first, ta = A.second, b = B.first, tb = B.second;
				d[a][b] = min(d[a][b], (ll)ta + (ll)tb);
			}
	}
	
	//floyd
	go(k,1,n)
		go(i,1,n)
			go(j,1,n)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
	go(i,1,q){
		int u, v; ll mn = 1e18; 
		cin >> u >> v;
		for(auto A: g[u])
			for(auto B: g[v]){
				int a = A.first, ta = A.second, b = B.first, tb = B.second;
				mn = min(mn, ta + d[a][b] + tb);
			}
		mn += w[u] + w[v];
		cout << mn <<'\n';
	}
	return 0;
}
