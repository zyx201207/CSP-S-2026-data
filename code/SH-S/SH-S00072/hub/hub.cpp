#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int c,T;
int n,k;
vector<int> graph[N];
int dist[N],clor[N];
int fdist[N];
set<int> lay[N];
void bfs(int be){
	memset(dist,0x3f,sizeof dist);
	queue<int> q;
	q.push(be);dist[be] = 0;
	while(q.size()){
		int u = q.front();q.pop();
		fdist[u] = max(fdist[u],dist[u]);
		for(int v:graph[u]){
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
void bfs2(int be,int* dist){
	queue<int> q;
	q.push(be);dist[be] = 0;
	while(q.size()){
		int u = q.front();q.pop();
		for(int v:graph[u]){
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
void dfs(int u,int mask,int fa){
	if(mask >> (u - 1) & 1){
		clor[u] = clor[fa];
		for(int v:graph[u]){
			if(v == fa) continue;
			dfs(v,mask,u);
		}
	}
}
int dp[N],dep[N];
	int ceildiv(int x,int y){
		if(x % y == 0) return x / y;
		return x / y + 1;
	}
	void dfs1(int u,int fa){
		dep[u] = dep[fa] + 1;
		for(int v:graph[u]){
			if(v == fa) continue;
			dfs1(v,u);
			dp[u] = max(dp[u],dp[v]);
		}
	}
void trickkis2(){
	int ans = 1e18,res = 1e18;
}
void trickA(){
	int len = k / 2;
	int gap = (n - k) / 4;
	if((n - k) % 4 <= 1) cout << gap + 1 << "\n";
	else cout << gap +2 << "\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--){
		int ans = 1e18;
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			graph[i].clear();
		}
		for(int i = 1;i < n;i++){
			int u,v;cin >> u >>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		if(c == 13 || c == 14){
			trickA();
			continue;
		}
		for(int mask = 1;mask < 1<<n;mask++){
			memset(fdist,0x3f,sizeof(fdist));
			memset(clor,0,sizeof(clor));
			if(__builtin_popcount(mask) > k) continue;
			int idx = 0;
			for(int i = 1;i <= n;i++){
				if(mask>>(i - 1) & 1){
					bfs2(i,fdist);
					if(clor[i]) continue;
					clor[i] = ++idx;
					dfs(i,mask,i);
				}
			}
			if(idx > 2) continue;
			int res = 0;
			for(int i = 1;i <= n;i++){
				res = max(res,fdist[i]);
//				cout << fdist[i] << " ";
			}
			ans = min(ans,res);
		}
		cout << ans << "\n";
	}
	
	return 0;
}

