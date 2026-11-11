#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N], c[N], s[N], sum[N]; //c表示i位置和前一个数的差,s表示第i个数到最后一个数的差,sum表示s的前缀和
int ans[N];
inline bool check(int mid, int r) {
	int t1 = sum[r] - s[r] * r; //1-r到r的差和
	int t2 = sum[mid] - s[mid] * mid; //1-mid到mid的差和
	int t3 = (s[1] - s[r]) - (s[1] - s[mid]); //mid-r的差
//	cout << t1 << ' ' << t2 << ' ' << t3 << '\n';
	int res = t1 - t2 - t3 * (mid - 1);
	if(res <= m) return 1;
	return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) c[i] = a[i] - a[i - 1];
	for(int i = n - 1; i >= 1; i--) s[i] = s[i + 1] + c[i + 1];
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i];
//	for(int i = 1; i <= n; i++) cout << c[i] << ' ';
//	cout << '\n';
//	for(int i = n - 1; i >= 1; i--) cout << s[i] << ' ';
//	cout << '\n';
//	for(int i = 1; i <= n; i++) cout << sum[i] << ' ';
//	cout << '\n';
	for(int i = n; i >= 1; i--) {
//		cout << i << '\n';
		int l = 1, r = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(mid, i)) {
//				cout << "T " << mid << '\n';
				ans[i] = max(ans[i], i - mid + 1);
				r = mid - 1;
			}
			else {
//				cout << "F " << mid << '\n';
				l = mid + 1;
			}
		}
//		cout << '\n';
	}
	int res = LLONG_MIN;
	for(int i = 1; i <= n; i++) res = max(res, ans[i]);
	cout << res;
	return 0;
}
/*
sort后
数字之间的差单调不减
考虑二分
从最大往前选
二分一个数
求差之和
小于则往左选
大于则往右选
记录ans[i]
最后取max
时间复杂度O(nlogn+3n)
难点：
怎么快速求差之和
考虑前缀和优化
*/
/*
当前问题：
hack：
5 2
1 2 3 4 5
*/