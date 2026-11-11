#include <bits/stdc++.h>
using namespace std;

vector<int64_t> C;
int n, ans;
int64_t m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int64_t tmp;
		cin >> tmp;
		C.push_back(tmp);
	}
	
	sort(C.begin(), C.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int64_t _m = m;
		int offset = -1;
		int cur = 1;
		while (offset >= -i) {
			_m -= C[i] - C[i + offset];
			if (_m >= 0) cur++;
			else break;
			offset--;
		}
		int more = 0;
		while (C[i] == C[i + more + 1]) {
			more++;
		}
		ans = max(ans, cur + more);
		if (_m < i + more + 1 && cur == i + more + 1) break;
		i += more;
	}
	
	cout << ans << "\n";
	return 0;
}
