#include<bits/stdc++.h>
#define ll long long
#define M 500000
using namespace std;
int c,n,m,d,q;
struct p{
	ll u,dis;
};
vector<p>e[1000005];
ll uu[500005],dd[500005],diss[1000005],a[500005];
bool vis[1000005];
ll BFS(ll xx,ll yy){
	memset(diss,0x3f3f,sizeof diss);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
	memset(vis,0ll,sizeof vis);
	pq.push({0ll,xx});
	diss[xx]=0ll;
	while(!pq.empty()){
		ll minn=pq.top().first;
		ll point=pq.top().second;
		if(point==yy){
			return minn;
		}
		pq.pop();
		if(vis[point]==1){
			continue;
		}
		vis[point]=1;
		for(auto edge:e[point]){
			if(diss[edge.u]>diss[point]+edge.dis){
				diss[edge.u]=diss[point]+edge.dis;
				pq.push({diss[edge.u],edge.u});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",uu+j,dd+j);
			if(j>=2){
				e[uu[j]].push_back({uu[j-1],0ll});
				e[uu[j-1]].push_back({uu[j],0ll});
				e[uu[j]].push_back({uu[j]+M,dd[j]});
				e[uu[j]+M].push_back({uu[j],dd[j]});
			}
		}
	}
	while(q--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",a[x]+a[y]+BFS(x+M,y+M));
	}
}
