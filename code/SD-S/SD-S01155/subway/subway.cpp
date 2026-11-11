// chennie bless me 
#include<bits/stdc++.h>
#define int long long
#define __FILE_IO__(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define all(x) x.begin(), x.end()
#define All(x) x.begin() + 1, x.end()
#define rep(i,l,r) for(int i = (l);i <= (r); ++i)
#define per(i,l,r) for(int i = (l);i >= (r); --i)
using vi = std::vector<int>;
using pii = std::pair<int,int>;
#define in std::cin
#define out std::cout
void ckmax(int &a,int b) { a = std::max(a,b); }
void ckmin(int &a,int b) { a = std::min(a,b); }
#define fi first
#define se second
#define pii std::pair<int,int>

const int N = 5e5+10, M = 1010;

int abs(int x) {
	if(x < 0) return -x;
	return x;
}

std::vector<pii> g[N], e[N];
int dis[M][M];

void solve(){
	int n, m, d, q; in >> n >> m >> d >> q;
	vi w(m+1);
	rep(i,1,m) in >> w[i];
	rep(i,1,n) {
		int k; in >> k;
		rep(j,1,k) {
			int a, t; in >> a >> t;
			g[a].emplace_back(i,t);
		}
	}
	rep(i,1,n) rep(j,1,n) dis[i][j] = 1e18;
	rep(i,1,m) {
		for(const pii &x : g[i])
			for(const pii &y : g[i]) {
				ckmin(dis[x.fi][y.fi], x.se + y.se);
			}
	}
	rep(i,1,n) dis[i][i] = 0;
	rep(k,1,n) rep(i,1,n) rep(j,1,n) ckmin(dis[i][j],dis[i][k] + dis[k][j]);	
	rep(_,1,q) {
		int u, v; in >> u >> v;
		int ans = 1e18;
		for(const pii &x : g[u])
			for(const pii &y : g[v]) {
				ckmin(ans, dis[x.fi][y.fi] + x.se + y.se + w[u] + w[v]);
			}
		out << ans << '\n';
	}
}

signed main() {
	__FILE_IO__("subway");
	std::ios::sync_with_stdio(0), in.tie(0);  
	int T = 1;
	int c; in >> c;
//	in >> T;
	while(T--) {
		solve();
	}
	return 0;
}
