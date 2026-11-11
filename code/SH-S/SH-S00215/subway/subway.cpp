#include<iostream>
#include<vector>
#include<cstdio>
using ll=long long;
ll c,n,m,d,q;
std::vector<ll>w,k;
std::vector<std::vector<ll>>a,t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin>>c>>n>>m>>d>>q;
	w.resize(m+1);
	k.resize(n+1);
	a.resize(n+1);
	t.resize(n+1);
	for(ll i=1;i<=m;++i){
		std::cin>>w[i];
	}
	for(ll i=1;i<=n;++i){
		std::cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(ll j=1;j<=k[i];++j){
			std::cin>>a[i][j]>>t[i][j];
		}
	}
	for(ll r=1;r<=q;++r){
		ll x,y;
		std::cin>>x>>y;
		std::cout<<w[x]+w[y]<<std::endl; // Send me some pts please.
	}
	return 0;
} // zero2hundred pts
