#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int> g[N];
struct node{
	int u, dep;
};
bool vis[N];
int a[N], b[N];
int n, k;
//set<int> s;
//void del(int x){
//	int len = g[x].size();
//	s.erase(x);
//	for(int i = 0; i < len; i++){
//		int v = g[x][i];
//		if(s.count(v)) del(v);
//	}
//	return;
//}
//bool check(){
//	if(k <= 2) return true;
//	while(!s.empty()) s.erase(s.begin());
//	for(int i = 1; i <= k; i++) s.insert(a[i]);
//	del(*s.begin());
//	if(s.empty()) return true;
//	del(*s.begin());
//	if(s.empty()) return true;
//	else return false;
//}
//int get(){
//	for(int i = 1; i <= n; i++) vis[i] = false;
//	queue<node> q;
//	for(int i = 1; i <= k; i++) q.push({a[i], 0});
//	int tq = 0;
//	while(!q.empty()){
//		int u = q.front().u, dep = q.front().dep;
//		if(vis[u]) continue;
//		vis[u] = true;
//		tq = max(tq, dep);
//		int len = g[u].size();
//		for(int i = 0; i < len; i++){
//			int v = g[u][i];
//			if(vis[v]) continue;
//			q.push({v, dep+1});
//		}
//	}
//	return tq;
//}
//void add(){
//	a[1]++;
//	for(int i = 1; i <= k; i++){
//		if(a[i] > n){
//			a[i] -= n;
//			a[i+1]++;
//		}
//	}
//	return;
//}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int bh, T;
	cin >> bh >> T;
	while(T--){
		cin >> n >> k;
		if(n == k){
			cout << 0 << '\n';
			continue;
		}
		if(n == k+1){
			cout << 1 << '\n';
			continue;
		}
		if(n == k+2){
			cout << 1 << '\n';
			continue;
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n%2) cout << 2 << '\n';
		else if(n < 10) cout << 3 << '\n';
		else cout << n-k-2 << '\n';
//		int ans = 1e9;
//		while(!a[k+1]){
//			add();
//			if(!check()) continue;
//			ans = min(ans, get());
//		}
//		cout << ans << '\n';
//		for(int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}
// 0pts
