#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;

	int z = n + 1;
	vector<long long> a2(z);
	char a[z];
	string s;
	if (n == 1) {
		for (int i = 1; i <= n; i++) {
			cin >> a2[i] >> a[i];
		}
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a2[i] >> a[i];
		for (int j = 1; j <= a2[i]; j++) {
			s += a[i];
		}
	}
	char c = s[0];
	int k = 1;
	for (int i = 1; i <= s.size(); i++) {
		if (s[i] == c) {
			k++;
		}
	}
	if (k == s.size()) {
		cout << 0;
		return 0;
	}
	if (k < (s.size() / 2 + 1)) {
		cout << k;
	} else {
		int u = s.size() + 1;
		c = s[u];
		k = 1;
		for (int i = 1; i <= s.size(); i++) {
			if (s[i] == c) {
				k++;
			}
		}
		cout << k;
	}

	return 0;
}