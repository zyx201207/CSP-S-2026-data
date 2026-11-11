#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	vector<ll> w(m+1),a[n+1];
	vector<vector<ll>> t(n+1,vector<ll>(m+1));
	vector<vector<pair<ll,ll>>> g(m+1);
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1,A,T,k;i<=n&&cin>>k;i++){
		for(ll j=1;j<=k&&cin>>A>>T;j++)a[i].push_back(A),t[i][A]=T;
		g[a[i][0]].push_back({a[i][1],i}),g[a[i][k-1]].push_back({a[i][k-2],i});
		for(ll j=1;j<k-1;j++)g[a[i][j]].push_back({a[i][j-1],i}),g[a[i][j]].push_back({a[i][j+1],i});
	}
	for(ll r=1;r<=q;r++){
		ll x,y;cin>>x>>y;
		vector<ll> vis(m+1),ans;
		function<void(pair<ll,ll>,pair<ll,ll>,ll)>dfs=[&](pair<ll,ll> u,pair<ll,ll> fa,ll ans1){
			if(vis[u.first])return;
			vis[u.first]=1;
			if(u.second!=fa.second)ans1+=t[u.second][fa.first]+t[fa.second][fa.first],fa=u;
			if(u.first==y){ans.push_back(ans1+t[u.second][u.first]),vis[y]=0;return;}
			for(auto v:g[u.first])dfs(v,u,ans1);
			vis[u.first]=0;
		};
		dfs({x,0},{x,0},w[x]+w[y]);
		cout<<*min_element(begin(ans),end(ans))<<'\n';
	}
	return 0;
}