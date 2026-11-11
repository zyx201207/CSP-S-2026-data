#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n,m,a[N],f[N],ans = 1;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int t = m;
	for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	int j = 1;
	f[1] = 1;
//	for(int i = 1;i <= n;i ++) cout << a[i] << " ";
//	puts(" ");
	for(int i = 2;i <= n;i ++) {
		int c = (a[i] - a[i - 1]) * (i - j);
		if(m >= c) m -= c,f[i] = f[i - 1] + 1;
		else {
			int tx = 1,t = m;
			while(m < c && j < i) {
				m += (a[i] - a[j]);
				j ++;
				tx --;
			}
			if(m >= c) {
				m -= c;
				f[i] = f[i - 1] + tx;
			}else f[i] = f[i - 1];
		}
		ans = max(ans,f[i]);
	}
	printf("%lld\n",ans);
	return 0;
} 
