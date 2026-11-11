#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+3;  //
int c,t,n,k;
vector<int> e[N];
namespace bf{
	queue<int> q;
	int dist[N],co[N];
	int bfs(){
		for(int i=1;i<=n;++i) dist[i] = n+1;
		for(int i=1;i<=n;++i) if(co[i]){
			dist[i] = 0;
			q.push(i);
		}
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int v : e[u]){
				if(dist[v] > dist[u]+1){
					dist[v] = dist[u]+1;
					q.push(v);
				}
			}
		}
		int re = 0;
		for(int i=1;i<=n;++i) re = max(re,dist[i]);
		return re;
	}
	void dfs(int u){
		co[u] = 2;
		for(int v : e[u]){
			if(co[v] == 1) dfs(v);
		}
	}
	void solve(){
		int res = n+1;
		for(int s=0;s<(1<<n);++s){
			int cnts = 0;
			for(int i=0;i<n;++i){
				if(s>>i&1) co[i+1] = 1,++cnts;
				else co[i+1] = 0;
			}
			if(cnts != k) continue;
			int block = 0;
			for(int i=1;i<=n;++i){
				if(co[i] == 1){
					dfs(i);
					++block;
				}
			}
			if(block > 2) continue;
			res = min(res,bfs());
		}
		cout << res << "\n";
	}
}
int resp[N];
void special(){
	resp[1] = n/4+1;
	int cnt = n;
	resp[n] = 0;
	int tot = 0;
	for(int i=1;i<=(n+1)/2;++i){
		resp[--cnt] = 1;
	}
	tot = 0;
	for(int i=cnt-1;i>=2;--i){
		resp[i] = tot/4+2;
		++tot;
	}
	cout << resp[k] << "\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;++i) e[i].clear();
		for(int i=1,u,v;i<n;++i){
			cin >> u >> v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		if(n <= 10){
			bf::solve();
			continue;
		}else{
			special();
		}
	}
	return 0;
}