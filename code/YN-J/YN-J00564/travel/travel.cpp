#include <iostream>
using namespace std;

int main() {
	freeopen("travel","r",stdin);
	freeopen("travel","w",stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
		if (b[0] + b[1] == d[0] + d[1]) {
			cout << 1;
			if ((b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') || (b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D'
			        && d[2] <= 'F')) {
				cout << 1 << 1;
			} else {
				cout << 0 << 0;

			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
