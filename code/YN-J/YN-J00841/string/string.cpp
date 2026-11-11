#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 50;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long cnt = 0;
	cin >> n;
	string s = "";

	for (int i = 1; i <= n; i++) {

		long long a;
		char c;
		cin >> a >> c;

		for (long long i = 1; i <= a; i++) {

			s += c;
		}
	}

	long long size = s.size();

	if (size % 2 == 0) {
		for (long long i = 1; i <= size; i++) {

			if (i - 1 > size - i) {
				break;
			}

			if (s[i - 1] != s[size - i]) {
				cnt++;
			}
		}
	} else {
		for (long long i = 1; i <= size; i++) {

			if (i - 1 == size  - i) {
				break;
			}

			if (s[i - 1] != s[size  - i]) {
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	return 0;
}