#include<bits/stdc++.h>
using namespace std;
const int N=502;
const int M=5e5+2;
typedef pair<int,int> PII;
int station[M];
int c,n,m,d,q;
struct Node{
	int next,to;
	int w;
};
Node edge[M*2];
int tot=0;
int head[M];
void add_edge(int u,int v,int w){
	edge[++tot].to=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot;
}
int min_dis[N][N];
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			min_dis[i][j]=0x3f3f3f;
		}
		min_dis[i][i]=0;
	}
	PII dui[N]={{0,0}};
	int headd=0,tail=1;
	dui[headd]={s,0};
	while(headd<tail){
		int u=dui[headd].first;
		int fromm=dui[headd].second;
		headd++;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			int w=edge[i].w;
			if(v==fromm)continue;
			if(min_dis[s][u]+w<min_dis[s][v]){
				min_dis[s][v]=min_dis[s][u]+w;
				dui[++tail]={v,u};
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;// id lines stations max_line_num queries
	//see platforms as nodes;
	for(int i=1;i<=m;i++)cin>>station[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;//stations 
		int temp,x;cin>>temp>>x;//temp: station x: line_station time
		add_edge(temp,k*500+temp,x);
		add_edge(k*500+temp,temp,x);
		int rem=temp;
		for(int j=2;j<=k;j++){
			cin>>temp>>x;
			add_edge(temp,k*500+temp,x);
			add_edge(k*500+temp,temp,x);
			add_edge(k*500+temp,k*500+rem,0);
			add_edge(k*500+rem,k*500+temp,0);
			rem=temp;
		}
	}
	//use o(n*n*logn) to check every nodes' dijkstra;
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	while(q--){
		int u,v;cin>>u>>v;
		if(u==v)cout<<0<<'\n';
		else cout<<(min_dis[u][v]+station[u]+station[v])<<'\n';
	}
	return 0;
} 