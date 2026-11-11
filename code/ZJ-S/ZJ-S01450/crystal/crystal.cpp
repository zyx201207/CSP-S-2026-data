#include <bits/stdc++.h>
#define int long long
using namespace std;
const int NB=5e5+4;
int n,m,maxd=0,a[NB],s[NB];
signed main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		int l=1,r=i,ans=-1;
		while(l<=r) {
			int mid=(l+r)/2,
				res=(i-mid+1)*a[i]-s[i]+s[mid-1];
			if(res<=m) {
				r=mid-1;
				ans=mid;
			} else l=mid+1;
		}
		maxd=max(maxd,i-ans+1);
	}
	cout<<maxd;
	return 0;
} 