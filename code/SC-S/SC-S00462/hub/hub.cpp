#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int INF = 1e18;
int n, k, ans = INF;
vector<int> G[1000010];
vector<int> s;
bool vis[1000010];
bool is_in_s[1000010];
void bfsltk(int u0){
	queue<int> q;
	q.push(u0);
	while(!q.empty()){
		int u = q.front();q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int v : G[u]) q.push(v);
	}
	return;
}
int bfs(int u0){
	queue<pii > q;
	vector<bool> vis(n + 5, false);
	q.push(make_pair(u0, 0));
	while(!q.empty()){
		int u = q.front().first, step = q.front().second;q.pop();
		if(vis[u]) continue;
		if(is_in_s[u]){
			return step;
		} 
		vis[u] = true;
		for(int v : G[u]) q.push(make_pair(v, step + 1));
	}
	return INF;
}
void cheek(){
	for(int i = 1;i <= n;i ++) vis[i] = true;
	for(int i : s) vis[i] = false;
	int cnt = 0;
	for(int i : s){
		if(!vis[i]){
			bfsltk(i); 
			cnt ++;
		} if(cnt > 2) return;
	}
	
	//cout << "合理！\n";
//	for(int i : s) cout << i << ' ';
//	cout << '\n';
	int anst = -1;
	for(int i = 1;i <= n;i ++){
		anst = max(anst, bfs(i)); 
	}
//	cout << anst << '\n';
	ans = min(ans, anst);
}
void dfsxs(int id, int cnt){
	if(cnt == k) {
		cheek();
		return;
	}
	if(id > n) return;
	s.push_back(id);
	is_in_s[id] = true;
	dfsxs(id + 1, cnt + 1);
	s.pop_back();
	is_in_s[id] = false;
	dfsxs(id + 1, cnt);
	return;
}

void slove(){
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) G[i].clear();
	for(int i = 1;i < n;i ++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	ans = INF;
	dfsxs(1, 0);
	cout << ans << '\n';
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0), cout.tie(0);
	
	int c, T;
	cin >> c >> T;
	while(T --){
		slove();
	}
	
	return 0;
}