#include<bits/stdc++.h>
#define int long long

#define rep(K,F,T) for(int K=F;K<=T;K++)
#define rip(K,F,T) for(int K=F;K>=T;K--)

//#define lson (x<<1)
//#define rson ((x << 1) | 1)
//#define mid ((l + r) >> 1)

using namespace std;

namespace florr{
	int read() {
		int x = 0, f = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9') {
			if(ch == '-') f = -1;
			ch = getchar();
		}
		while(ch >= '0' && ch <= '9') {
			x = x * 10 + (ch - '0');
			ch = getchar();
		}
		return x * f;
	}
	void write(int x) {
		if(x < 0) {
			putchar('-');
			x = -x;
		}
		if(x > 9) write(x / 10);
		putchar(x % 10 + '0');
		return;
	}
}
using namespace florr;
const int MAXN = 5e5 + 10;
int c, n, m, d, q;
int a[MAXN], k[550];
vector<int>sbw[550], sbt[550];
vector<pair<int,int> > G[501], g[MAXN];
int dis[501][501];
int mp[501][501];
void dijkstra(int s) {
	dis[s][s] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > >q;
	q.push({0, s});
	while(!q.empty()) {
		int u = q.top().second, w = q.top().first;
		q.pop();
		if(w > dis[s][u]) continue;
		for(auto v : G[u]) {
			if(dis[s][v.first] > w + v.second) {
				dis[s][v.first] = w + v.second;
				q.push({dis[s][v.first], v.first}); 
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out", "w",stdout);
	c = read(), n = read(), m = read(), d = read(), q= read();
	rep(i,1,m) {
		a[i] = read();
	}
	rep(i,1,n) {
		k[i] = read();
		rep(j,1,k[i]) {
			int x = read(), t = read();
			sbw[i].emplace_back(x);
			sbt[i].emplace_back(t);
			g[x].emplace_back(i, t);
		}
	}
	memset(mp, -1, sizeof mp);
	rep(i,1,n ) {
		rep(j,0,k[i] - 1) {
			for(auto l : g[sbw[i][j]]) {
				if(i == l.first)  {
					continue;
				}
				if(-1 == mp[i][l.first]) {
					mp[i][l.first] = (int)G[i].size();
					int w = l.second + sbt[i][j];
					G[i].emplace_back(l.first, w) ;
					mp[l.first][i] = (int)G[l.first].size();
					G[l.first].emplace_back(i, w);
				}
				else{
					G[l.first][mp[l.first][i]].second = G[i][mp[i][l.first]].second = min(G[i][mp[i][l.first]].second, l.second + sbt[i][j]);
				}
			}
		}
	}
	memset(dis, 0x3f, sizeof dis);
	
	rep(i,1,n) {
		dijkstra(i);
	}
	while(q--){
		int u = read(), v = read();
		int w = LLONG_MAX;
		if(u == v) {
			write(0);
			putchar('\n');
			continue;
		}
		for(auto i : g[u]) {
			for(auto j : g[v]) {
				w = min(w, dis[i.first][j.first] + i.second + j.second);
//				cout << i.first << " " << j.first << " " << dis[i.first][j.first] << " " << i.second << " " << j.second << "\n";
			}
		}
		w += a[u] + a[v];
		write(w);
		putchar('\n');
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

