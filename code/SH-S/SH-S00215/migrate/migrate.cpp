#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using ll=long long;
ll pc(ll x){
	ll num=0;
	while(x){
		++num;
		x&=x-1;
	}
	return num;
}
bool check(ll status,std::vector<ll>&x,ll n,ll d){
	if(pc(status)<2){
		return false;
	}
	std::vector<ll>a;
	for(ll i=0;i<n;i++){
		if((status>>i)&1){
			a.push_back(x[i]);
		}
	}
	for(ll i=1;i<a.size();i++){
		if(a[i]-a[i-1]>d){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	std::cin>>c>>t;
	while(t--){
		ll n,d;
		std::cin>>n>>d;
		std::vector<ll>x(n+1);
		for(ll i=1;i<=n;++i){
			std::cin>>x[i];
		}
		std::vector<std::vector<ll>>mn(n+1,std::vector<ll>(n+1,1e18)),num(n+1,std::vector<ll>(n+1));
		for(ll status=0;status<(1<<n);++status){
			if(check(status,x,n,d)){
				ll l=std::log2(status);
				ll r=std::log2(status&-status);
				ll nm=pc(status)-1;
				if(nm<mn[l][r]){
					mn[l][r]=nm;
					num[l][r]=1;
				}else if(nm==mn[l][r]){
					++num[l][r];
				}
			}
		}
		ll sum=0;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				if(num[i][j]==2){
					sum++;
				}
			}
		}
		std::cout<<sum<<std::endl;
	}
	return 0;
} // 8pts ToT
