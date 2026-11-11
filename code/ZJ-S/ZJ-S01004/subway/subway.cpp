#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=5e5+9,N=509;
ll C,n,m,d,Q,w[M],k[N],dis[N][N],diss[N],vis[N];
vector<pair<ll,ll> > a[N+M];
void diji(ll x){
	for(ll i=0;i<=n;i++) diss[i]=1e18,vis[i]=0;
	diss[x]=0;
	for(ll t=1;t<=n;t++){
		ll c=0;
		for(ll i=1;i<=n;i++){
			if(!vis[i] && diss[i]<diss[c]) c=i;
		}
		vis[c]=1;
		for(ll i=0;i<a[c+m].size();i++){
			ll next=a[c+m][i].first,wi=a[c+m][i].second;
			for(ll j=0;j<a[next].size();j++){
				ll nt=a[next][j].first-m,wwi=a[next][j].second;
				if(!vis[nt] && diss[nt]>diss[c]+wi+wwi){
					diss[nt]=diss[c]+wi+wwi;
				}
			}
		}
	}
	for(ll i=1;i<=n;i++) dis[x][i]=diss[i];
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll aa,tt;
			cin>>aa>>tt;
			a[m+i].push_back({aa,tt});
			a[aa].push_back({m+i,tt});
		}
	}
	for(ll i=1;i<=n;i++) diji(i);
	while(Q--){
		ll ans=1e18,x,y;
		cin>>x>>y;
		for(ll i=0;i<a[x].size();i++){
			for(ll j=0;j<a[y].size();j++){
				pair<ll,ll> qx=a[x][i],qy=a[y][j];
				ans=min(qx.second+qy.second+dis[qx.first-m][qy.first-m],ans);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
