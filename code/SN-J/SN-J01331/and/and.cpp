#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], mask;
int main() {
	freopen("and.in", "r", stdin); freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if ((mask & a[j]) == mask) {
				if ((1 << i) & a[j]) cnt++;
			} 
		}
		if (cnt >= m) mask |= (1 << i);
	}
	cout << mask;
	
	return 0;
}
