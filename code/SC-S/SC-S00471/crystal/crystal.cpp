#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], d[N], pre[N];
int ans;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i ++ ){
		scanf("%lld", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i ++ ){
		d[i] = a[i + 1] - a[i];
		pre[i] = pre[i - 1] + d[i];
	}
	
	int cnt = 0, l, r = 1;
	for(l = 1; l <= n; l ++ ){
		while(r < n && cnt + (r - l + 1ll) * d[r] <= m){
			cnt += (r - l + 1ll) * d[r];
			r ++ ;
		}
		ans = max(ans, r - l + 1ll);
		cnt -= pre[r - 1] - pre[l - 1];
	}
	if(ans == 1) ans = 0;
	printf("%lld", ans);
	return 0;
}
