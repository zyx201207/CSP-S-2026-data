#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a, b, bo = 0, sum1 = 0;

	cin >> a >> b;
	int n[a];
	string m[a];
	for (int i = 0; i < a; i++) {
		cin >> n[i];
	}
	sort(n, n + a, cmp);
	if (b == 2) {
		for (int i = 0; i < a; i++) {
			if (n[i] == 15 || n[i] == 31 || n[i] == 63 || n[i] == 127 || n[i] == 255 || n[i] == 511 || n[i] == 1023 || n[i] == 2047
			        || n[i] == 4095 || n[i] == 8191  ) {
				cout << n[i + 1];
				return 0;
			}
		}
	}
	return 0;
}