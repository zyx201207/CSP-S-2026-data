#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,T,n,d,a[5005];
ll dis[5005][5005];
vector<pair<ll,ll>> p[5005]; 
void solve(){
	cin>>n>>d;
	for(ll i=1ll;i<=n;i++) cin>>a[i];
	for(ll i=1ll;i<=n;i++){
		for(ll j=1ll;j<=n;j++){
			if(i==j) dis[i][j]=0ll;
			else if(max(a[i],a[j])-min(a[i],a[j])<=d)
			dis[i][j]=1ll;
			else dis[i][j]=1e18;
		}
	}                        
	for(ll k=1ll;k<=n;k++){
		for(ll i=1ll;i<=n;i++){
			for(ll j=1ll;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	/*for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++) cout<<dis[i][j]<<' ';
		cout<<'\n';
	}*/
	ll ans=0ll;
	for(ll i=1ll;i<=n;i++){
		for(ll j=i+2ll;j<=n;j++){
			ll cnt=0ll;
			for(ll k=i+1ll;k<=j-1ll;k++){
				if((dis[i][k]+dis[k][j])==dis[i][j]) cnt++;
			}
			if(cnt==2ll) ans++;
	//		if(cnt==2) cout<<i<<' '<<j<<'\n'; 
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
}
