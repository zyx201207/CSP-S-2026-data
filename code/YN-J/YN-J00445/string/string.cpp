#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 2;
int x[MAXN];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
//	if (n == 1) {
//		int a;
//		string c;
//		cin >> a >> c;
//		cout << 0;
//	}
//	if (n == 2) {
//		int x[2002];
//		string s, s2;
//		for (int i = 1; i <= n; i++) {
//			cin >> x[i] >> s2;
//			if (s == s2) {
//				x[i] += x[i - 1];
//				x[i - 1] = 0;
//			}
//			s = s2;
//		}
//		if (s.size() == 1) {
//			cout << 0;
//		} else {
//			cout << x[1];
//		}
//	} else {
	string s, s2;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> s2;
		if (s == s2) {
			x[i] += x[i - 1];
			x[i - 1] = 0;
		}
		s = s2;
	}
	sort(x + 1, x + n + 1);
	cout << x[n - 1];
//	}
	return 0;
}