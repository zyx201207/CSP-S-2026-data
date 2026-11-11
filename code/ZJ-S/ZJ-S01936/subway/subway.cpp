#include<bits/stdc++.h>
using namespace std;
long long w[500005];
struct node{
	long long v;
	long long w;
};
vector<node>kk[1005];
long long dis[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		if(k==1){
			long long _,__;
			cin>>_>>__;
		}
		if(k==2){
			long long u,t1,v,t2;
			cin>>u>>t1>>v>>t2;
			kk[u].push_back({v,t1+t2});
			kk[v].push_back({u,t1+t2});
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			dis[i][j]=1e12;
		}
	}
	for(long long i=1;i<=m;i++){
		dis[i][i]=0;
		priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >pq;
		pq.push({0,i});
		while(!pq.empty()){
			long long ds=pq.top().first;
			long long u=pq.top().second;
			pq.pop();
			if(ds>dis[i][u])continue;
			for(long long j=0;j<kk[u].size();j++){
				long long w=kk[u][j].w;
				long long v=kk[u][j].v;
				if(w+dis[i][u]<dis[i][v]){
					dis[i][v]=w+dis[i][u];
					pq.push({dis[i][v],v});
				}
			}
		}
	}
	while(q--){
		long long u,v;
		cin>>u>>v;
		long long ans=dis[u][v]+w[u]+w[v];
		cout<<ans<<'\n';
	}
	
	return 0;
}
