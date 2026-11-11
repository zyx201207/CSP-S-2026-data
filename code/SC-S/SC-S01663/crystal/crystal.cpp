#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	bool f=1;
	ll n,m,l=1;cin>>n>>m;
	vector<ll> a(n+1);cin>>a[1]>>a[2];
	ll k=a[2]-a[1];
	for(ll i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=k)f=0;
	}
	if(!f){
		vector<ll> ans(n+1,1),cnt(n+1);
		sort(begin(a)+1,end(a),greater<>());
		for(ll i=2;i<=n;i++){
			while(m-cnt[l]<a[l]-a[i])l++;
			for(ll j=l;j<i;j++)ans[j]++,cnt[j]+=a[j]-a[i];
		}
		cout<<*max_element(begin(ans),end(ans));
	}
	else{
		ll ans=1;
		while((1+ans)*ans/2*k<=m)ans++;
		cout<<ans;
	}
	return 0;
}