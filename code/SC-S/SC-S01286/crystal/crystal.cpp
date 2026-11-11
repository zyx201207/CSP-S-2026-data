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
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	ll n,m,times=0;
	cin>>n>>m;
	vector<ll>a(n);
	for(ll i=0;i<n;i++)cin>>a[i];
	ll aver;
	aver=n/2;
	aver=a[aver];
	sort(a.begin(),a.end());
	for(ll i=0;i<n;i++){
		if(m<=0)break;
		if(a[i]<aver){
			a[i]++;m--;times++;
		}
	}
	cout<<times+1;
	AK;
}