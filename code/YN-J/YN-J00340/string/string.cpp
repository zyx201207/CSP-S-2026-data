#include <bits/stdc++.h>
using namespace std;
string a;
long long sum;
long long m[1000005];

int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		char y;
		cin >> m[i] >> y;

		a += y;
		//for (int i = 0; i < x; i++) {
		//a += y;
		//}


	}
	//for (int i = 0; i < n; i++) {
	//cout << m[i] << " ";
	//}
	//for (int i = 0; i < a.size() / 2; i++) {
	//if (a[i] != a[n - i]) {
	//sum++;
	//}
	//}
	long long l = 0;
	long long r = n;
	while (l < n / 2 && r > n / 2) {
		if (a[l] == a[r - 1]) {
			if (max(m[l], m[r - 1]) == m[l]) {
				m[l] -= m[r - 1];

				r--;
			} else {
				m[r - 1] -= m[l];

				l++;
			}
		} else {
			if (max(m[l], m[r - 1]) == m[l]) {
				sum += m[r - 1];
				//cout << sum << " " << m[r - 1] << " " << 1 << " ";
				m[l] -= m[r - 1];
				r--;
			} else {
				sum += m[l];

				m[r - 1] -= m[l];
				l++;
			}
		}
	}
	cout << sum;
	return 0;
}