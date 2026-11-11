#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen('andin', 'r', 'stdin');
	freopen('andout', 'w', 'stdout');
	int n;
	cin >> n ;

	for (int i; i = n; i++) {

		int a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;

		for (int j; j = a; j++) {

			cout << 2 * a << endl;
		}

		for (int q; q = b; q++) {

			cout << 2 * b << endl;
		}

		for (int q; q = c; q++) {

			cout << 2 * c << endl;
		}

		cout << "aabbc" << endl;

		if (a = 2, b = 2 ) {
			cout << 0 << endl;
		}

	}



	fclose(stdin)fclose(stdout);
	return 0;
}
