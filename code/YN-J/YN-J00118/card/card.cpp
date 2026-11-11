#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
bool x[500010];
int t[500010];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	queue<int>qwq;
	for (int i = 1; i <= n; i++) {
		memset(x, 0, sizeof(x));
		for (int j = i; j <= n; j++) {
			int k = a[j];
			if (x[k] == 0) {
				x[k] = 1;
				qwq.push(k);
//				cout << k << ' ';
			} else {
//				cout << (qwq.front() == k) << '\n';
				queue<int>u;
				while (!qwq.empty()) {
					u.push(qwq.front());
					qwq.pop();
				}
				while (!u.empty() && u.front() != k) {
					x[u.front()] = 0;
//					cout << qwq.front() << ' ';
					u.pop();
				}
				if (!u.empty() && u.front() == k) {
					x[u.front()] = 0;
//					cout << qwq.front() << '\n';
					u.pop();
				}
				while (!u.empty()) {
					qwq.push(u.front());
					u.pop();
				}
				x[k] = 1;
				qwq.push(k);
			}
		}
//		cout << '\n';
		while (!qwq.empty()) {
			t[qwq.front()]++;
			qwq.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << t[i] << ' ';
	}
	return 0;
}