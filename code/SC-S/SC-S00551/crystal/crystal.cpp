#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=1;
	for(ll i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
//		cout<<i<<":"<<r<<"\n";
		ans=max(ans,i-r+1);
	}
	cout<<ans<<"\n";
	return 0;
}
