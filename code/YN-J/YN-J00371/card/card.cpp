#include <bits/stdc++.h>
using namespace std;
int m, n;
int card[500005];
int appair[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> card[i];
	}
	for (int i = 0; i < m; i++) {
		stack<int>s;
		bool vis[500005] = {};
		for (int j = i; j < m; j++) {
			if (vis[card[j]]) {
				while (s.top() != card[j]) {
					vis[s.top()] = 0;
					s.pop();
				}
			} else {
				s.push(card[j]);
				vis[card[j]] = 1;
			}
		}
		while (!(s.empty())) {
			appair[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << appair[i] << " ";
	}
	return 0;
}