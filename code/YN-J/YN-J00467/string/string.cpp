#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a[200001];
	char s[200001];
	int n;
	cin >> n;
	long long sum;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> s[i];
		sum = sum + a[i];
	}
	string h;
	long long z = sum / 2;
	long long count = 0;
	long long q = 0;
	bool x = true;
	char v = s[0];
	for (int i = 0; i < n; i++) {
		if (s[i] != v) {
			x = false;
			break;
		}
	}
	if (x == true) {
		cout << 0;
		return 0;
	}
	for (long long i = 0; i < n; i++) {
		long long e = a[i] - q;
		long long e1 = a[n - i] - q;
		if (i == n - i || count == z) {
			break;
		}
		if (e == e1) {
			if (s[n - i] != s[i]) {
				s[n - i] = s[i];
				count += e;
			}
		} else {
			if (e > e1) {
				s[n - i] = s[i];
				q = e - e1;
				count += e;
			} else {
				s[i] = s[n - 1];
				q = e1 - e;
				count += e1;
			}
		}
	}
	cout << count;
	return 0;
}