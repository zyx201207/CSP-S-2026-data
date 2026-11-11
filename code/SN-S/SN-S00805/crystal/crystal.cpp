// green
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],sa[500005];
bool check(ll x){
	for(ll i=1;i<=n-x+1;i++){
		ll li=i,ri=i+x-1;
		ll cost=a[ri]*(ri-li+1)-(sa[ri]-sa[li-1]);
		if(cost<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		
	}
	ll l=1,r=n;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sa[i]=sa[i-1]+a[i];
	}
	while(l<r){
		if(l+1==r){
			if(check(r)){
				l=r;
			}
			else{
				r=l;
			}
			break;
		}
		ll mid=l+r>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
