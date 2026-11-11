#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test(x) cerr << "Test: " << (x) << '\n';
#define debug test("qwq")
#define pii pair<int,int>
#define eb emplace_back
#define F first
#define S second
const int N = 5e5 + 19;
int n, a[N], m, sum[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n); int ans=0;
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;++i) {
		int l=1,r=i;
		while (l<r) {
			int mid=(l+r)>>1;
			int res=0;
			{
				int tot=i-mid+1;
				int dis=tot*a[i]-(sum[i]-sum[mid-1]);
				// assert(dis>=0);
				res=m>=dis;
			}
			if (res) r=mid;
			else l=mid+1;
		} ans=max(ans,i-r+1);
	} printf("%lld\n",ans);
	return 0;
}
/*
g++ A.cpp -o tmp &&./tmp
*/