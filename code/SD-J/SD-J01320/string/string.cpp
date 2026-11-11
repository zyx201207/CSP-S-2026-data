#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int SIZE = 2e5 + 5, T = 816;
int n, a[SIZE], ans;
char c[SIZE];
void _main() {
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while (l < r){
		int minn = min(a[l], a[r]);
		if (c[l] != c[r])ans += minn;
		a[l] -= minn, a[r] -= minn;
		if (a[l] == 0)l++;
		if (a[r] == 0)r--;
	}
	cout << ans;
	return;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	while (t --> (T^T)){
		_main();
	}
	return 0; 
}
