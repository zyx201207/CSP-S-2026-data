#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010];
vector<pair<int,long long>> edges[500010];
long long dist[500010];

long long dijkstra(int s,int e){
	memset(dist,127,sizeof(dist));
	dist[s]=0;
	set<pair<long long,int>> q;
	q.insert({0,s});
	while(!q.empty()){
		int x=q.begin()->second;
		q.erase(q.begin());
		for(auto y:edges[x]){
			if(dist[x]+y.second<dist[y.first]){
				q.erase({dist[y.first],y.first});
				dist[y.first]=dist[x]+y.second;
				q.insert({dist[y.first],y.first});
			}
		}
	}
	return dist[e];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(j!=l){
                    edges[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
				}
			}
		}
	}
	for(;q--;){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",w[x]+w[y]+dijkstra(x,y));
	}
}
