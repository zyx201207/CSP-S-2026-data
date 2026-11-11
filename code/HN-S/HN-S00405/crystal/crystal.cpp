#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000100],ans,sum[1000100];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ii=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) r=mid-1,ii=mid;
			else l=mid+1;
		}
		ans=max(ans,i-ii+1);
	}
	cout<<ans;
	return 0;
} 
/*
4 10
100000000000 238947982372 213847219083 1828738273
*/
