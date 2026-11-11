#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define READ_FILE 1
const i32 N = 5e5+5;
i32 n;
i64 m;
i64 a[N];
//i32 search(i32 MID) {
//	i32 l1,r1,l2,r2,mid1,mid2;
//	r1 = l2 = MID;
//	l1 = 1, r2 = n;
//	while(l1 < r1 || l2 < r2) {
//		mid1 = (l1 + r1) >> 1;
//		mid2 = (l2 + r2) >> 1;
//		
//		if((MID-mid1)*a[MID] - (pre[MID-1] - pre[mid1-1])
//		   + (pre[mid2-1] - pre[MID]) - (mid2-MID)*a[MID] <= m) {
//			// 有效，缩小
//			l1 = mid1;
//			r2 = mid2;
//		} else {
//			r1 = mid1 - 1;
//			l2 = mid2 + 1;
//		}
//	}
//	return mid2 - mid1 + 1;
//}
i32 main() {
#if READ_FILE
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	cin >> n >> m;
	bool sj1_equal_diff = 1;
	i32 sj1_diff = -1;
	for(i32 i=1;i<=n;i++) {
		cin >> a[i];
		if(i == 2) sj1_diff = a[i] - a[i-1];
		sj1_equal_diff = sj1_equal_diff && (i <= 2 || a[i] - a[i-1] == sj1_diff);
	}
	
	sort(a+1, a+n+1); // 顺序无直接关联，升序便于处理
	// 45 pts O(n^2) 暴力
	if (sj1_equal_diff) {
		// 如果是等差数列，显然选最中间的是正确的
		
		i32 mx = n >> 1;
		auto calc = [&](i64 in) -> i64 {
			return (sj1_diff*in*in) + sj1_diff*in;
		};
		i32 l=1,r=mx,mid;
		while(l < r) {
			mid = (l+r) >> 1;
			if(calc(mid) <= m) l = mid+1;
			else r = mid;
		}
		// r-1 为最终两侧共选的数的个数
		-- r;
		if(r < mx && calc(r) + sj1_diff*(r+1) <= m) cout << 2*r + 2;
		else cout << 2*r + 1;
	} else if (n <= 5000) {
		i32 ans = 0;
		for(i32 i=1;i<=n;i++) {
			// 双指针，找到左右端点
			i64 tot = 0;
			i32 cnt = 1;
			for(i32 l=i,r=i;l >= 2 || r <= n-1;) {
				if(l >= 2) {
					tot += a[i] - a[--l];
					if(tot > m) break;
					++ cnt;
				}
				if(r <= n-1) {
					tot += a[++r] - a[i];
					if(tot > m) break;
					++ cnt;
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans;
	} 
	return 0;
}