#include <bits/stdc++.h>
using namespace std;
string s;
long long cnt;
long long l;

void move() {
	long long L = 0, R = l - 1;
	while (L < R) {
		char a = s[L];
		char b = s[R];
		if (a != b) {
			cnt++;
		}
		L++;
		R--;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int a;
		char c;
		cin >> a;
		cin >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
		l += a;
	}

	move();
	cout << cnt;
	return 0;
}