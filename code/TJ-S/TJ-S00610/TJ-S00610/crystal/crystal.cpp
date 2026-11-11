#include <cstdio>
#include <cassert>
#include <algorithm>
const int N=500010;
long long a[N];
long long s[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+1ll*(a[i]-a[i-1])*(i-1);
	for (int i=1;i<n;i++) assert(s[i]<=s[i+1]);
	int ans=0;
	long long sum=0;
	for (int i=1,j=1;i<=n;i++) {
		while (j<=n && sum<=m) j++,sum+=1ll*(j-i)*(a[j]-a[j-1]);
		ans=std::max(ans,j-i);
		sum-=a[j]-a[i];
	}
	printf("%d\n",ans);
	return 0;
}
