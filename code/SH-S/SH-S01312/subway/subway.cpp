#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao1=5e2+10,biao2=1e6+10;
ll dis[biao1][biao1],tid,n,m,d,q,a[biao2];
vector<ll> v[biao2],t[biao2];

void solve(){
	ll x,y;
	cin>>x>>y;
	
	ll ans=1e18;
	for(ll i=0;i<v[x].size();i++){
		for(ll j=0;j<v[y].size();j++){
			ans=min(ans,dis[v[x][i]][v[y][j]]+t[x][i]+t[y][j]+a[x]+a[y]);
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>tid>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll len;
		cin>>len;
		while(len--){
			ll x,y;
			cin>>x>>y;
			v[x].push_back(i);
			t[x].push_back(y);
		}
	}
	
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			dis[i][j]=1e18;
	for(ll i=1;i<=n;i++) dis[i][i]=0;
	
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<v[i].size();j++){
			for(ll k=j+1;k<v[i].size();k++){
				ll x=v[i][j],y=v[i][k],tx=t[i][j],ty=t[i][k];
				dis[x][y]=min(dis[x][y],tx+ty);
				dis[y][x]=min(dis[y][x],tx+ty);
			}
		}
	}
	
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	
	while(q--) solve();
	
	return 0;
}
