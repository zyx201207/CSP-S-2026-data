#include<bits/stdc++.h>
#define AK return 0
using namespace std;
using ll=long long;
static ll qpow(ll x,ll k,ll mod){
	ll res=1;
	while(k){
		if(k&1)res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
static ll qpow(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1)res=res*x;
		x=x*x;
		k>>=1;
	}
	return res;
}
ll num_sum(string x){
	ll cnt=0;
	for(ll i=0;i<x.size();i++){
		if('0'<=x[i]&&x[i]<='9'){
			cnt=cnt+x[i]-48;
		}
	}
	return cnt;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	ll k,t;
	cin>>k>>t;
	while(t--){
		ll x,y;
		cin>>x>>y;
		vector<ll>a(x);
		for(ll i=0;i<x;i++)cin>>a[i];
		if(a[0]<0){
			cout<<(a[0]+a[x-1])/2<<"\n";
		}
		else{
			cout<<(a[x-1]-a[0]/2)<<"\n";
		}
	}
	AK;
}