#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5,INF=1e18;
struct Node{
	int u,v,len;
};
int c,t,n,d,x[N];
vector<int> g[N];
map<pair<int,int>,bool> vis;

int bfs(int st,int ed){
	queue<Node> q;
	q.push({st,0});
	vector<int> vt;
	vis.clear();
	int mn=INF,last=-1;
	while(!q.empty()){
		int u=q.front().u,v=q.front().v,dep=q.front().len;
		q.pop();
		if(u==ed){
			mn=min(mn,dep);
			vt.push_back(dep);
		}
		if(vis.count({u,v})||vis.count({v,u})) continue;
		vis[{u,v}]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			q.push({v,u,dep+1});
		}
	}
	int ret=0;
	for(int i=0;i<vt.size();i++){
		if(vt[i]==mn){
			ret++;
		}
	}
	return ret;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(abs(x[i]-x[j])>d) continue;
				g[j].push_back(i);
				g[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j)==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
