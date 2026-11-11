#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 1000;
int a[N], sum[N];
stack<int> s;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool f = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) f = false;
	}
	if (f) {
		for (int i = 1; i <= n; i++) {
			s.clear();
			for (int j = i; j <= n; j++) {
				if (s.empty() || s.top() != a[i]) {
					s.push(a[i]);
					sum[a[i]]++;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << sum[i] << ' ';
		}
		return 0;
	}
	return 0;
}