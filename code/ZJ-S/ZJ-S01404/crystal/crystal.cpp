#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,a[500005],s[500005],ans,ans1,cnt1;
struct d{
	LL cnt,s;
}k[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort (a+1,a+1+n);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (LL i=1;i<=n;i++){
		LL l=1,r=i;
		ans=r;
		while (l<=r){
			LL mid=(l+r)>>1;
			if ((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
		ans1=max(ans1,i-ans+1);
	}
	cout<<ans1;
	return 0;
}
