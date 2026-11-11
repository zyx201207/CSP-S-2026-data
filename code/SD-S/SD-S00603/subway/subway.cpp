#include <bits/stdc++.h>
using namespace std;
#define M 500000
#define N 500
vector<int>g[N+5];
int c,n,m,d,q;
int k[N+5],w[N+10],p[M+5],t[N+5][M+5];
bool vis[M+5];
void bfs(int u,int v){
	memset(vis,0,sizeof vis);
	using pii=pair<int,int>;
	queue<pii>qu;
	qu.push({u,0});
	vis[u]=1;
	while(!qu.empty()){
		pii point=qu.front();
		qu.pop();
		for(int to:g[point.first]){
			if(!vis[to]){
				vis[to]=1;
				qu.push({to,point.second+1});
			}
			if(to==v){
				long long tme=(point.second+1)*2+w[u]+w[v];
				cout<<tme<<'\n';
			}
		}
	}
}
void cheat(){
	int t;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>p[i]>>t;
			if(j>1)g[p[i-1]].push_back(p[i]),g[p[i]].push_back(p[i-1]);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		bfs(u,v);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(12<=c&&c<=19){
		cheat(); 
	}
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>p[i]>>t[i][j];
			if(j>1)g[p[i-1]].push_back(p[i]);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		;
	}
	return 0;
}

