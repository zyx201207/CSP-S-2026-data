#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=500009;
const ll MM=1009;
const ll N=509;
const ll INF=1e10;
ll c,n,m,dd,q;
ll w[M];
ll dis[MM][MM],rd[MM][MM];
bool vst[3][M];
ll aa[3][M],tt[3][M];
vector< pair<ll,ll> > to[MM];
void Dij(ll rt){
	priority_queue< pair<ll,ll> , vector< pair<ll,ll> > ,greater<> > pq;
	pq.push( make_pair(0,rt) );
	while(!pq.empty()){
		ll d=pq.top().first;
		ll u=pq.top().second;
		pq.pop();
		ll sze=to[u].size();
		for(int i=0;i<sze;++i){
			ll v=to[u][i].first;
			ll val=to[u][i].second;
			if(rd[rt][v]>rd[rt][u]+val){
				rd[rt][v]=rd[rt][u]+val;
				pq.push( make_pair(rd[rt][v],v) );
			}
		}
	}
}
void solveminrd(){
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j){
			dis[i][j]=INF;
			rd[i][j]=INF;
		}
	for(int i=1;i<=m;++i) dis[i][i]=0;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		ll k;
		cin>>k;
		ll a[k+1],t[k+1];
		for(int j=1;j<=k;++j) cin>>a[j]>>t[j];
		for(int ii=1;ii<=k;++ii){
			for(int jj=1;jj<=k;++jj){
				dis[a[ii]][a[jj]]=min(dis[a[ii]][a[jj]],t[ii]+t[jj]);
				dis[a[jj]][a[ii]]=min(dis[a[jj]][a[ii]],t[jj]+t[ii]);
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=i;j<=m;++j){
			if(dis[i][j]!=INF){
				to[i].push_back( make_pair (j,dis[i][j]) );
				to[j].push_back( make_pair (i,dis[i][j]) );
			}
		}
	}
	for(int i=1;i<=m;++i) rd[i][i]=0;
	for(int i=1;i<=m;++i)
		Dij(i);
	for(int i=1;i<=q;++i){
		ll x,y;
		cin>>x>>y;
		cout<<rd[x][y]+w[x]+w[y]<<endl;
	}
}
void solve2(){
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			ll tim;
			cin>>aa[i][j]>>tim;
			tt[i][aa[i][j]]=tim;
			vst[i][aa[i][j]]=1;
		}
	}
	ll bst=INF;
	for(int i=1;i<=m;++i){
		if(vst[1][i]==1&&vst[2][i]==1) bst=min(bst,tt[1][i]+tt[2][i]);
	}
	for(int i=1;i<=q;++i){
		ll ans=INF;
		ll x,y;
		cin>>x>>y;
		if(vst[1][x]==1&&vst[1][y]==1) ans=min(ans,tt[1][x]+tt[1][y]);
		if(vst[2][x]==1&&vst[2][y]==1) ans=min(ans,tt[2][x]+tt[2][y]);
		if(vst[1][x]==1&&vst[2][y]==1) ans=min(ans,tt[1][x]+tt[2][y]+bst);
		if(vst[2][x]==1&&vst[1][y]==1) ans=min(ans,tt[2][x]+tt[1][y]+bst);
		cout<<ans+w[x]+w[y]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	if(c==20||c==21) solve2();
	else solveminrd();
	return 0;
}
