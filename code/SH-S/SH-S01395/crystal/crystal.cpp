#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N],ans;
int calc(int l,int r) {
	return (r-l+1)*a[r]-(sum[r]-sum[l-1]);
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1; i<=n; i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	for (int i=1; i<=n; i++) {
		//start from i
		if (calc(i,n)<=m) {
			ans=max(ans,n-i+1);
			continue;
		}
		int l=i,r=n;
		while (l+1<r) {
			int mid=(l+r)>>1;
//			cerr<<"binary "<<mid<<' '<<calc(i,mid)<<endl; 
			if (calc(i,mid)<=m) l=mid;
			else r=mid;
		}
//		cerr<<"searched "<<i<<' '<<l<<endl;
		ans=max(ans,l-i+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
a[i] can only +x it can't -
so just add one by one,easy.
nonono,it's wrong.
we need to do 1~n and n~1.
thanks to big sample 
nonono,it's also wrong.
we start from i.
let me think,now we choose [l,r] crystals.
our goal is a[r].
so,ans=sum(a[r]-a[i]).
maintain prefix sum.done.
yesyesyes,then we can binary the answer.
let's go!
*/
