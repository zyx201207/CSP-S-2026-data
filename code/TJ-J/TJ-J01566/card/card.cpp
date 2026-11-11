#include <iostream>
#include <stack>
using namespace std;

bool dp[300005] = {0};

int out[300005] = {0};
stack<int> s;

void q() {
	while (!s.empty()) {
		out[s.top()] ++;
		s.pop();
	}
	for (int i = 0; i < 300005; i++) {
		dp[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (dp[a[j]]) {
				while (s.top() != a[j]) {
					dp[s.top()] = 0;
					s.pop();
				}
			} else {
				s.push(a[j]);
				dp[a[j]] = 1;
			}
		}
		q();
	}
	for (int i = 1; i <= m; i++) {
		cout << out[i];
	}
	return 0;
}