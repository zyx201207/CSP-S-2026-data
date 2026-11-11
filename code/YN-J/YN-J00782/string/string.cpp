#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	string s;
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		int a;
		char b;
		cin >> a >> b;
		sum += a;
		for (int j = 1; j <= a; j++) {
			s += b;
		}
	}

	int cnt = 0;
	bool panduan = 0;
	int size = s.size();
	for (int i = 0; i * i < sum; i++) {
		if (s[i] == s[size - i - 1]) {
			panduan = 1;
		} else {
			panduan = 0;
			//cout << s[i] << ' ' << s[size - i - 1] << ' ' << i << ' ' << cnt << ' ' << endl;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}