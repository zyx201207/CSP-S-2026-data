#include <bits/stdc++.h>
using namespace std;

struct data {
	int aa, bb;

};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c[100000], jss[10000];
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> c[i];

	}
	for (int i = 1; i <= a; i++) {
		long long js[10000] = {0};
		for (int j = i; j <= a; j++) {
			js[c[j]] = 1;

		}
		for (int j = 1; j <= b; j++) {
			if (js[j]) {
				jss[j]++;
			}

		}
	}
	for (int i = 1; i <= b; i++ ) {
		cout << jss[i] << ' ';
	}
	return 0;
}

