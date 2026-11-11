#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	long long n, m;
	cin >> n >> m;
	int a[n + 5];
	string s, l;

	for (int i = 0; i < n; i ++) {

		cin >> a[i];
	}

	int num = 0;

	for (int i = 0; i < n; i ++) {

		for () {

			s[j] = a[i] % 2;
			a[i] / 2;
		}

		l[i] = s.size;

		for (int j = 0; j < n; j += l) {

			num += s[i] & m{i + 1};
		}

	}


	cout << num;

	return 0;
}
