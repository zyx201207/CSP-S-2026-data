#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
string x;
long long n;
long long m;
long long sum;

bool ai(string x, int c) {
	for (int i = 0; i <= x.size(); i++) {
		if (x[i] - '0' == c) {
			b[c]++;
		}
	}
	return 0;
}

int main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);


	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			string v = to_string(a[i]);

			if (x.find(v) > n) {
				x += v;
				x += ',';
			} else {
				int s = x.find(v);
				for (int i = s; i <= x.size(); i++) {
					x[i] == '0';

				}
			}
		}
		for (int i = 1; i <= m; i++) {
			ai(x, i);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (b[i] != 0) {
			cout << b[i] << " ";
		}

	}

	return 0;
}