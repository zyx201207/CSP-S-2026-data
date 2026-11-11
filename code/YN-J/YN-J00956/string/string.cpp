#include <bits/stdc++.h>
using namespace std;
long long a[100000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, s = 0, ans = 0;
	cin >> n;
	while (n--) {
		int m;
		string str;
		cin >> m >> str;
		for (int i = 0; i <= str.size(); i++) {
			for (int j = 0; j <= str.size(); j++) {
				if (a[i] == a[j]) {
					s = 1;
				}
			}
		}
	}
	if (s == 1) {
		cout << 0;
	} else {
		for (int i = 1; i <= ni++) {

		}
	}
	return 0;
}