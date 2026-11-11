#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> mp[50];
vector<ll> v;
ll n,m;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll a;
		cin>>a;
		ll t=0,ta=a;
		while(ta){
			if(ta&1){
				mp[t++].push_back(a);
			}
			ta>>=1;
		}
	}
	ll idx;
	for(ll i=32;i>=0;i--){
		if(mp[i].size()>=m){
			idx=i;
			ll t=1,t1=0;
			for(ll i=0;i<=30;i++){
				t1+=t;
				t*=2;
			}
			for(ll x:mp[i]){
				v.push_back(x&t1);
			}
			break;
		}
	}
	sort(v.begin(),v.end());
	ll vn=v.size();
	ll res=0;
//	cout<<vn<<' ';
	for(ll i=vn-1;i-m+1>=0;i--){
		ll t=v[i];
		for(ll j=i-1;j>=i-m+1;j--){
//			cout<<t<<" ";
			t&=v[j];
		}
//		cout<<'\n';
		res=max(res,t);
	}
	cout<<res;
	return 0;
}
