#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=505;
const int M=1222+7;
int w[M];
int head[M+N],cnt=0;
struct edge{
	int to;
	int next;
	int w;
}edge[(M+N)<<1];
long long ans=0;
struct node{
	int pos;
	int dis;
	bool friend operator <(const node & A,const node & B){
		return A.dis>B.dis;
	}
};
void add_edge(int u,int v,int w){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].w=w;
	head[u]=cnt;
}
priority_queue<node>Q;
int vis[N+M],dis[N+M];
void dij(int s){
	Q.push({s,0});
	dis[s]=0;
	while(!Q.empty()){
		node x=Q.top();
		Q.pop();
		int u=x.pos;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w;
				if(!vis[v]){
					Q.push({v,dis[v]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	if(c<=8){
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int lst=0;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			add_edge(m+i,v,t);
			add_edge(v,m+i,t);
			
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		int u,v;
		cin>>u>>v;
		ans=0;
		ans+=w[u]+w[v];
		dij(u);
		ans+=dis[v];
		cout<<ans<<'\n';
	}
//}
	
	return 0;
}
