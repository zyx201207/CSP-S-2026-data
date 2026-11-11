#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int n,m,a[500005],sum[500005],ans;
int find(int l,int r,int x) {
	int res=-1;
	while(l<=r) {
		int mid=(l+r)>>1;
//		cout<<x<<" "<<mid<<" "<<a[x]*(x-mid)<<" "<<(sum[x-1]-sum[mid-1])<<"\n";
		if(a[x]*(x-mid)-(sum[x-1]-sum[mid-1])<=m) {
			res=mid;
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	return res;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++) {
		int ops=find(1,i-1,i);
		if(ops!=-1) {
			ans=max(ans,i-ops+1);
		} else ans=max(ans,1ll);
	}
	cout<<ans;
	return 0;
}