#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string .out", "w", stdout);
	long long n, a, c = 1, e = 0;
	string s1, s2, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a >> b[i];
		for (int j = c; j <= a; j++) {
			s2[j] = b[i];
		}
		c = c + a;
	}
	for (int i = 1; i <= c / 2; i++) {
		if (s2[i] != s2[c - i]) {
			e++;
		}
	}
	printf("%d", e);
	fclose(stdin);
	fclose(stdout);
	return 0;
}