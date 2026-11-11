#include <bits/stdc++.h>
using namespace std;
long long d[1000000];
string f[1000000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long a;
	cin >> a;
	long long s;
	cin >> s;
	for (long long i = 1; i <= a; i++) {
		cin >> d[i];
		string r;
		while (d[i]) {
			r += d[i] % 2;
			d[i] /= 2;
		}

		for (int j = r.size() - 1; j >= 0; j++) {
			f[i] += r[j];
		}
	}
	sort(d + 1, d + 1 + a);
	cout << d[1];
	return 0;
}