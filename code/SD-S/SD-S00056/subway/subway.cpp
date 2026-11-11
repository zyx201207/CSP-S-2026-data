#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10,INF=1e9;
int c,n,m,q,d;
int w[M];
int head[N+M],cnt;
struct edge{
	int v,w,nxt;
}e[N+M];
void add(int u,int v,int w){
	e[++cnt]={v,w,head[u]};
	head[u]=cnt;
}
int dis[N+M];
struct node{
	int pos,val; 
	bool operator <(node a)const{
		return a.val<val;
	}
};
priority_queue<node> qe;
bool vis[M+N];
//¼ÇµÃÇå¿Õ£¡£¡£¡£¡£¡ 
void dij(int x){
	for(int i=1;i<=n+m;i++){dis[i]=INF;}
	for(int i=1;i<=n+m;i++){vis[i]=false;}
	dis[x]=0;
	qe.push((node){x,0});
	while(!qe.empty()){
		node tmp=qe.top();
		qe.pop();
		if(vis[tmp.pos]){
			continue;
		}
		vis[tmp.pos]=true;
		for(int i=head[tmp.pos];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>tmp.val+w){
				dis[v]=tmp.val+w;
				qe.push((node){v,dis[v]});
				//cout<<v<<" "<<dis[v]<<'\n';
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			add(m+i,v,w);
			add(v,m+i,w);
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		dij(u);
		cout<<(dis[v]+w[u]+w[v])<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
