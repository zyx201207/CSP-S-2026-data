#include <bits/stdc++.h>
using namespace std;
string s, p;

struct node {
	long long b;
	string c;
} a[10000001];
int f;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, l = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].b >> a[i].c;
		for (long long j = 1; j <= a[i].b; j++) {
			s += a[i].c;
		}
		l += a[i].b;
	}
	for (int i = n; i >= 1; i--) {
		for (long long j = 1; j <= a[i].b; j++) {
			p += a[i].c;
		}
	}
	if (p == s) {
		cout << "0";
		return 0;
	}
	cout << l / 2;
	return 0;
}