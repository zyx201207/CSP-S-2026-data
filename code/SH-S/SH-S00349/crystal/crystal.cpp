#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+2;
int n;
long long m,a[N];
long long l=1,ad=0,ans=LONG_LONG_MIN;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int r = 1; r <= n; r++) {
		ad += (r-l)*(a[r]-a[r-1]);
		while (ad > m) {
			ad -= (a[r]-a[l]);
			l++;
		}
		ans = max(ans,r-l+1);
	}
	printf("%lld",ans);
	
	return 0;
}
