#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
#define ll long long
ll c,n,m,d,q,k,ans,T[N],opp[505][505],road[505][505];
vector<pair<ll,ll>>e[505];
vector<pair<ll,ll>>a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	fill(opp[0],opp[505],1e18);
	for(ll i=1;i<=m;i++){
		cin>>T[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll p,t;
			cin>>p>>t;
			a[p].push_back({i,t});
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<a[i].size();j++){
			for(ll k=j+1;k<a[i].size();k++){
				ll l1=a[i][j].first,l2=a[i][k].first,w=a[i][j].second+a[i][k].second;
				opp[l1][l2]=opp[l2][l1]=min(opp[l1][l2],w);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(opp[i][j]!=1e18){
				e[i].push_back({j,opp[i][j]}),e[j].push_back({i,opp[j][i]});
			}
		}
	}
	for(ll i=1;i<=n;i++){
		bool vis[505]={};
		ll dis[505];
		fill(dis,dis+505,1e18);
		dis[i]=0;
		for(ll j=1;j<=n;j++){
			ll pos=0,minn=1e18;
			for(ll k=1;k<=n;k++){
				if(vis[k]==0&&dis[k]<minn){
					minn=dis[k],pos=k;
				}
			}
			vis[pos]=1;
			for(auto k:e[pos]){
				dis[k.first]=min(dis[k.first],k.second+dis[pos]);
			}
		}
		for(ll j=1;j<=n;j++){
			road[i][j]=dis[j];
		}
	}
	for(ll i=1;i<=q;i++){
		ll u,v,minn=1e18;
		cin>>u>>v;
		for(ll j=0;j<a[u].size();j++){
			for(ll k=0;k<a[v].size();k++){
				ll l1=a[u][j].first,l2=a[v][k].first;
				ll w=a[u][j].second+a[v][k].second;
				minn=min(minn,road[l1][l2]+w);
			}
		}
		cout<<minn+T[u]+T[v]<<'\n';
	}
	return 0;
}