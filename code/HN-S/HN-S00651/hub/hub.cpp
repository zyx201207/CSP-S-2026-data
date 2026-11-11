#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c, t, n, k, ans, p[35], d[35], F[35];
bool f[35], fl[35];
vector<int> vc[1000005];
int findf(int x){
	if(F[x] == x) return x;
	return F[x] = findf(F[x]);
}
void bfs(){
	memset(d, 0x3f, sizeof d);
	memset(fl, 0, sizeof fl);
	queue<int> q;
	for(int i = 1; i <= k; i++){
		q.push(p[i]);
		fl[p[i]] = 1;
		d[p[i]] = 0;
	}
	while(!q.empty()){
		int fr = q.front(); q.pop();
		for(auto i : vc[fr]){
			if(d[i] <= d[fr] + 1) continue;
			d[i] = d[fr] + 1;
			if(fl[i]) continue;
			fl[i] = 1;
			q.push(i);
		}
	}
}
void dfs(int x, int c){
	if(c > k){
		for(int i = 1; i <= n; i++) F[i] = i;
		for(int i = 1; i <= k; i++)
			for(auto j : vc[i])
				if(f[j] && findf(i) != findf(j)) F[i] = F[findf(j)];
		map<int, bool> mp;
		for(int i = 1; i <= k; i++) mp[F[p[i]]] = 1;
		if(mp.size() > 2) return;
		bfs();
		int mx = 0;
		for(int i = 1; i <= n; i++)
			mx = max(mx, d[i]);
		ans = min(ans, mx);
		return;
	}
	if(x > n) return;
	f[x] = 1;
	p[c] = x;
	dfs(x + 1, c + 1);
	f[x] = 0;
	dfs(x + 1, c);
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		ans = 1e9;
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i++){
			int u, v;
			cin >> u >> v;
			vc[u].push_back(v);
			vc[v].push_back(u);
		}
		dfs(1, 1);
		cout << ans << '\n';
		for(int i = 1; i <= n; i++) vc[i].clear();
	}
	return 0;
}
/*

再见小学 再见小学生
试了一万遍也考不了满分
——久眯 & 鳗 《再见了小学生》 

*一种诗人般的离开 

*/
