#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,q,w[500010],v[500010],vv[500010],mn=1e18,s,v1;
vector<vector<pair<long long,long long> > > a,b;
void dfs(long long x){
	if(x==v1){
		mn=min(mn,s);
		return;	
	}
	if(vv[x]==1){
		return;
	}
	vv[x]=1;
	for(auto i:b[x]){
		s+=i.second;
		for(auto j:a[i.first]){
			if(v[i.first]==1){
				continue;
			}
			v[i.first]=1;
			s+=j.second;
			dfs(j.first);
			s-=j.second;
			v[i.first]=0;
		}
		s-=i.second;
		vv[x]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	a.resize(n+10);
	b.resize(m+10);
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long u,v;
			cin>>u>>v;
			a[i].push_back({u,v});
			b[u].push_back({i,v});
		}
	}
	for(long long i=1;i<=q;i++){
		long long u;
		cin>>u>>v1;
		dfs(u);
		cout<<mn+w[u]+w[v1]<<"\n";
		mn=1e18,s=0;
		memset(v,0,sizeof v);
	}
	return 0;
}
