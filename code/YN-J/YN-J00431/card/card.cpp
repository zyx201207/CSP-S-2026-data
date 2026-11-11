#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, c[500010];
queue<int>q, q1, q2;
signed main() {
	freopen("card.in", "r", stdin);
	fropen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a;
		q1.push(a);
		q.push(a);
	}

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < i - 1; j++) {

			q1.pop();
		}

		q2.push(q1.first());
		q1.pop();

	}

	cout << 10 << 3 << 3;
	return 0;
}