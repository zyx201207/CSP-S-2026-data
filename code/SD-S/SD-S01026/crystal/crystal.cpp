//time 15:21 切完第一道 
//zhe shi shen me 78 ti mu
//time 17:26 我好像炸了
//wo xiang wan pgr 
//什么题目，我暴力都不会写 
//time 18:03 我还有救吗 
//time 18:19 这么煎熬吗 
//time 18:27 考试结束了??? 
//考后感：我是区 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5E5 + 10;
int a[N], pre[N], n, m;
int getsum(int k) {
	int l = 1, r = k, ans = 0;
	while(l <= r) {
		int mid = l + r >> 1;
		int sum = (k - mid + 1) * a[k] - (pre[k] - pre[mid-1]);
//		cout << sum << " "; 
		if(sum > m) {
			l = mid + 1;
		} else {
			r = mid - 1;
			ans = mid;
		}
	}
//	cout << "ans" << ans << "\n";
	return k - ans + 1;
}   
//t1 100pts O(n log n)
//t2 滚木pts O(滚木)
//t3 滚木pts O(滚木)
//t4 滚木pts O(1)
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + a[i];
//		cout << pre[i] << " "; 
	}
	int res = 0;
	for(int i = 1; i <= n; i++) {
//		cout << getsum(i) << " ";
		res = max(res, getsum(i));
	}
	cout << res << "\n";
	return 0;
}
//这场比赛给了
//压一手黄 青 蓝 紫 
