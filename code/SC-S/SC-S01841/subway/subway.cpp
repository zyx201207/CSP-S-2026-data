#include<bits/stdc++.h>
#define ll int64_t
#define endl '\n'
using namespace std;
ll C,n,m,d,q,W[500000+10],jz[500+10][500+10];
struct node{
	ll v,w;
};
vector<node> nvt[500000+10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>W[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			nvt[a].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) jz[i][j]=1e18;
	for(ll i=1;i<=n;i++) jz[i][i]=0;
	for(ll i=1;i<=m;i++){
		for(auto v1:nvt[i]){
			for(auto v2:nvt[i]){
				if(v1.v==v2.v) continue;
				jz[v1.v][v2.v]=min(jz[v1.v][v2.v],v1.w+v2.w);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(jz[i][k]+jz[k][j]<jz[i][j]){
					jz[i][j]=jz[i][k]+jz[k][j];
				}
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(auto v1:nvt[x]){
			for(auto v2:nvt[y]){
				ans=min(ans,jz[v1.v][v2.v]+v1.w+v2.w+W[x]+W[y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}