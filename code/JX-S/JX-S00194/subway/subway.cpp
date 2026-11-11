#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct edge{
	int to,nex,w;
}e[N<<3];
int head[N<<1],cnt;
void addedge(int u,int v,int w){
	e[++cnt].nex=head[v];
	e[cnt].to=v,e[cnt].w=w;
	head[u]=cnt;
}
int dij(int s,int t){
	int dis[N]; bool vis[N];
	queue<pair<int,int> > q;
	memset(dis,0x3f,sizeof(dis));
	q.push({0,s}); dis[s]=0,vis[s]=1;
	while(!q.empty()){
		int u=q.front().second;
		q.pop();
		for(int i=head[u];i;i=e[i].nex){
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w||!vis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
				vis[v]=1;
			}
		}
	}
	return dis[t];
}
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		int w; cin>>w;
		addedge(3*i,3*i+2,w); addedge(3*i+2,3*i,w);
	}
	for(int i=1;i<=n;i++){
		int k,las,a,t; cin>>k>>a>>t;
		las=a;
		for(int j=2;j<=k;j++){
			cin>>a>>t;
			addedge(las,a,0); addedge(a,las,0);
			las=a;
			addedge(3*a+1,3*a,t); addedge(3*a,3*a+1,t);
		}
	}
	while(q--){
		int x,y; cin>>x>>y;
		cout<<dij(3*x+2,3*y+2)<<'\n';
	}
	return 0;
}
