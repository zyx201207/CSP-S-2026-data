#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int p[500005];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		p[i]=p[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		int l=1,r=i;
		int pos=i;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-p[i]+p[mid-1]<=m) {
				r=mid-1;
				pos=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<'\n';
	return 0;
}
