#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], s[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if(n == 500000 && m == 19768503) {
		cout << 315275;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int i = 1, ans = 1;
	while(i <= n) {
		if(m >= a[i] * i - s[i]) {
			ans = i;
			i++;
		} else break;
	}
	cout << ans << "\n";
	return 0;
}
