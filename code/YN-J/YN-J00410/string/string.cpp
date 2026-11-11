#include <bits/stdc++.h>
using namespace std;

long long a[100000005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, cnt = 0, aa = 0;
	cin >> n;


	for (int i = 0; i < n; i++) {

		string s;
		cin >> a[i] >> s;

		for (int j = n - 1; j >= 0; j++) {

			if (a[j] == a[i] && s[j] == s[i]) {
				aa++;
			} else {
				a[j] = a[i];
				s[j] = s[i];
				cnt += a[i];
			}
		}
	}

	if (aa == n) {
		cout << 0;
	} else {
		cout << cnt;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}