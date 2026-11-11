#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9+5;
vector<vector<int> > graph; 
vector<vector<int> >ans;
vector<int> vis;
void bfs(int start, int u, int depth){
	for(int i = 0; i<graph[u].size(); i++){
		if(vis[graph[u][i]]) continue;
		vis[graph[u][i]] = 1;
		if(depth<ans[start][graph[u][i]]){
			ans[start][graph[u][i]] = depth;
		}
		bfs(start,graph[u][i], depth+1);
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	int a[m];
	for(int i = 0; i<m; i++){
		cin>>a[i];
	}
	int val = 0;
	
	 
	graph.assign(m,vector<int>());
	for(int i = 0; i<n; i++){
		int k;
		cin>>k;
		vector<int> g;
		for(int j = 0; j<k; j++){
			int x;
			cin>>x>>val;
			g.push_back(x);
		}
		for(int j = 0; j<k; j++){
			for(int e = 0; e<k; e++){
				if(g[e]!=g[j]) graph[g[e]].push_back(g[j]);
			}
		}
	}
	ans.assign(m,vector<int>(m,INF));
	for(int i = 0; i<m; i++){
		vis.assign(m,0);
		bfs(i, i, 0);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<a[x]+a[y] + 2*val*ans[x][y]<<"\n";
	}
	return 0;
} 
