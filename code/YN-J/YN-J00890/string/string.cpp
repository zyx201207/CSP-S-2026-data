#include <iostream>
using namespace std;

struct aaa {
	long long x;
	char y;
};
int a;
aaa b[200005];
long long sum;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> a;
	for (int c = 0; c < a; c++) {
		cin >> b[c].x;
		cin >> b[c].y;
	}
	for (int d = 0, e = a - 1; d < a && e >= 0;) {
		if (d >= e) {
			break;
		}
		int l = min(b[d].x, b[e].x);
		if (b[d].y != b[e].y) {
			sum += l;
		}
		b[d].x -= l;
		b[e].x -= l;
		if (b[e].x <= 0) {
			e--;
		}
		if (b[d].x <= 0) {
			d++;
		}
	}
	cout << sum;
	return 0;
}