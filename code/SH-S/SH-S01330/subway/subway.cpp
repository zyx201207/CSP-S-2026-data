#include <bits/stdc++.h>
using namespace std;
const int N=509,M=5e5+9;
int c,n,m,f,q,d[N][N],w[M],a[M],t[M],dis[N],vis[N];
vector <int> g[N];
queue <int> qu;
void check(int x){
	while(!qu.empty()) qu.pop();
	qu.push(x);
	dis[x]=0;
	vis[x]=1;
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(vis[v]==0){
				qu.push(v);
				vis[v]=1;
				dis[v]=dis[u]+d[u][v];
			} 
			if(dis[v]>dis[u]+d[u][v]) dis[v]=dis[u]+d[u][v];
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>f>>q;
	memset(d,0x7f,sizeof(d));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int h=1;h<j;h++){
				g[a[j]].push_back(a[h]);
				g[a[h]].push_back(a[j]);
				d[a[j]][a[h]]=min(t[j]+t[h],d[a[j]][a[h]]);
				d[a[h]][a[j]]=d[a[j]][a[h]];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		check(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
		memset(dis,0x7f,sizeof(dis));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
