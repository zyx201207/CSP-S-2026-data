#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], to[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		to[a[i]]++;
	}
	bool flag = true;
	for (int i = 1; i <= m; i++) {
		if (to[i] >= 2) {
			flag = false;
		}
	}
	if (flag == true) {
		for (int i = 1; i <= n; i++) {
			cout << n - i + 1 << ' ';
		}
	} else {
		stack<int> s, st;
		vector<int> b(m + 3, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				int x = a[j];
				bool f = true;
				while (!s.empty()) {
					int t = s.top();
					s.pop();
					st.push(t);
					if (t == x) {
						s.push(t);
						f = false;
						break;
					}
				}
				if (f) {
					b[s.top()]++;
					s.pop();
				} else {
					while (!st.empty()) {
						s.push(st.top());
						st.pop();
					}
					s.push(x);
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << b[i] << ' ';
		}
	}
	return 0;
} 
