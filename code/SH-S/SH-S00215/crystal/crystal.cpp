#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio> 
using ll=long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	std::cin>>n>>m;
	std::vector<ll>a(n+1),diff(n+1);
	bool flag=true;
	ll d=-1;
	for(ll i=1;i<=n;++i){
		std::cin>>a[i];
		if(d!=-1&&a[i]-a[i-1]!=d){
			flag=false;
		}
		if(d==-1&&i!=1){
			d=a[i]-a[i-1];
		}
	}
	if(flag){
		ll l=1,r=1e18;
		while(l<=r){
			ll mid=l+(r-l>>1LL);
			if(static_cast<double>(mid)*(mid-1)*d-2.0*m<=1e-6){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		std::cout<<l-1;
		return 0;
	}
	std::sort(a.begin()+1,a.end());
	for(ll i=2;i<=n;++i){
		diff[i]=a[i]-a[i-1];
	}
	ll ans=0;
	for(ll st=0;st<n;++st){
		ll sum=0,num=0;
		for(ll i=st;i<=n;++i){
			sum+=diff[i]*(i-st);
			if(sum>m){
				break;
			}
			num++;
		}
		ans=std::max(ans,num);
	}
	std::cout<<ans;
	return 0;
} // 75pts
