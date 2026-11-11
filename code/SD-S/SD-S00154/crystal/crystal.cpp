#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int itn;
typedef  __int128 i128;
int test = 1;
const int N = 5e5 + 5;
int n , ans;
ll a[N] , m , sum[N];
inline void solve() {
	scanf("%d%lld" , &n , &m);
	for (int i = 1 ; i <= n ; i++) scanf("%lld" , a + i);
	sort(a + 1 , a + n + 1);
	for (int i = 1 ; i <= n ; i++) {
		sum[i] = sum[i - 1] + a[i];
		int l = 0 , r = i;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if ((i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m)
				r = mid;
			else
				l = mid;
		}
		ans = max(ans , i - r + 1);
	}
	printf("%d\n" , ans);
}

signed main() {
	
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
//	scanf("%d" , &test);
	while (test--)
		solve();
	
	return 0;
}
