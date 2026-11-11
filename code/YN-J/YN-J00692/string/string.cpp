#include <bits/stdc++.h>
using namespace std;
long long n, a, b1[10001], c = 0, st[100000001], la[100000001], d = 0;
string b2[10001];

long long num1(int x) {
	int cnt = 1;
	while (x != 0) {
		cnt++;
		x -= b1[cnt];
	}
	return cnt;
}

long long num2(int x) {
	int cnt = n;
	while (x != 0) {
		cnt--;
		x -= b1[cnt];
	}
	return cnt;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> b1[i] >> b2[i];
		c += b1[i];
	}
	for (int i = 1; i <= c; i++) {
		if (b2[num1(i)] != b2[num2(i)])
			d++;
	}
	cout << d;
	return 0;
}