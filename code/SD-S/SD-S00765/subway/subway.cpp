#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define int long long
using namespace std;
const int N=2e6+10,M=5e6+10,MAXN=0x3f3f3f3f3f3f;
const int B=505;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
struct node{
	int to,nxt,w;
}e[M];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
int t=0,n,m,d,q,cnt=1;
int w[N],k[N];
int num[N];
int head[N],dis[N],s;
bool vis[N];
void add(int u,int v,int w){
	e[++cnt].w=w;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	return ;
}
void dijkstra(){
	for(int i=1;i<=t;i++) dis[i]=MAXN,vis[i]=0;
	dis[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		int now=pq.top().second;
		pq.pop();
		if(vis[now]) continue;
		vis[now]=1;
		for(int i=head[now];i;i=e[i].nxt){
			if(dis[e[i].to]>dis[now]+e[i].w){
				dis[e[i].to]=dis[now]+e[i].w;
				pq.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	return ;
}
int ds[B][B];
vector<int> g[M];
void planB(){
	n=read(),m=read(),d=read(),q=read();
	int T;
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int x=read(),y=read();
			T=y;
			g[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) ds[i][j]=MAXN;
	}
	for(int i=1;i<=n;i++) ds[i][i]=0; 
	for(int i=1;i<=m;i++){
		for(int j=1;j<g[i].size();j++){
			int u=g[i][j-1],v=g[i][j];
			if(ds[u][v]>1) ds[u][v]=1,ds[v][u]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=1;k<=n;k++) ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
		}
	}
	while(q--){
		int x=read(),y=read();
		int res=MAXN;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int u=g[x][i],v=g[y][j];
				res=min(res,ds[u][v]);
			}
		}
		int ans=w[x]+w[y]+2*T*(res+1);
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read();
//	if(){
//		
//	}
	if(c>=12&&c<=19){
		planB();
		return 0;
	}
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
		add(t+1,t+2,w[i]);
		add(t+2,t+1,w[i]);
		t+=2;
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		int x1;
		for(int j=1;j<=k[i];j++){
			int x=read(),y=read();
			int ai=2*x;
			num[x]=++t;
			add(num[x],ai,y);
			add(ai,num[x],y);
			if(j>1) add(num[x1],num[x],0),add(num[x],num[x1],0);
			x1=x;
		}
	}
	while(q--){
		int x=read(),y=read();
		s=2*x-1;
		dijkstra();
		cout<<dis[2*y-1]<<'\n'; 
	}
	return 0;
}
