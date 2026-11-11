#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
typedef long long ll;
using namespace std;
ll n,m,ans=1;vector<ll> a,su;
bool check(ll x,ll i){
	ll t=su[i]-su[i-x],p=a[i]*x;
	return p-t<=m;
}
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;a.resize(n+1);su.resize(n+1);
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	for(ll i=1;i<=n;i++)su[i]=su[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,jg=1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid,i))l=mid+1,jg=mid;
			else r=mid-1;
		}
		ans=max(ans,jg);
	}
	cout<<ans<<endl;
	return 0;
}