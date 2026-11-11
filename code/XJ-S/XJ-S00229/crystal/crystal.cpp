#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5E5 + 10;
int n, m, md;
int a[N];
int pre[N];
int cmp(int x,int y) {
	return x < y;
}
int check(int k) {
	if (k > n) {
		return 0;
	}
	if (k <= 1){
		return 1;
	}
	for(int i = 1; i <= n - k + 1; i++) {
		if(((k - 1) * 1LL * a[i + k - 1]  - (pre[i + k - 2] - pre [i - 1])) <= m ) {
//			cout << "YES:k" << k << " ";
//			cout << "i:" << i << " " <<(k - 1) * a[i + k - 1] << " " << pre[i + k - 2] - pre [i - 1] << " " << ((k-1) * 1LL * a[i + k - 1]  - (pre[i + k - 2] - pre [i - 1])) << endl;
			return 1;
		}
	}
//	cout << "NO" << endl;
	return 0;
}
//考虑二分答案，二分最多能满足条件的水晶数量
//用K个合成大水晶，检验消耗的次数是否小于 m
//选择一个区间长度为K的区间，能否使得其中每一个到最大值的差之和小于等于m
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int dta = INT_MAX;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dta = min(a[i] , dta);
	}
	if(dta < 0){
		for(int i = 1;i <= n; i++){
			a[i] += abs(dta);
		}
	}//修正负数，全搞成正的 
//	for(int i = 1;i <= n ; i++){
//		cout << a[i] << " ";
//	}
//	cout << endl;
	sort(a + 1, a + n + 1);
	for(int i = 1 ; i < n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
//	for(int i = 1;i <= n ; i++){
//		cout << pre[i] << " ";
//	}
//	cout << endl;
	int l = 0, r = N;
	while(l <= r) {
		int mid = (l + r) >> 1;
//		cout << l << " " << mid << " " << r <<endl;
		if(check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << r ;
	return 0;
}
