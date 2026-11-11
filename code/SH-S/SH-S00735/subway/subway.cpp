#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],anss=1e18;
vector<pair<long long,long long> > r[505],p[500005];
bool visp[500005]={},visr[505]={};
void dfs(long long now,long long dd,long long cnt){
	if(now==dd){
		anss=min(anss,cnt);
		return;
	}
	for(long long i=0;i<p[now].size();i++){
		long long l=p[now][i].first;
		if(visr[l]==1) continue;
		for(long long j=0;j<r[l].size();j++){
			long long to=r[l][j].first;
			if(visp[to]==1) continue;
			if(p[to].size()==1&&to!=dd){
				continue;
			}
			visr[l]=1;
			visp[to]=1;
			dfs(to,dd,cnt+p[now][i].second+r[l][j].second);
			visr[l]=0;
			visp[to]=0;			
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		long long k,a,t;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a>>t;
			r[i].push_back(make_pair(a,t));
			p[a].push_back(make_pair(i,t));
		}
	}
	
	while(q--){
		long long x,y,ans=0;
		anss=1e9;
		cin>>x>>y;
		ans+=w[x]+w[y];
		visp[x]=1;
		dfs(x,y,0);
		visp[x]=0;
		printf("%lld\n",ans+anss);
	}
	
	return 0;
}

