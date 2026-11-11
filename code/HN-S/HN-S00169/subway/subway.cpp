#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int N=505,M=5e+5+5;
const long long INF=1e+17;
int n,m,d,q,c,head1[N+M],id1,id,head[N];
long long tsp[M],dis[N][N],Map[N][N];
struct Edge{
	int v,nx;
	long long w;
}e1[M<<1],e[N*N<<1];
struct Rough{
	int l,r;
}rou[N];
struct Stop{
	int a;
	long long t;
}sp[M];

void add1(int u,int v,long long w){
	id1++; e1[id1].v=v; e1[id1].w=w;
	e1[id1].nx=head1[u]; head1[u]=id1;
}
void add(int u,int v,long long w){
	id++; e[id].v=v; e[id].w=w;
	e[id].nx=head[u]; head[u]=id;
}

void init(){
	int k;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&tsp[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{dis[i][j]=INF;Map[i][j]=INF;}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		rou[i].l=rou[i-1].r+1; rou[i].r=rou[i-1].r+k;
		for(int j=rou[i].l;j<=rou[i].r;j++){
			scanf("%d%lld",&sp[j].a,&sp[j].t);
			add1(i,sp[j].a+n,sp[j].t); add1(sp[j].a+n,i,sp[j].t);
		}
	}
}

void spfa(int st){
	int u,v;
	bool vs[N];
	queue<int> q;
	memset(vs,false,sizeof(vs));
	vs[st]=true; q.push(st);
	while (q.size()){
		u=q.front(); q.pop(); vs[u]=false;
		for(int i=head[u];i!=0;i=e[i].nx){
			v=e[i].v;
			if(dis[st][v]>dis[st][u]+e[i].w){
				dis[st][v]=dis[st][u]+e[i].w;
				if(!vs[v]){q.push(v);vs[v]=true;}
			}
		}
	}
}

void make_map(){
	int u,v;
	for(int st=1;st<=n;st++){
		for(int i=head1[st];i!=0;i=e1[i].nx){
			u=e1[i].v;
			for(int j=head1[u];j!=0;j=e1[j].nx){
				v=e1[j].v;
				Map[st][v]=min(Map[st][v],e1[i].w+e1[j].w);
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(Map[i][j]!=INF) add(i,j,Map[i][j]);
	for(int i=1;i<=n;i++) spfa(i);
}

inline long long calc(int st,int ed){
	int u,v;
	long long ans=INF;
	for(int i=head1[st+n];i!=0;i=e1[i].nx){
		u=e1[i].v;
		for(int j=head1[ed+n];j!=0;j=e1[j].nx){
			v=e1[j].v;
			ans=min(ans,e1[i].w+e1[j].w+dis[u][v]);
		}
	}
	return ans;
}

void query(){
	int st,ed;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&st,&ed);
		printf("%lld\n",calc(st,ed)+tsp[st]+tsp[ed]);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	make_map();
	query();
	return 0;
}
