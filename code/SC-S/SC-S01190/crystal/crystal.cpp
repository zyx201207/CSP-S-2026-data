#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N], b[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, sum = 0, ans = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		b[i - 1] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		if(b[i] < m) {
			sum += b[i] * i;
			if(sum > m) {
				cout << ans;
				break;
			}
			ans++;
		}
	}
	return 0;
}