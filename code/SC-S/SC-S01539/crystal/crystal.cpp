#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],need,ans,l=1,r=0;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;l=r=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while(l<=n&&r<=n) {
		while(r<=n&&need<=m) {++r;need=need+(r-l)*(a[r]-a[r-1]);}
		// cout<<l<<' '<<r<<' '<<need<<'\n';
		ans=max(r-l,ans);
		need-=a[r]-a[l];
		++l;
	}
	cout<<ans;
	return 0;
}