#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int a[200005];
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}

	bool xiangtong = true;
	for (int i = 1; i <= n - 1; i++) {
		if (xiangtong == false) {
			break;
		}

		if (c[i] != c[i + 1]) {
			xiangtong = false;
		}
	}
	if (xiangtong) {
		cout << 0;
		return 0;
	}

	long long ans = 0, sum;

	string s1 = " ";
	string s2 = " ";
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		for (int j = 1; j <= a[i]; j++) {
			s1 += c[i];
		}
	}
	for (int i = sum; i >= 1; i--) {
		s2 += s1[i];
	}


	for (int i = 1; i <= sum; i++) {
		if (s1[i] != s2[i]) {
			s2[i] = s1[i];
			s1[sum - i + 1] = s1[i];
			ans++;
		}
	}

	cout << ans;
	return 0;
}