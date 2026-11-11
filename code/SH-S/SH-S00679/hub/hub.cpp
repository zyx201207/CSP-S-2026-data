#include<bits/stdc++.h>
using namespace std;
const int maxn = 40;
int _case, T, n, k, ans;
vector<int> tree[maxn];
bool vis[maxn], ds[maxn];
int dis[maxn];

void bfs(int s){
	queue<int> q;
	q.push(s);
	ds[s] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int j = 0; j < tree[u].size(); j ++){
			if(!vis[tree[u][j]] || ds[tree[u][j]])	continue;
			ds[tree[u][j]] = true;
			q.push(tree[u][j]);
		}
	}
}

int commute(){
	queue<int> q;
	memset(dis, 0, sizeof(dis));
	for(int i = 1; i <= n;i ++){
		if(vis[i])	q.push(i);
	}
	int res = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		res = max(res, dis[u]);
		for(int j = 0; j < tree[u].size(); j ++){
			if(vis[tree[u][j]] || dis[tree[u][j]] > 0)	continue;
			dis[tree[u][j]] = dis[u] + 1;
			q.push(tree[u][j]);
		}
	}
	return res;
}

void dfs(int i, int j){
	if(i + (k - j - 1) > n)	return;
	if(i == n + 1 || j == k){
		memset(ds, false, sizeof(ds));
		int cnt = 0;
		for(int p = 1; p <= n; p ++){
			if(!vis[p])	continue;
			if(!ds[p])	bfs(p),	cnt ++;
		}
		if(cnt != 2)	return;
//		for(int p = 1;p <= n; p++){
//			cout << vis[p] << " ";
//		}
//		cout << endl;
		ans = min(ans, commute());
//		printf("%d %d\n",cnt,commute());
		return; 
	}
	dfs(i + 1, j);
	vis[i] = true;
	dfs(i + 1, j + 1);
	vis[i] = false;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> _case >> T;
	while(T --){
		cin >> n >> k;
		for(int i = 1; i < n; i ++){
			int u, v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		ans = INT_MAX;
		dfs(1, 0);
		cout << ans << "\n";
		
		memset(vis,false,sizeof(vis));
		for(int i = 1; i <= n; i ++){
			tree[i].clear();
		}
	}
	return 0;
}
