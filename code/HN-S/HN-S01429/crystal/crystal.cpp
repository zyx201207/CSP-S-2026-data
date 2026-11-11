#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fileIO("crystal");
	
	int n;
	i64 m, sum = 0;
	cin >> n >> m;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 1;
	for(int i = 0, j = 0; i < n; i ++) {
		sum += a[i];
		while((i - j + 1ll) * a[i] - sum > m) {
			sum -= a[j];
			j ++;
		}
		ans = max(ans, i - j + 1); 
	}
	cout << ans << "\n";
}
