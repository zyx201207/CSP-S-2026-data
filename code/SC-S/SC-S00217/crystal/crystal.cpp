#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll a[N],sum[N];
ll ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=n;i>=1;i--){
		ll l=0,r=i;
		while(l+1<r){
			ll mid=(l+r)/2;
			if(a[i]*(i-mid+1LL)-0LL-(sum[i]-sum[mid-1])<=m)r=mid;
			else l=mid;
			
		}
		ans=max(ans,i-r+1LL);
	}
	cout<<ans<<endl;
	return 0;
}