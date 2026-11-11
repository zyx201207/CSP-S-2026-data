#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500505;

struct node{
	int to;
	long long da;
};

bool operator<(node a,node b){
	return a.da>b.da;
}

bool vis[N];
int n,c,m,d,q,k[N],o[N],dis[N],pis[505][505],pol;
vector<pair<int,int> > g[N];
vector<pair<int,int> > a[N];

void dij(int pt){
	for(int i=1;i<=n+m;i++) dis[i]=1e18,vis[i]=0;
	dis[pt+m]=0;
	priority_queue<node> pq;
	pq.push({pt+m,0});
	while(!pq.empty()){
		int u=pq.top().to;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto pp:g[u]){
			int v=pp.first;
			int w=pp.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(v>m) pis[pt][v-m]=dis[v]; 
				pq.push({v,dis[v]});
			}
		}
	}
	return ;
}

void bfs(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pis[i][j]=1e18;
		}
		pis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto pp:a[i]){
			int x=pp.first;
			for(auto qq:a[i]){
				int y=qq.first;
				pis[x][y]=min(pis[x][y],pol*2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				pis[j][k]=min(pis[j][k],pis[j][i]+pis[i][k]);
			}
		}
	}
	return ;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&o[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x;
			int y;
			scanf("%lld%lld",&x,&y);
			pol=y;
			a[x].push_back(make_pair(i,y));
			g[x].push_back(make_pair(m+i,y));
			g[m+i].push_back(make_pair(x,y));
		} 
	}
	if(c>=12 && c<=19){
		bfs();
	}else{
		for(int i=1;i<=n;i++){
			dij(i);
		}
	}
	while(q--){
		int st,ed;
		int mi=1e18;
		scanf("%lld%lld",&st,&ed);
		for(auto pp:a[st]){
			int x=pp.first;
			int y=pp.second;
			for(auto qq:a[ed]){
				int l=qq.first;
				int r=qq.second;
				mi=min(mi,y+r+pis[x][l]);
			}
		}
		printf("%lld\n",mi+o[st]+o[ed]);
	}
	
	return 0;
}

