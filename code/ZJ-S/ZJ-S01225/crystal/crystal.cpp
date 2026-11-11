#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

int n, m, a[500005], b[500005];

bool cmp(int aa, int bb){
	return aa > bb;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	std::sort(a + 1, a + 1 + n, cmp);
	for(int i = 1;i <= n;i++)
		b[i] = b[i - 1] - a[i];
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int l = i, r = n;
		while(l <= r){
			int mid = (l + r) / 2;
			if(b[mid] - b[i] + (mid - i) * a[i] <= m)
				l = mid + 1;
			else
				r = mid - 1;
		}
		ans = std::max(ans, l - i);
//		printf("%lld\n", l - i);
	}
	printf("%lld", ans);
	return 0;
}