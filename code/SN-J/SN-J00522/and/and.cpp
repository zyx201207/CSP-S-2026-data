#include <bits/stdc++.h>
#define N 200005 
/*
这这这这这这这这
* * * * * * * *
* * * * * * * *
是是是是是是是是 
啥啥啥啥啥啥啥啥 
, , , , , , , ,
看看看看看看看看 
来来来来来来来来 
只只只只只只只只 
能能能能能能能能 
骗骗骗骗骗骗骗骗 
分分分分分分分分
了了了了了了了了
! ! ! ! ! ! ! !

ToT ToT ToT ToT
*/
using namespace std;
namespace eggy {
	int n, m, a[N], sum = 0;
	void work() {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		if (m == n) {
		
			for (int i = 1; i < n; i++) {
				if (i == 1) 
					sum = a[i];
				sum &= a[i + 1];
			} 
			cout << sum;
			return;
		}
		if (a[1] == 1) {
			bool ok = 0;
			for (int i = 1; i <= n; i++)
				if (!(a[i] % 2)) ok = 1;
			if (ok) cout << 0;
			else cout << 1;
			return;
		}
		if (m == 1) {cout << a[n]; return;} // 最大的那个
		int b[m + 2];
		for (int i = 1; i <= m; i++) b[i] = a[n - i];
		for (int i = 1; i < m; i++) {
			if (i == 1) 
				sum = b[i];
			
			sum &= b[i + 1];
		} 
		cout << sum;
		return;
	}
} 
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	return eggy::work(), 0;
}
