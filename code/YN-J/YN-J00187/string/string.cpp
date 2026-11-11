#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, s = 0;

struct SCP {
	ll z;
	char m;
} sc[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int j = 1; j <= n; j++) {

		int x;
		char y;
		cin >> x >> y;
		sc[j].z = x, sc[j].m = y;
	}

	for (int i = 1; i <= n / 2; i++) {

		if (sc[i].m != sc[n + 1 - i].m && sc[i].z != sc[n + 1 - i].z) {
			s += sc[i].z;
			sc[n - i].z -= abs(sc[i].z - sc[n - 1 + i].z);
		} else if (sc[i].m != sc[n + 1 - i].m && sc[i].z == sc[n + 1 - i].z) {
			s += sc[n + 1 - i].z;
		} else if (sc[i].m == sc[n + 1 - i].m && sc[i].z != sc[n + 1 - i].z) {
			if (i + 1 == n + 1 - i) {
				continue;
			} else {
				s += abs(sc[i].z - sc[n + 1 - i].z);
			}

			if (i + 1 == n - i) {
				sc[i + 1].z += abs(sc[i].z - sc[n + 1 - i].z);
			} else {
				sc[i + 1].z += abs(sc[i].z - sc[n + 1 - i].z), sc[n - i].z += abs(sc[i].z - sc[n + 1 - i].z);
			}
		} else {
			continue;
		}
	}

	cout << s;
	return 0;
}