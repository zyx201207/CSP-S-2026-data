#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],f[500010],ans,ans1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		f[i]=a[i]+f[i-1];
	}
	for(int i=1;i<=n;i++) {
		ll l=1ll,r=i,ans=0ll;
		while(l<=r) {
			ll mid=((l+r)>>1);
			if(a[i]*(i-mid+1)-(f[i]-f[mid-1])<=m) {
				ans=mid;
				r=mid-1;
			} else l=mid+1;
		}
		if(ans) {
			ans1=max(ans1,i-ans+1ll);
		}
	}
	cout<<ans1;
	return 0;
}