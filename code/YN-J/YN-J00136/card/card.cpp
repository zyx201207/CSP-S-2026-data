#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N], b[M];
bool g[M];
stack<int>s;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		memset(g, 0, sizeof(g));

		for (int j = i; j <= n; j++) {

			if (g[a[j]]) {
				while (s.top() != a[j]) {
					g[s.top()] = 0;
					s.pop();
				}

				s.pop();
			}

			s.push(a[j]);
			g[a[j]] = 1;
		}

		while (!s.empty()) {
			b[s.top()]++;
			s.pop();
		}


	}

	for (int i = 1; i <= m; i++) {

		cout << b[i] << ' ';
	}

	return 0;
}