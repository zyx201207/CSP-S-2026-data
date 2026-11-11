#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
char b[200001];
string s;
string s1;
int xg;

void planbl() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s += b[i];
		}
	}
	int l1 = s.size();
	for (int i = l1 - 1; i >= 0; i--) {
		s1 += s[i];
	}
	cout << s << "\n" << s1 << "\n";
	for (int i = 0; i <= n / 2; i++) {
		if (s[i] != s1[i]) {
			++xg;
		}
	}
	cout << xg;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i + 1] >> b[i + 1];
	}
	if (n == 1) {
		cout << 0;
	} else if (n == 2) {
		cout << min(a[1], a[2]);
	} else {
		planbl();
	}
	return 0;
}
