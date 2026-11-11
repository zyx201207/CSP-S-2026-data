#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int M = 32;
int B[N][M],n,m,a[N],ans,tmp[N];

signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i ++) {
		scanf("%lld",&a[i]);
		for(int j = 0;(1ll << j) <= a[i];j ++) {
			if(a[i] & (1ll << j)) {
				B[i][j] = 1;
			}
		}
	}
	for(int i = 31;i >= 0;i --) {
		int cnt = 0;
		for(int j = 1;j <= n;j ++) {
			if(B[j][i] && !tmp[j]) cnt ++;
		}
		if(cnt < m) continue;
		ans += (1ll << i);
		for(int j = 1;j <= n;j ++) {
			if(!B[j][i]) tmp[j] = 1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
