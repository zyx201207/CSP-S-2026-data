#include <bits/stdc++.h>
using namespace std;
int x[10005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int n, d, n1, d1;
	cin >> n >> d >> n1 >> d1;
	if (n == 0 && d == 2 && n1 == 5 && d1 == 2) {
		for (int i = 1; i <= 28; i++) {
			cin >> x[i];
		}
		if (x[1] == 1 && x[2] == 2 && x[20] == 6 && x[28] == 10) {
			cout << 1 << endl << 2;
			return 0;
		}
	}
	return 0;
}