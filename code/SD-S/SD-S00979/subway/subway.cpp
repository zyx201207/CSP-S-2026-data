#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct edge{
	int n,v,w;
}e[4000001];
int head[2000001],cnt;
void addedge(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].n=head[u];
	head[u]=cnt;
}
int c,n,m,d,q,w[1000001];
int g[501][501],gb[501][501];
struct node{
	int dis,i;
	bool operator < (const node& r)const{
		return 	dis>r.dis;
	}
};
priority_queue<node>p;
void dij(int s){
	for(int j=1;j<=n;j++)	gb[s][j]=0x3f3f3f3f3f3f3f3f;
	gb[s][s]=0;
	p.push({0,s});
	while(!p.empty()){
		node h=p.top();
		p.pop();
		int u=h.i;
		for(int i=1;i<=n;i++){
			int v=i;
			if(u==v)	continue;
			if(g[u][v]<0x3f3f3f3f3f3f3f3f){
				if(gb[s][v]>gb[s][u]+g[u][v]){
					gb[s][v]=gb[s][u]+g[u][v];
					p.push({gb[s][v],v});	
				}
			}	
		}
	}
}
//500000*20*20=
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%lld",&a);
		for(int j=1;j<=a;j++){
			scanf("%lld%lld",&b,&c);
			addedge(b,m+i,c);
		//	addedge(m+i,b,c);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	g[i][j]=0x3f3f3f3f3f3f3f3f;
	}
	for(int i=1;i<=m;i++){
		for(int j=head[i];j!=0;j=e[j].n){
			int u=e[j].v-m;
			for(int k=e[j].n;k!=0;k=e[k].n){
				int v=e[k].v-m;
			//	if(u==v)	continue;
				g[u][v]=min(g[u][v],e[j].w+e[k].w);
				g[v][u]=min(g[v][u],e[j].w+e[k].w);
			}
		}
	}
	for(int i=1;i<=n;i++)	dij(i);
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	cout<<gb[i][j]<<' ';
		cout<<'\n';
	}*/
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%lld%lld",&a,&b);
		int minn=0x3f3f3f3f3f3f3f3f;
		for(int j=head[a];j!=0;j=e[j].n){
			int u=e[j].v-m;
			for(int k=head[b];k!=0;k=e[k].n){
				int v=e[k].v-m;
				minn=min(e[j].w+e[k].w+gb[u][v],minn);
			}
		}
		printf("%lld\n",minn+w[a]+w[b]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

