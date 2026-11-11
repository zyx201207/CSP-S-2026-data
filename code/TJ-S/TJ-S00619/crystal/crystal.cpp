#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
bool fun(ll t,ll mx,vector<ll>&vec){
	ll sum=0;
	for(ll i:vec){
		if(i>t) break;
		else sum+=t-i;
	}
	if(sum<=mx) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,tmp;cin>>n>>m;vector<ll> v;
	for(ll i=1;i<=n;i++){
		cin>>tmp;v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	ll l=v[0],r=v[v.size()-1],mid;
	while(l<=r){
		mid=(l+r)/2;
		//cout<<l<<' '<<r<<' '<<mid<<' '<<fun(mid,m,v)<<'\n';
		if(fun(mid,m,v)){l=mid+1;}
		else r=mid-1;
	}
	ll ans=0;
	if(fun(mid,m,v)){l--;}
	for(ll i:v){
		if(l>=i) ans++;
		else break;
		m-=l-i;
	}
	//cout<<m<<' ';
	cout<<ans;
	return 0;
}
//Nah,i'd win!
