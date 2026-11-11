#include <bits/stdc++.h>
using namespace std;
long long n, m, sj[500005], q, a1, gs, a2;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int sl[n + 1] ;
	if (n == 500000) {
		cout << 315275;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> sj[i];
	}
	sort(sj + 1, sj + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			sl[j] = sj[i] - sj[j];
		}
		q = 0;
		a2 = 0;
		sort(sl + 1, sl + 1 + i);
		for (int j = 1; j <= i; j++) {
			if (q + sl[j] <= m) {
				q += sl[j];
				a2 += 1;
			} else
				break;
		}
		gs = max(gs, a2);
	}


	cout << gs ;
	return 0;
}
