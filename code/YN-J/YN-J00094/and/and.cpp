#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long x, ans;
priority_queue<long long> pq;

bool ck(long long x) {
	while (x != 1) {
		if (x % 2 == 1)
			return 0;
		x /= 2;
	}

	return 1;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int tot = 0;

	for (int i = 1; i <= n; i++) {

		cin >> x;
		pq.push(x);
		tot++;
	}

	if (m == 1) {
		cout << pq.top();
		return 0;
	}

	while (ck(pq.top()) && tot > m) {
		pq.pop();
		tot--;
	}

	ans = pq.top();

	for (int i = 1; i <= m; i++) {

		ans &= pq.top();
		pq.pop();
	}

	cout << ans;
	return 0;
}
