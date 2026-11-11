#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500004;
ll n,m,a[N],ans;
bool check(ll x){
	ll res=0; 
	for(ll i=1;i<=n;i++){
		res+=(a[i]-a[i-1])*min(x+1,i-1);
		if(i>x) res-=(a[i]-a[i-x]);
		if(i>=x&&res<=m) return true;
	}
	return false;
}
void solve(){
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;l=mid+1;
		}else r=mid-1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	solve();
	cout<<ans<<"\n";
	return 0; 
}
