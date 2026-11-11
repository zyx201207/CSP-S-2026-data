#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a,t,u,v,dis[500505],sum[500505];
bool vis[500505];
vector<pair<int,int> > adj[500505];
priority_queue<pair<int,int > > pq;
int dj(int u,int v){
	for(int i=1;i<=n+m;i++){
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	dis[u]=0;
	while(!pq.empty()){
		pq.pop();
	}
	pq.push(make_pair(0,u));
	while(!pq.empty()){
		int p=pq.top().second;
		pq.pop();
		for(int i=0;i<sum[p];i++){
			if(dis[adj[p][i].second]>dis[p]+adj[p][i].first&&!vis[adj[p][i].second]){
				dis[adj[p][i].second]=dis[p]+adj[p][i].first;
				vis[adj[p][i].second]=1;
				pq.push(make_pair(-dis[adj[p][i].second],adj[p][i].second));
			}
		}
	}
	return dis[v];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			adj[a].push_back(make_pair(t,i+m));
			adj[i+m].push_back(make_pair(t,a));
			sum[a]++;
			sum[i+m]++;
		}
	}
	while(q--){
		scanf("%d%d",&u,&v);
		printf("%d\n",dj(u,v)+w[u]+w[v]);
	}
}
