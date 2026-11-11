#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N],ans;
int erfen(int ll,int rr,int xx) {
	int bzy=0;
	while(ll<=rr) {
		int mid=(ll+rr)/2;
		int lz=sum[mid]-sum[xx]-(a[mid]-a[xx] )*(xx-1);
		if(lz<=m) {
			bzy=max(bzy,mid);
			ll=mid+1;
		} else {
			rr=mid-1;
		}
	}
	return bzy;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2; i<=n; i++) {
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=1; i<=n; i++) {
		int l=i,r=n;
		int ls=erfen(l,n,i);
		ans=max(ans,ls-i+1);
	}
	cout<<ans;
	return 0;
}