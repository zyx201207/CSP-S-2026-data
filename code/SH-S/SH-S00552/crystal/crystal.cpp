#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],sum[1000005];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=2; i<=n; i++) {
		//int i=4;
		int l=0,r=i-1,mid,mx;
		//cout<<a[i]<<endl;
		while(l<=r) {
			mid=(l+r)>>1;
			//cout<<mid<<" "<<(i-mid)*a[i]<<" "<<(sum[i-1]-sum[mid-1])<<endl;
			if((i-mid-1)*a[i]-(sum[i-1]-sum[mid])<=m) {
				mx=mid;
				r=mid-1;
			} else l=mid+1;
		}
		//cout<<mx;
		///cout<<i-mx<<'\n';
		ans=max(i-mx,ans);
	}
	cout<<ans;
}
