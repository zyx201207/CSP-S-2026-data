#include<bits/stdc++.h>
using namespace std;		
struct inforg{
	int v,t,i;
};
struct inforq{
	int l,u,t,i;
};
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],dist[500005],ans;
bool vis[500005];
vector<inforg>g[500005];
queue<inforq>qu;
void bfs(int u,int e){
	for(int i=0;i<g[u].size();i++){
		inforg v=g[u][i];
		qu.push({u,v.v,v.t,v.i});
	}
	while(!qu.empty()){
		inforq x=qu.front();
		qu.pop();
		if(x.t>=dist[x.u]){
			continue;
		}
		if(x.u==e){
			ans=min(ans,x.t);
			continue;
		}
		int z=0;
		for(int i=0;i<g[x.u].size();i++){
			inforg s=g[x.u][i];
			inforq v={x.u,s.v,s.t,s.i};
			if(x.l==v.u){
				continue;
			}
			if(v.i==x.i){
				z=x.t;
				if(dist[v.u]>v.t){
					v.t+=x.t;
					dist[v.u]=v.t;
					qu.push(v);
				}
			}
			else{
				if(dist[v.u]>v.t){
					dist[v.u]=v.t;
					v.t+=x.t+z;
					qu.push(v);
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>c>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i]>>a[i][1]>>t[i][1];
		for(int j=2;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j-1]].push_back({a[i][j],t[i][j],i});
			g[a[i][j]].push_back({a[i][j-1],t[i][j],i});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		memset(dist,0x3f3f3f3f,sizeof(dist));
		bfs(u,v);
		cout<<w[u]+w[v]+dist[v]<<"\n";
	}
	return 0;
}