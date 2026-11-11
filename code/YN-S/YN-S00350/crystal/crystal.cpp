//wr 2026.10.31
#include <bits/stdc++.h>
using namespace std;
//const int N = 2e5 + 5;
long long n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	vector<long long> a(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long mc = 1;
	for (int i = 1; i <= n; i++) {
		long long cot = 0;
		long long cnt = 1;
		for (int j = i - 1; j >= 0; j--) {
			cot += (a[i] - a[j]);
			if (cot <= m) {
				cnt++;
			} else {
				break;
			}
		}
		mc = max(mc, cnt);
	}
	cout << mc;
	return 0;
}