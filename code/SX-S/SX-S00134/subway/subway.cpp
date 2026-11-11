#include <bits/stdc++.h>
using namespace std;
int w[500005];
int cnt=1,head[500005];
queue<int> q;
bool vis[500005];
int dist[500005];
struct Node{
	int to,nxt,wei;
}edge[2000005];
void add(int u,int v,int w){
	edge[cnt].nxt=head[u];
	edge[cnt].to=v;
	edge[cnt].wei =w;
	head[u]=cnt;
	cnt++;
}
int SPFA(int s,int e){
	memset(dist,63,sizeof dist);
	memset(vis,0,sizeof vis);
	vis[s]=1;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to,w=edge[i].wei;
			if(dist[u]+w<dist[v]){
				q.push(v);
				dist[v]=dist[u]+w;
				vis[v]=1;
			}
		}
	}
	return dist[e];
}
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int nowa,nowt,lasta,lastt;
		cin>>nowa>>nowt;
		for(int j=2;j<=k;j++){
			lasta=nowa,lastt=nowt;
			cin>>nowa>>nowt;
			add(lasta,nowa,lastt+nowt);
			add(nowa,lasta,lastt+nowt);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=SPFA(x,y)+w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}