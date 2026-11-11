#include<bits/stdc++.h>
using namespace std;
long long n,m,sum[500005],ans;
long long a[500005];
bool check(int x,int p) {
	if(a[p]*x-(sum[p]-sum[p-x])<=m) return 1;
	else return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; ++i) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) {
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1; i<=n; ++i) {
		if(a[i]*i-sum[i]<=m) ans=max(ans,(long long)i);
		else if(a[i]-a[i-1]>m) continue;
		else {
			int l=1,r=i;
			while(l<=r) {
				int mid=l+r>>1;
				if(check(mid,i)) l=mid+1;
				else r=mid-1;
			}
			ans=max(ans,(long long)r);
		}
	}
	printf("%lld",ans);
}
