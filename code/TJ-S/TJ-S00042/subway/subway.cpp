#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N = 5e5+10, M = 1e5+10;
struct node {
	int v, w;
};
vector <node> e[N+550];
int c, n, m, d, q, k[N], w[N], cnt;
ll dis[N], ans[M];

struct answ {
	int v, id;
};
vector <answ> op[N];
bool flag[N];

struct nodee {
	int v; ll d;
};
bool operator < (const nodee &x, const nodee &y) {
	return y.d < x.d;
}

void solve(int s) {
	for(int i=1; i<=cnt; i++) dis[i] = LLONG_MAX;
	priority_queue <nodee> Q;
	dis[s] = 0; Q.push({s, 0});
	while(!Q.empty()) {
		nodee tmp = Q.top(); Q.pop();
		int u = tmp.v; ll ud = tmp.d;
		//cout << " " << ud << " " << dis[u] << "\n";
		if(ud > dis[u]) continue;
		for(auto v : e[u]) {
			if(dis[v.v] > ud + v.w) {
				dis[v.v] = ud + v.w;
				Q.push({v.v, dis[v.v]});
			}
		}
	}
}

void solve1() {
	cin >> n >> m >> d >> q;
	cnt = n + m;
	for(int i=1; i<=m; i++) {
		cin >> w[i];
		e[n+i].push_back({++cnt, w[i]});
		e[cnt].push_back({n+i, w[i]});
	}
	for(int i=1; i<=n; i++) {
		cin >> k[i];
		for(int j=1; j<=k[i]; j++) {
			int a, t; cin >> a >> t;
			e[i].push_back({n+a, t});
			e[n+a].push_back({i, t});
		}	
	}
		 
	for(int i=1; i<=q; i++) {
		int x, y; cin >> x >> y;
		op[x].push_back({y, i});
		flag[x] = 1;
	}
	
	
	for(int i=1; i<=m; i++) {
		if(flag[i]) solve(n+m+i);
		//cout << n + m + i << "\n";
		//if(flag[i]) for(int i=1; i<=cnt; i++) cout << dis[i] << " ";
		for(auto j : op[i]) {
			ans[j.id] = dis[n+m+j.v];
		}
	}
	for(int i=1; i<=q; i++) cout << ans[i] << "\n";
}

vector <int> tran_line[N];
int t; ll f[502][502]; bool ltl[550][550], vis[550][550];

void solve2() {
	cin >> n >> m >> d >> q;
	cnt = n;
	for(int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> k[i];
		for(int j=1; j<=k[i]; j++) {
			int a; cin >> a >> t;
			tran_line[a].push_back(i);
		}	
	}
	
	for(int i=1; i<=m; i++) {
		for(int j=0; j<tran_line[i].size(); j++) {
			for(int k=0; k<j; k++) {
				ltl[tran_line[i][j]][tran_line[i][k]] = true;
			}
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<i; j++) 
			if(ltl[i][j]) {
				e[i].push_back({j, t*2});
				e[j].push_back({i, t*2});
			}
		 
	for(int i=1; i<=q; i++) {
		int x, y; cin >> x >> y;
		op[x].push_back({y, i});
		flag[x] = 1;
		ans[i] = LLONG_MAX;
	}
	
	for(int i=1; i<=m; i++) {
		if(flag[i]) {
			//cout << i << " ";
			for(int j=0; j<tran_line[i].size(); j++) {
				solve(tran_line[i][j]);
				for(auto k : op[i]) {
					for(int p=0; p<tran_line[k.v].size(); p++) {
						//cout << tran_line[i][j] << " " << tran_line[k.v][p] << "\n";
						ans[k.id] = min(ans[k.id], 2*t+w[i]+w[k.v]+dis[tran_line[k.v][p]]);
					}
				}
			}
		}
	}
	for(int i=1; i<=q; i++) cout << ans[i] << "\n";
}

void solve3() {
	cin >> n >> m >> d >> q;
	cnt = n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) 
			if(j != i) f[i][j] = LLONG_MAX;
		vis[i][i] = 1;
	}
	
	for(int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> k[i];
		for(int j=1; j<=k[i]; j++) {
			int a; cin >> a >> t;
			tran_line[a].push_back(i);
		}	
	}
	
	for(int i=1; i<=m; i++) {
		for(int j=0; j<tran_line[i].size(); j++) {
			for(int k=0; k<j; k++) {
				ltl[tran_line[i][j]][tran_line[i][k]] = true;
			}
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<i; j++) 
			if(ltl[i][j]) {
				e[i].push_back({j, t*2});
				e[j].push_back({i, t*2});
				f[i][j] = f[j][i] = t * 2;
				vis[i][j] = vis[j][i] = 1;
			}
		 
	for(int i=1; i<=q; i++) {
		int x, y; cin >> x >> y;
		op[x].push_back({y, i});
		flag[x] = 1;
		ans[i] = LLONG_MAX;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
					f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
					vis[i][j] = 1;
				
			}
			//cout << f[i][j] << " ";
		}
		//cout << "\n";
	}
	for(int i=1; i<=m; i++) {
		if(flag[i]) {
			//cout << i << " ";
			for(int j=0; j<tran_line[i].size(); j++) {
				for(auto k : op[i]) {
					for(int p=0; p<tran_line[k.v].size(); p++) {
						//cout << tran_line[i][j] << " " << tran_line[k.v][p] << "\n";
						ans[k.id] = min(ans[k.id], 2*t+w[i]+w[k.v]+f[tran_line[i][j]][tran_line[k.v][p]]);
					}
				}
			}
		}
	}
	for(int i=1; i<=q; i++) cout << ans[i] << "\n";
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c;
	if(c >= 12 && c <= 15) solve2();
	else if(c >= 16 && c <= 19) solve3();
	else solve1();
	
	
	return 0;
}
