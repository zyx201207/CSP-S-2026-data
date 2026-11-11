#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,ans;
ll m,a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			ll mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		ans=(ll)max(1LL*ans,i-l+1);
	}
	cout<<ans;
	return 0;
}