#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define INFint (int)(1e9 + 5)
#define INFll (long long)(1e18 + 5)
#define ull unsigned long long
using namespace std;

int c,t;
int n,k;
vector<int> z[maxn];
void clear() {
	for(int i = 1; i <= n; ++ i) z[i].clear();
}

int dis[15][15];
bool pd[15],vis[15];
void ycl_10pts() {
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			dis[i][j] = INFint;
			if(i == j) dis[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int e : z[i]) {
			dis[i][e] = min(dis[i][e],1);
			dis[e][i] = min(dis[e][i],1);
		}
	}
	for(int k = 1; k <= n; ++ k) {
		for(int i = 1; i <= n; ++ i) {
			if(dis[i][k] == INFint) continue;
			for(int j = 1; j <= n; ++ j) {
				if(dis[k][j] == INFint) continue;
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
}
void find(int now) {
	vis[now] = 1;
	for(int e : z[now]) {
		if(vis[e]) continue;
		if(!pd[e]) continue;
		find(e);
	}
}
int ptans = INFint;
void check() {
	int num_chs = 0;
	for(int i = 1; i <= n; ++ i) {
		if(pd[i]) ++ num_chs;
		vis[i] = 0;
	}
	if(num_chs != k) return ;
	int num_gt = 0;
	for(int i = 1; i <= n; ++ i) {
		if(pd[i] == 1 && vis[i] == 0) {
			find(i);
			++ num_gt;
		}
	}
	if(num_gt > 2) return ;
	int jl = 0;
	for(int i = 1; i <= n; ++ i) {
		int now = INFint;
		for(int j = 1; j <= n; ++ j) {
			if(pd[j] == 1) {
				now = min(now,dis[i][j]);
			}
		}
		jl = max(jl,now);
	}
	ptans = min(ptans,jl);
}
void dfs(int now) {
	if(now == n + 1) {
		check();
	} else {
		dfs(now + 1);
		pd[now] = 1;
		dfs(now + 1);
		pd[now] = 0;
	}
}

void solve() {
	cin >> n >> k;
	clear();
	for(int i = 1; i < n; ++ i) {
		int s,e;
		cin >> s >> e;
		z[s].push_back(e);
		z[e].push_back(s);
	}
	if(n <= 10) {
		ptans = INFint;
		ycl_10pts();
		dfs(1);
		cout << ptans << "\n";
		return ;
	} else if(c >= 13 && c <= 14){
		int Nn = (n - 1) / 2;
		if(k == n){
			cout << 0 << "\n";
			return ;
		}
		if(k >= Nn){
			cout << 1 << "\n";
			return ;
		}
		for(int i = 0;i <= Nn;++ i){
			if(k + 4 * i >= Nn){
				cout << i + 1 << "\n";
				return ;
			}
		}
		return ;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t --) solve();

	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
