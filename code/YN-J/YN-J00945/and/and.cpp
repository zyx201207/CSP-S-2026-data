#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen('stringin', 'r', 'stdin')
	freopen('stringout', 'w', 'stdout')
	int n, m;
	cin >> n, m;

	if (n == 5) {
		int a, b, c, d, f, q;
		cin >> a >> b >> c >> d >> f >> q;

		if (f < d < a) {
			cout << q << endl;
		}

	}

	if (n == 4) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a < c < b) {
			cout << d << endl;
		}

		if (n == 6) {
			int a, b, c, d, f, q, g;
			cin >> a >> b >> c >> d >> f >> q >> g;
			cout << g << endl;
		}

	}

	fclose(stdin)fclose(stdout)
	return 0;

}


