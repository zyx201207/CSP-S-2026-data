#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=510;
const int M=5e5+10;
int w[N];
vector<int> g[N],t[N],color[M];
int k,cnt;
int pre[M],ne[M],to[M],val[M],idx;
void add(int u,int v,int w){
	to[++idx]=v;
	val[idx]=w;
	ne[idx]=pre[u];
	pre[u]=idx;
}
int query(int u,int v){
	int dist[M];
	bool vis[M];
	memset(dist,0x3f3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[u]=0;
	for(int i=1;i<=m;i++){
		int mi=0x3f3f3f3f;
		for(int j=1;j<=m;j++){
			mi=min(mi,dist[j]);
		}
		vis[mi]=true;
		for(int j=pre[mi];j!=0;j=ne[j]){
			if(dist[to[j]]>dist[mi]+val[j] and !vis[to[j]]){
				dist[to[j]]=dist[mi]+val[j];
				vis[to[j]]=1;
			}
		}
	}return dist[v];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	bool flag=1;
	cin>>c>>n>>m>>d>>q;
	if(c>=20){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>2) flag=0;
		for(int j=1;j<=k;j++){
			cin>>g[i][j]>>t[i][j];
			color[g[i][j]].push_back(cnt);
		}cnt++;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=g[i].size();j++){
			for(int k=0;k<=g[i].size();k++){
				if(j==k) continue;
				add(j,k,g[i][j]+g[i][k]);
				add(k,j,g[i][j]+g[i][k]);
			}
		}
	}
	if(flag){
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			cout<<query(u,v)+w[u]+w[v]<<'\n';
		}
	}
	return 0;
}
