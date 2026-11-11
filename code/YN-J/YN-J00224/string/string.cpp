#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, num = 0;
	char a[N];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long s;
		char x;
		cin >> s;
		cin >> x;
		for (int j = num; j <= num + s; j++) {
			a[j] = x;
		}
		num += s;
	}
	int ans = 0;
	if (num % 2 == 1) {
		num--;
		for (int i = 1; i <= num / 2; i++) {
			if (a[num / 2 - i + 1] != a[num / 2 + i + 1]) {
				ans++;
			}
		}
	} else {
		for (int i = 1; i <= num / 2; i++) {
			if (a[num / 2 - i] != a[num / 2 + i]) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}