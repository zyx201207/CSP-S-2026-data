#include<bits/stdc++.h>
typedef long long ll;
const int N = 1e6 + 5;
bool vis[N];
int n,k,u[N],v[N],fa[N],dis[N];
int ans;
std::vector<int> g[N];
struct DIS{int id,dis;};
std::vector<int> S;
int getroot(int x){return fa[x] == x ? x : fa[x] = getroot(fa[x]);}
void dfs(int i){
	if (S.size() == k){
		for (int i : S) vis[i] = 1;
		for (int i = 1;i <= n;i++) fa[i] = i;
		for (int i = 1;i < n;i++) 
			if (vis[u[i]] && vis[v[i]]) fa[getroot(u[i])] = getroot(v[i]);
		for (int i : S) vis[i] = 0;
		std::set<int> se;
		for (int i : S) se.insert(getroot(i));
		if (se.size() > 2) return;
		memset(dis,0x3f,sizeof(dis));
		std::queue<DIS> q; 
		for (int i : S) dis[i] = 0,q.push({i,0});
		while (!q.empty()){
			DIS h = q.front();q.pop();
			int u = h.id;
			if (h.dis != dis[u]) continue;
			for (int v : g[u])
				if (dis[u] + 1 < dis[v]){
					dis[v] = dis[u] + 1;
					q.push({v,dis[v]});
				}
		}
		int res = 0;
		for (int i = 1;i <= n;i++) res = std::max(res,dis[i]);
		ans = std::min(ans,res);
		return;
	}
	if (i > n) return;
	dfs(i + 1);
	S.push_back(i);
	dfs(i + 1);
	S.pop_back();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	int c,t;
	for (std::cin >> c >> t;t--;){
		std::cin >> n >> k;
		for (int i = 1;i < n;i++) std::cin >> u[i] >> v[i];
		for (int i = 1;i <= n;i++) g[i].clear();
		for (int i = 1;i < n;i++){
			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
		ans = 1e9;
		dfs(1);
		S.clear();
		std::cout << ans << '\n';
	}
	return 0;
}
