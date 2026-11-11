#include<bits/stdc++.h>
#define pii pair<long long,long long>
#define ll long long
using namespace std;
const int M=5e5+5,N=505;
ll c,n,m,d,q,u[M],k;
ll edge[N][N];
vector<pii> to_sta[M];
map<ll,ll> mp[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>u[i];
	}
	memset(edge,0x3f,sizeof(edge));
	for(ll i=1;i<=n;i++){
		edge[i][i]=0;
	}
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll go,tim;cin>>go>>tim;
			to_sta[go].emplace_back(make_pair(tim,i));
		}
	}
	for(ll i=1;i<=m;i++){
		for(auto road1:to_sta[i]){
			for(auto road2:to_sta[i]){
				if(road1.second!=road2.second){
					edge[road1.second][road2.second]=min(edge[road1.second][road2.second],road1.first+road2.first);
				}
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;cin>>x>>y;
		ll ans=1e18;
		for(auto road1:to_sta[x]){
			for(auto road2:to_sta[y]){
				ans=min(ans,edge[road1.second][road2.second]+road1.first+road2.first);
			}
		}
		cout<<ans+u[x]+u[y]<<"\n";
	}
	return 0;
}