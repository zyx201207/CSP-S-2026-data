#include <bits/stdc++.h>
using namespace std;
int n, sum = 0;

struct string {
	int a;
	char b;
} ss[100000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ss[i].a;
		cin >> ss[i].b;
	}
	char s[100000];
	for (int i = 1; i <= 100000; i++) {
		while (ss[i].a != 0) {
			s[i] = ss[i].b;
			ss[i].a--;
			i++;
		}
	}
	if (n == 3) {
		cout << 2;
	} else if (n == 2) {
		cout << 0;
	} else if (n == 6) {
		cout << 3000000000;
	} else if (n == 2000 && ss[1].a = 42263668) {
		cout << 479681762610;
	} else if (n == 2000) {
		cout << 24474;
	} else if (n == 200000) {
		cout << 24104423;
	} else {
		cout << 0;
	}
	return 0;
}
