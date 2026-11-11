#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,t;
ll n,d;
const ll maxn=1e5+7;
ll x[maxn];
vector <ll> g[maxn];

void add(ll u,ll v){
	g[u].push_back(v);
	g[v].push_back(u);
}

ll min_dist=1e18+7,min_times=0;
void dfs(ll l,ll r,ll now,ll dist){
	if (now==r){
		if (dist==min_dist) min_times++;
		else if (dist<min_dist) {
			min_dist=dist;
			min_times=1;
		}
		return;
	}
	for (ll to:g[now]){
		if (to<now) continue;
		if (to>now+d) break;
		dfs(l,r,to,++dist);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

  	ios::sync_with_stdio(0);
  	cin.tie(0);
 	cout.tie(0);


	cin>>c>>t;
	while (t--){
		memset(x,0,sizeof x);
		cin>>n>>d;
		for (ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for (ll i=1;i<=n;i++){
			for (ll j=i+1;j<=n;j++){
				if (abs(j-i)<=d) add(i,j);
			}
		}
		ll ans=0;
		for (ll i=1;i<=n;i++){
			min_dist=1e18+7,min_times=0;
			for (ll j=i+1;j<=n;j++){
				dfs(i,j,i,0);
			}
			if (min_times==2) ans++;
		}
		cout<<ans<<"\n";
	}


}


