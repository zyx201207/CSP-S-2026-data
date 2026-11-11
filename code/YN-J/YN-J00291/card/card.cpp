#include <bits/stdc++.h>
using namespace std;

int ty[300005] = {0};
int c[300005];

bool f[300005] = {0};
int n, m, a, x;
stack<int> s;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> c[i];

		if (f[c[i]] == 1) {
			while (s.top() != c[i]) {
				x = s.top();
				f[x] = 0;
				s.pop();
			}
		} else {
			s.push(c[i]);
			f[c[i]] = 1;
		}
	}

	for (int i = 1; i <= m; i++) {

		if (f[i] == 1) {
			ty[i]++;
			s.pop();
			f[i] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {

		for (int j = i; j <= n; j++) {

			if (f[c[j]] == 1) {
				while (s.top() != c[j]) {
					x = s.top();
					f[x] = 0;
					s.pop();
				}
			} else {
				f[c[j]] = 1;
				s.push(c[j]);
			}
		}

		for (int j = 1; j <= m; j++) {

			if (f[j] == 1) {
				ty[j]++;
				s.pop();
				f[j] = 0;
			}
		}
	}

	for (int i = 1; i <= m; i++)

		cout << ty[i] << " ";
	return 0;
}
