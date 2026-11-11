#include <bits/stdc++.h>
#include <stack>
using namespace std;
const int maxn = 1e6 + 10;
long long n, m;
long long  z[maxn], biao[maxn], k[maxn], t[maxn];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >>  m;
	for (int i = 1; i <= n; i++) {
		cin >> z[i];
	}
	for (int i = 1; i <= n; i++) {
		stack <long long> dp;
		long l = 1;
		long long r = n;
		for (int j = l; j <= r; j++) {
			if (biao[z[j]] == 0) {
				dp.push(z[j]);
				biao[z[j]] = 1;
			} else {
				for (int i = 1; i <= n; i++) {
					if (dp.top() == z[j]) {
						break;
					} else {
						dp.pop();
					}
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (dp.empty()) {
				break;
			} else {
				t[dp.top()]++;
				dp.pop();
			}
		}
		l++, r++;
	}
	for (int i = 1; i <= n; i++) {
		if (k[z[i]] == 0) {
			k[z[i]] == 1;
			printf("%lld ", t[z[i]]);
		}
	}
	return 0;
}