#include <bits/stdc++.h>
using namespace std;
int n, m, a[200000], ans;
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort (a, a+n);
	ans = a[n-1];
//	cout << ans << ' ';
	for (int i = n-2; i >= n-m; i--) { 
	    ans &= a[i];
//	    cout << a[i] << ' ';
    }
	cout << ans;
	return 0;
}
/*
非正解思路：
1暴力 × 
2贪心 (有反例）
正解：
二分答案？ 
*/
