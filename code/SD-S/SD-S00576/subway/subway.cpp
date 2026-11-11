#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long c,n,m,d,q,w[500005];
long long dis[505][505];
vector<pair<long long,long long> >pp[500005];
vector<pair<long long,long long> >tu[505];
void dij(long long x){
	for(long long i=1;i<=n;i++)
		dis[x][i]=inf;
	dis[x][x]=0;
	priority_queue<pair<long long,long long> >q;
	q.push({0,x});
	while(q.size()){
		long long u=q.top().second;
		q.pop(); 
		for(long long i=0;i<tu[u].size();i++){
			long long v=tu[u][i].first,w=tu[u][i].second;
			if(dis[x][v]>dis[x][u]+w){
				dis[x][v]=dis[x][u]+w;
				q.push({-dis[x][v],v});
			}
		} 
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long t1,t2;
			scanf("%lld%lld",&t1,&t2);
			pp[t1].push_back({i,t2});
		}
	}
	for(long long i=1;i<=m;i++)
		for(long long j=0;j<pp[i].size()-1;j++)
			for(long long k=j+1;k<pp[i].size();k++){
				long long u=pp[i][j].first,v=pp[i][k].first;
				long long w=pp[i][j].second+pp[i][k].second;
				tu[u].push_back({v,w});
				tu[v].push_back({u,w}); 
			}
	for(long long i=1;i<=n;i++){
		dij(i); 
	}
	while(q--){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long minn=inf;
		for(long long i=0;i<pp[x].size();i++)
			for(long long j=0;j<pp[y].size();j++){
				long long u=pp[x][i].first,v=pp[y][j].first;
				long long w=dis[u][v]+pp[x][i].second+pp[y][j].second;
				minn=min(minn,w);
			} 
		printf("%lld\n",w[x]+w[y]+minn);
//		cout<<f[1][2]; 
	}
	return 0;
} 
