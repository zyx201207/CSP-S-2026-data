#include <bits/stdc++.h>
using namespace std;
int n;
int i;
int p = 0;
char j;
char so[100000000];
char s[100000000];
int sl;

int main() {
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	cin >> n;
	for (int q = 0; q < n; q++) {
		cin >> i;
		cin >> j;
		for (int a = 1; a <= i; a++) {
			so[a + p] = j;
		}
		p = p + i;
	}
	for (int q = p; q > 0; q--) {
		for (int a = p + 1 - q; a < p + 2 - q; a++) {
			s[q] = so[a];
		}
	}
	for (int q = 1; q <= p / 2; q++) {
		if (s[q] != so[q]) {
			s[q] = so[q];
			sl++;
		}
	}
	cout << sl;
}