#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
//#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define F(i, n, m) for(int i = n; i <= m; i++)
#define dF(i, n, m) for(int i = n; i >= m; i--)
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> x(n+1), f(n+1);
	F(i, 1, n) {
		cin >> x[i];
	}int ans = 0;
	F(i, 1, n-3) {
		if((x[3+i] - x[1+i] <= d) && (x[2+i] - x[i] <= d) && (x[3+i] - x[i] > d)){
			f[i] = f[i+1] = f[i+2] = f[i+3] = f[i-1] + 1;
			ans = max(ans, f[i]);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("migrate3.in", "r", stdin);
	
	int qwe, T;
	cin >> qwe >> T;
	while(T--) {
		solve();
	}
	
	return 0;
}