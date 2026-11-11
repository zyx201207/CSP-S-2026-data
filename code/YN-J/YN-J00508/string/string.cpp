#include <bits/stdc++.h>
using namespace std;
long long l;
const long long N = 2e5 + 10;
string c[N];
string h;
long long a[N];
long long hh;
long long j = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> l;
	for (long long i = 1; i <= l; i++) {
		cin >> a[i] >> c[i];
		for (long long j = 1; j <= a[i]; j++) {
			h += c[i];
		}
		hh += a[i];
	}
	long long l = 0, r = hh - 1;
	while (l <= r) {
		if (h[l] != h[r]) {
			j++;
		}
		l++;
		r--;
	}
	cout << j << endl;


	return 0;
}
