#include <iostream>
using namespace std;
int a, b;
long long ma, d[200005], k;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> a >> b;
	for (int c = 0; c < a; c++) {
		cin >> d[c];
		ma = max(ma, d[c]);
	}
	if (a == b) {
		k = d[0];
		for (int e = 0; e < a; e++) {
			k = k & d[e];
		}
		cout << k;
	} else if (b == 1) {
		cout << ma;
	} else if (b == 2) {
		long long mm = 0;
		for (int g = 0; g < a; g++) {
			if (d[g] == ma) {
				continue;
			}
			mm = max(mm, d[g]);
		}
		int y = ma && mm;
		cout << y;
	}
	return 0;
}