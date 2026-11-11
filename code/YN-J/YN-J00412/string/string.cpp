#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a;
	cin >> a;
	string f;
	for (long long i = 1; i <= a; i++) {
		long long s;
		char d;
		cin >> s >> d;
		for (long long j = 1; j <= s; j++) {
			f += d;
		}

	}
	string q;
	for (long long i = f.size() - 1; i >= 0; i--) {
		q += f[i];
	}
	if (q == f) {
		cout << 0;
		return 0;
	}
	string e, r;
	if (f.size() % 2 == 0) {
		for (long long i = 0; i < f.size() / 2; i++) {
			e += f[i];
		}
		for (long long i = f.size() / 2; i < f.size(); i++) {
			r += f[i];
		}
		int t = 0;
		for (long long i = 0; i < f.size() / 2; i++) {
			if (e[i] != r[i]) {
				t++;
			}
		}
		cout << t;
	} else {
		for (long long i = 0; i <= f.size() / 2; i++) {
			e += f[i];
		}
		for (long long i = f.size() / 2; i < f.size(); i++) {
			r += f[i];
		}
		int t = 0;
		for (long long i = 0; i < f.size() / 2; i++) {
			if (e[i] != r[i]) {
				t++;
			}
		}
		cout << t;
	}
	return 0;
}