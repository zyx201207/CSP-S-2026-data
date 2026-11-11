#include <cstdio>
#include <algorithm>
#define ll long long
#define N (int(5e5 + 10))
#define max(a, b) (((a) > (b)) ? (a) : (b))

using std::sort;

ll a[N], pre[N], m;
int n, l, r, ans, i, j;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(i = 1; i <= n; i ++)
		scanf("%lld", a + i);
	sort(a + 1, a + i);
	for(i = 1; i <= n; i ++){
		pre[i] = pre[i - 1] + a[i], l = 1, r = i;
		while(l <= r){
			int mid = l + r >> 1;
			if(1ll * (i - mid) * a[i] - (pre[i - 1] - pre[mid - 1]) <= m)
				r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	printf("%d\n", ans);
	return 0;
} 