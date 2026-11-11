#include <iostream>
using namespace std;

long long a[100010], L, cnt;
string c;
int n;
string b;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "r", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c;
		L += a[i];

		for (int j = 1; j <= a[i]; j++) {

			b += c;
		}
	}


	

	if (!L & 1)
		for (long long i = 0; i < (L - 1) / 2; i++) {

			if (b[i] != b[L - 2 + i]) {

				cnt++;
			}
		} else
		for (long long i = 0; i <= (L - 1) / 2; i++) {

			if (b[i] != b[L - 2 + i]) {
				cnt++;
			}
		}

	cout << cnt;
	return 0;
}
