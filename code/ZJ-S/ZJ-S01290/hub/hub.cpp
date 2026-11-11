#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)

typedef long long ll;
const int N = 2e6 + 5;

int c, T;
int n, k;

struct Edge{
	int u, v, nxt;
}e[N];
int h[N], idx;
void add_edge(int u, int v){
	e[++idx] = {u, v, h[u]}, h[u] = idx;
}

int ch[N];
int ans = N + N + N;
int vis[N];
void dfss(int u){
	if(!ch[u] || vis[u]) return;
	vis[u] = 1;
	for(int id = h[u]; id; id = e[id].nxt){
		int v = e[id].v;
		dfss(v);
	}
}
bool check(){
	rep(i, 1, n) vis[i] = 0;
	int cnt = 0;
	rep(i, 1, n){
		if(vis[i] || !ch[i]) continue;
		cnt++;
		if(cnt > 2) return false;
		dfss(i);
	}
	return true;
}

int dis[N];
int calc(){
	queue<int>q;
	rep(i, 1, n){
		dis[i] = -1;
		if(ch[i]){
			q.push(i);
			dis[i] = 0;
		}
	}
	int res = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		res = max(res, dis[u]);
		for(int id = h[u]; id; id = e[id].nxt){
			int v = e[id].v;
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
//	rep(i, 1, n) cout << ch[i];
//	cout << '\n' << res << '\n';
	return res;
}

void dfs(int l, int cnt){
	if(cnt == k){
		if(!check()) return;
		ans = min(ans, calc());
		return;
	}
	if(l > n) return;
	dfs(l + 1, cnt);
	ch[l] = 1;
	dfs(l + 1, cnt + 1);
	ch[l] = 0;
}

void solve(){
	ans = N + N + N;
	cin >> n >> k;
	rep(i, 1, n - 1){
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
		add_edge(v, u);
	}
//	cout << '*';
	dfs(1, 0);
	cout << ans << '\n';
	
	do{
		e[idx] = {0, 0, 0};
	}while(--idx);
	rep(i, 1, n) h[i] = 0;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> c >> T;
	while(T--) solve();
	
	return 0;
}