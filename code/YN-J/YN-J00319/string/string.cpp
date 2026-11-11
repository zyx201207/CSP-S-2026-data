#include <bits/stdc++.h>
using namespace std;
string a = "";
string s = "";

long long n, num, i, j;
long long cnt = 0;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num >> s;
		for (j = 0; j < num; j++) {
			a = a + s;
		}
	}
	long long l = a.size();
	if (l % 2 == 1) {

		for (i = 0; i < l / 2; i++) {
			if (a[i] != a[l - i - 1]) {
				cnt++;
			}
		}
	} else {
		for (i = 0; i < l / 2; i++) {
			if (a[i] != a[l - i]) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}