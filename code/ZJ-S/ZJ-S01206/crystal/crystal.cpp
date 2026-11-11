#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,ans;
ll m,a[N],sum[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	int l=1;
	for (int i=1;i<=n;i++) {
		while (a[i]*(i-l+1)-sum[i]+sum[l-1]>m) {
			l++;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
