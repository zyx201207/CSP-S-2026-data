#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,k,ans;
ll a[N],b[N];
ll vis[N];
vector<ll> G[N];
void dfs(ll x){
	if(G[x].size()==0) return ;
	for(ll i=0;i<G[x].size();i++){
		ll v=G[x][i];
		dfs(v);
		b[x]+=b[v];
	}
}
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i],++b[a[i]];
	for(ll i=n;i>=1;i--){
		if(vis[a[i]]) continue;
		vis[a[i]]=1;
		G[a[i+1]].push_back(a[i]);
	}
	dfs(a[n]);
	for(ll i=1;i<=m;i++) cout<<b[i]<<' ';
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
/*
10 3
4 3 1 2 3 4 1 2 1 3
3
1 3
2 1 3

*/
