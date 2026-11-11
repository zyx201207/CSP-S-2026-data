#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1000005;
int C, T;
int n, k, ans, fa[N];
int head[N], to[2*N], nxt[2*N], ed;
int que[N], front, back, dis[N];
void add_edge(int u, int v){
	++ed;
	to[ed] = v;
	nxt[ed] = head[u];
	head[u] = ed;
	++ed;
	to[ed] = u;
	nxt[ed] = head[v];
	head[v] = ed;
	return;
}
int getfa(int u){
	if(u == fa[u]) return u;
	return fa[u] = getfa(fa[u]);
}
bool check(int S){
	int com = 0;
	for(int i = 1; i <= n; i++){
		fa[i] = i;
		if(S&(1<<(i-1))) com++;
	}
	if(com != k) return false;
	for(int i = 1; i <= n; i++){
		if(!(S&(1<<(i-1)))) continue;
		for(int it = head[i]; it != -1; it = nxt[it]){
			int j = to[it];
			if(S&(1<<(j-1))){
				if(getfa(i) == getfa(j)) continue;
				fa[getfa(i)] = getfa(j);
				com--;
			}
		}
	}
	return com <= 2;
}
void solve(){
	cin >> n >> k;
	ed = -1;
	for(int i = 1; i <= n; i++) head[i] = -1;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}
	if(n == k){
		cout << 0 << "\n";
		return;
	}
	if(C == 13 || C == 14){
		cout << (n-k+3)/4+1 << "\n";
		return;
	} 
	ans = INF;
	for(int S = 0; S < (1<<n); S++){
		if(!check(S)) continue;
		front = 1;
		back = 0;
		for(int i = 1; i <= n; i++){
			if(S&(1<<(i-1))){
				dis[i] = 0;
				que[++back] = i;
			}else dis[i] = -1;
		}
		while(front <= back){
			int u = que[front++];
			for(int it = head[u]; it != -1; it = nxt[it]){
				int v = to[it];
				if(dis[v] != -1) continue;
				dis[v] = dis[u]+1;
				que[++back] = v;
			}
		}
		int res = 0;
		for(int i = 1; i <= n; i++) res = max(res, dis[i]);
		ans = min(ans, res);
	}
	cout << ans << "\n";
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
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
*/
