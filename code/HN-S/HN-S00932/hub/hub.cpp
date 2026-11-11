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
const int MAXN = 1e6 +10;
int c, t;
int n, k, mid;
vector<int>G[MAXN];
bool vis2[MAXN], vis[MAXN];
void dfs2(int x, int fa) {
//	cout << "-" <<x;
	vis2[x] = 1;
	for(auto v : G[x]) {
		if(v == fa) continue;
		if(!vis[v] or vis2[v]) continue;
//		cout << x <<"$";
		dfs2(v, x);
	}
}
int bfs(int x) {
	rep(i,1,n) vis2[i] = 0;
	queue<pair<int,int> >q;
	q.push({x, 0});
	vis2[x] = 1;
	while(!q.empty()) {
		int u = q.front().first, s= q.front().second;
		q.pop();
		if(vis[u]) return s;
		for(auto v : G[u]) {
			if(!vis2[v]) {
				q.push({v, s+ 1});
				vis2[v] = true;
			}
		}
	}
	return n;
}
int ans = LLONG_MAX;
void check() {
	int s = 0;
	rep(i,1,n) {
		vis2[i] = 0;
	}
	int p = 0;
	rep(i,1,n) {
		if(!vis2[i] and vis[i]) {
			p ++;
//			cout << i;
			dfs2(i, 0);
			if(p > 2) return ;
		}
	}
	rep(i,1,n) {
		if(!vis[i]) {
			s = max(s,bfs(i));
		}
	}
	ans =min(ans, s);
//	rep(i,1,n) cout << vis[i];
//	cout <<p<<s;
//	cout << "\n";
	return;
}
void dfs(int x,int used) {
	if(x > n) 
	{
		check();
		return;
	}
	vis[x] = 0;
	dfs(x + 1, used);
	vis[x] = 1;
	if(used < k)dfs(x + 1, used +1);
}
void solve()
{
	ans = LLONG_MAX;
	n = read(), k = read();
	rep(i,1,n - 1) {
		int u = read(), v = read();
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1, 0);
	rep(i,1,n) G[i].clear();
	write(ans);
	putchar('\n');
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out", "w",stdout);
	c = read();
	t = read();
	while(t --) {
		solve();
	}
	return 0;
}
/*
*/

