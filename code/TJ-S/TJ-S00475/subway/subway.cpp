#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
const ll N = 5e5+510;
struct Edge{
	ll to;
	ll w;
};
vector<Edge> e[N*4];
vector<Edge> k[550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<ll> w(m+1,0);
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++){
		ll ki;
		cin >> ki;
		ll from=i+500000;
		for(int j = 1;j<=ki;j++){
			ll a,t;
			cin >> a >> t;
			k[i].push_back({a,t});
			e[a].push_back({i,t});
		}
	} 
	vector<vector<ll>> djs(n+1,vector<ll>(n+1,INT_MAX));
	for(int i = 1;i<=n;i++){
		djs[i][i]=0;
	}
	for(int i = 1;i<=n;i++){
		for(auto x : k[i]){
			for(auto j : e[x.to]){
				djs[i][j.to]=min(djs[i][j.to],x.w+j.w);
			}
		} 
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				djs[i][j]=min(djs[i][k]+djs[k][j],djs[i][j]);
			}
		}
	}
	for(int i = 1;i<=q;i++){
		ll x,y;
		cin >> x >> y;
		ll ans=LLONG_MAX;
		for(auto j:e[x]){
			for(auto k:e[y]){
				ans=min(djs[j.to][k.to]+j.w+k.w,ans);
			}
		}
		ans+=w[x]+w[y];
		cout << ans << '\n';
	}
	return 0;
}
