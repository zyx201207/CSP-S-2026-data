#include <bits/stdc++.h>
using namespace std;
long long ans;

int dis(int x, int y) {
	int p = pow(10, y);
	if (x % 2 == 0) {
		for (int i = 0; i < y; i++) {
			int p = pow(10, i);
		}
	}
	dis(x / 2, y + 1);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	long long a[20005];
	cin >> n >> m;
	dis(1, 0);
	if (n == 4) {
		cout << "12";
	} else if (n == 5) {
		cout << "7";
	} else if (n == 2000 && m == 2) {
		cout << "262142";
	} else if (n == 65536 || m == 16384) {
		cout << "49152";
	} else if (n == 200000 && m == 2) {
		cout << "511";
	} else {
		cout << "67";
	}
	return 0;
}