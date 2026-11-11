#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define req(i, r, l) for(int i = r; i >= l; i--)
#define pb push_back
inline int rd() {
	int res = 0, f = 1; char ch;
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) { res = (res << 3) + (res << 1) + (ch ^ 48); ch = getchar(); }
	return f * res;
}
using namespace std;
const int N = 1e6 + 8;
int n, k;
vector<int> G[N];
int ind[N];
int tot, bel[N], len[N];
// 链的数量，这个点属于哪个链，每个链的长度
multiset<int> S; // 维护每个链
void dfs(int u, int fa) {
	for(auto v: G[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
	if(G[u].size() != 2) return ;
	int v = G[u][0];
	if(!bel[v]) bel[u] = ++tot, len[tot] = 1;
	else bel[u] = bel[v], len[bel[u]]++;
}
queue<int> q[2];
int vis[N];
void init() {
	rep(i, 1, n) G[i].clear(), vis[i] = ind[i] = bel[i] = 0;
	rep(i, 1, tot) len[i] = 0;
	tot = 0;
	S.clear();
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
}
void solve() {
	init();
	n = rd(); k = rd();
	rep(i, 2, n) {
		int u = rd(), v = rd();
		G[u].pb(v);
		G[v].pb(u);
		ind[u]++, ind[v]++;
	}
	if(n == k) {
		puts("0");
		return ;
	}
	int rt = 1;
	rep(i, 1, n) 
		if(G[i].size() == 1) rt = i;
	dfs(rt, 0);
	rep(i, 1, tot) 
		S.insert(len[i]);
	int o = 0;
	rep(i, 1, n) 
		if(ind[i] == 1) q[o].push(i);
	int cnt = n;
	rep(i, 1, n) {
//		cout << i << "\n";
		while(!q[o].empty()) {
			int u = q[o].front();
			q[o].pop();
//			cout << u << " ";
			vis[u] = 1;
			cnt--;
			for(auto v: G[u]) if(!vis[v]) {
				ind[v]--;
				if(ind[v] <= 1) {
					q[o ^ 1].push(v);
					if(G[v].size() == 2) {
						auto nxt = S.lower_bound(len[bel[v]]--);
						S.erase(nxt);
						if(len[bel[v]]) S.insert(len[bel[v]]);
					}
				}
			}
		}
//		cout << cnt << "\n";
//		for(auto i: S) cout << i << " ";
//		cout << "\n\n";
		if(cnt <= k) { 
			cout << i << "\n"; 
			return ;
		}
		if(!S.empty()) {
			auto pos = S.lower_bound(cnt - k); // 剪掉这个链后，剩下的节点
			if(pos != S.end() && cnt - k <= 2 * i - 1) {
				cout << i << "\n"; 
				return ;
			}
		}
		o ^= 1;
	}
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);	
	rd(); int T = rd();
	while(T--) solve();
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

0 1
5 2
1 2
2 3
3 4
4 5

input
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
output
2
*/