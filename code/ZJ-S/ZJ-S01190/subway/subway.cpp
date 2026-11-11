#include<bits/stdc++.h>
#include<vector>
#define ll long long
using namespace std;
ll m,n,c,d,q;
ll w[50010];
ll a[510][510];
ll k[510];
ll t[510][510];
ll ans;
ll mn=1e9;
ll oi[5050][5050];
struct node{
	ll v,c;
};
vector<node>e[10010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		ans=w[u]+w[v];
		cout<<ans+t[1][u]+t[1][v];
	}
	return 0;  
}