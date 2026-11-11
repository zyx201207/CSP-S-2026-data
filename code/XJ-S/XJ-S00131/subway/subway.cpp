#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
struct E{
	long long zd,w;
};
vector<E> e[600005];
struct cmp{
	bool operator()(const E &x,const E &y) const{
		return x.w>y.w;
	}
};
long long dij(long long x,long long y){
	vector<long long> d(m+n+5);
	vector<bool> vis(m+n+5);
	priority_queue<E,vector<E>,cmp> pq;
	const long long inf=1e18;
	for(long long i=1;i<=m+n;i++){
		d[i]=inf;
	}
	d[x]=0;
	pq.push({x,0});
	while(!pq.empty()){
		long long zd=pq.top().zd,jl=pq.top().w;
		pq.pop();
		if(zd==y){
			return jl;
		}
		if(vis[zd]){
			continue;
		}
		vis[zd]=1;
		for(auto v:e[zd]){
			if(v.w+jl<d[v.zd]){
				d[v.zd]=v.w+jl;
				pq.push({v.zd,d[v.zd]});
			}
		} 
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	unordered_map<long long,vector<long long> > kd;
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		long long u,v,w;
		cin>>u>>w;
		e[u].push_back({m+i,w});
		e[m+i].push_back({u,w});
		kd[u].push_back(m+i);
		for(long long j=2;j<=k;j++){
			cin>>v>>w;
			kd[v].push_back(m+i);
			e[u].push_back({v,0});
			e[v].push_back({u,0});
			e[m+i].push_back({v,w});
			e[v].push_back({m+i,w});
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		if(x==y){
			cout<<"0\n";
			continue;
		}
		long long ans=INT_MAX;
		vector<long long> zx,zy;
		for(long long va:kd[x]){
			for(long long vb:kd[y]){
				ans=min(dij(va,vb),ans);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

