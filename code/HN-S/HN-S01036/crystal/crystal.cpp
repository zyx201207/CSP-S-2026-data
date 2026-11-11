#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], d[N];
bool check(int mid) {
	int c = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > mid) continue;
		c += mid - a[i]; 
	}
	return c <= m;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int l = -1000000000000, r = 1000000000000;
	while(l < r - 1) {
		int mid = l + r >> 1; 
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	int c = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > l) continue;
		c++;
	}
	cout << c;
	return 0;
} 
