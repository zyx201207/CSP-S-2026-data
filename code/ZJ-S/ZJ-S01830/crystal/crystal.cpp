#include <bits/stdc++.h>
using namespace std;
#define M 500005
#define ll long long
int n;
ll m,a[M],s[M];
int main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	ll ans=-1;
	for(int k=1;k<=n;k++){
		ll l=1,r=k,now=-1;
		while(l<=r){
			ll mid=(l+r)/2;
			if((k-mid+1)*a[k]-(s[k]-s[mid-1])<=m){
				r=mid-1;
				now=k-mid+1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}
