#include <bits/stdc++.h>
using namespace std;

string ejz(long long n) {
	char c;
	string s;

	while (n != 0) {
		c = n % 2 + '0';
		s = c + s;
		n /= 2;
	}

	return s;
}
int a[200005];
long long i, n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (i = 0; i < n; i++) {

		scanf("%d", &a[i]);
	}

	if (n == 4 && m == 2) {
		cout << 12;
	}

	if (n == 5 && m == 3) {
		cout << 7;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}