#include <bits/stdc++.h>
using namespace std;
int n,k;
struct node{
	int pnt,stp;
};
vector<int> e[2000005];
bool visit[2000005];
bool VIS[2000005];
bool vis[2000005];
int a[2000005];
int ans = 1e9;
bool DFS(int cur){
	for (int nxt : e[cur]){
		if (!vis[nxt])return 0;
		if (VIS[nxt])continue;
		VIS[nxt] = 1;
		DFS(nxt);
	}
}
queue<node> q;
int bfs(int from,int to){
	q.push({from,0});
	visit[from] = 1;
	while (q.size()){
		node head = q.front();
		q.pop();
		if (head.pnt == to){
			return head.stp;
		}
		for (int nxt : e[head.pnt]){
			if (visit[nxt])continue;
			visit[nxt] = 1;
			q.push({nxt,head.stp+1});
		}
	}
}
void dfs(int cnt){
	if (cnt > k){
		int ge= 0;
		for (int i=1;i<=cnt;i++){
			if (!VIS[a[i]]){
				DFS(a[i]);
				ge++;
			}
			if (ge > 2)return;
		}
		int dst = 1e9;
		for (int i=1;i<=n;i++){
			for (int jj=1;jj<=cnt;jj++){
				int j = a[jj];
				memset(visit,0,sizeof(visit));
				dst = min(dst,bfs(i,j));
			}
		}
		ans = min(ans,dst);
		return;
	}
	for (int i = 1;i<=n;i++){
		if (vis[i])continue;
		vis[i] = 1;
		a[cnt] = i;
		dfs(cnt+1);
		vis[i] = 0;
	}
}
void solve(){
	cin >> n >> k;
	for (int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	cout << ans << endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--){
		solve();
	}
	return 0;
}
