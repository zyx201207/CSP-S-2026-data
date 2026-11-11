#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int cnt[N],a[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	cnt[1]=0;
	for(int i=2; i<=n; i++) {
		cnt[i]=cnt[i-1]+(a[i]-a[i-1])*(i-1);
	}
	//cnt[r]-cnt[l]-(a[r]-a[l-1])*(l-1);
	int ans=0;
	for(int i=1; i<=n; i++) {
		int l=1,r=i-1,now=l;
		while(l<=r) {
			int mid=(l+r)/2;
			if(cnt[i]-cnt[mid]-(a[i]-a[mid-1])*(mid-1)<=m) {
				now=mid;
				r=mid-1;
			} else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}

