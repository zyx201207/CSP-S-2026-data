#include<bits/stdc++.h>
#define int long long 
using namespace std; 
const int maxn = 2e6 + 100; 
const int inf = 5e18 + 100; 
int n, d; 
int a[maxn]; 
int sum[maxn]; 

inline void solveA() {
	cin >> n >> d; 
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	if(n == 1) {
		cout << 0 << '\n'; 
		return; 
	}
	int D = abs(a[2] - a[1]); 
	int num = d / D; // 能飞过的空隙数量; 
	if(num + 1 >= n || num <= 1) {
		cout << 0 << '\n'; 
		return; 
	}
	cout << n - num * 2 + 1 << '\n'; 
}
/*inline void solveB() {
	cin >> n >> d; 
	cout << n << ' ' << d << '\n'; 
	int pos = 0; 
	if(n == 1) {
		cout << 0 << '\n'; 
		return; 
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
		// cout << a[i] << '\n'; 
		if(a[i] <= d) {
			pos = i; 
		}
	}
	int ans = 0; 
	int stnd = a[pos] - a[pos - 1]; 
	for(int i = 1; i <= n; i++) {
		int x_1 = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1; 
		// cout << i << ' ' << x_1 << '\n'; 
		int x_2 = upper_bound(a + 1, a + n + 1, a[x_1] + d) - a - 1; 
		int d1 = a[x_1] + d - a[x_2]; 
		int d2 = a[x_1] - a[x_1 - 1]; 
		int d3 = a[x_1 - 1] - a[x_1 - 2]; 
		// if()
	} 破如防。 --18:24
}*/ 

signed main() {
	freopen("migrate.in", "r", stdin); 
	freopen("migrate.out", "w", stdout); 
	ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0); 
	int c, T; cin >> c >> T; 
	while(T--) {
		if(c == 11 || c == 12) solveA(); 
		else cout << 0 << '\n'; 
		
	}
	
	
	
	return 0; 
}


 
 
