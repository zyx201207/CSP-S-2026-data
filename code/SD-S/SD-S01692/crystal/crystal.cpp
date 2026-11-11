#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const ll N=5e5+10;
ll ans,n,m,a[N],sum[N]; 

bool check(ll x){
	ll da=0;
	ll qjh=0;
	ll bsa=0;
	for(ll i=x;i<=n;i++){
		ll qjh=sum[i]-sum[i-x];
		ll bsa=x*a[i];
		da=bsa-qjh;
		if(da<=m){
			return 1;
		}
	}
	return 0;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n;

	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}

	cout<<ans<<"\n";
	return 0;
}
