#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
ll n,m,a[N],sum[N];
bool check(ll l,ll r){
	if((sum[r]-sum[l]-(l-1)*(a[r]-a[l]))>m) return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sum[1]=0;
	for(ll i=2;i<=n;i++) sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	ll ans=0,l=1,r=n;
	for(int i=1;i<=n;i++){
		if(n-i<=ans) break;
		if(i>1){
			l=r;
			r=n;
		}
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(i,mid)) l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r-i+1);
	}
	cout<<ans;
	return 0;
} 