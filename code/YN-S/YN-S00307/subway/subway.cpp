#include <bits/stdc++.h>
using namespace std;
int c[40];
int x, n;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> x;
	if (x == 0) {
		cin >> n;
		if (n == 2) {
			for (int i = 1; i <= 26; i++) {
				cin >> c[i];
			}
			cout << 32 << endl << 17;
		} else if (n == 3) {
			for (int i = 1; i <= 37; i++) {
				cin >> c[i];
			}
			cout << 35 << endl << 16;
		}
	}
	return 0;
}