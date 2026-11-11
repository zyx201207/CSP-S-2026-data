#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	vector<ll> v(n);
	for(ll i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	ll  cnt1 = 0,cnt2=0,cnt=0;
	ll  k = v[n/2];
	for(ll i = n/2-1; i >= 0; i--){
		for(ll j = 0; j <= m; j++){
			ll l = k-v[i];
			if(m>=l){
				m-=l;
				v[i]+=l;
			}
		}
	}
	for(ll i = n/2; i < n; i++){
		ll  tmp = v[i+1]-k;
		if(tmp==0){
			k=v[i+1];
		}
		if(m>=tmp*i){
			for(ll j = 0; j <= i; j++){
				v[j]+=tmp;
			}
			k=v[i+1];
		}
		m-=tmp*i;
	}
	for(ll i = n/2; i>=0; i--){
		if(k==v[i]){
			++cnt1;
		}else{
			break;
		}
	}
	for(ll i = n/2; i < n; i++){
		if(k==v[i]){
			++cnt2;
		}
	}
	cnt=cnt1+cnt2-1;
	cout<<cnt; 
	return 0;
}