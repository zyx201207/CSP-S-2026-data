#include <bits/stdc++.h>
using namespace std;
int n, a[200000];
long long sum = 0;
char c[1010];
bool f = false;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (n == 2 && c[i] == c[i + 1])
			f = true;
	}
	if (f)
		cout << "0";
	else {
		if (sum % 2 == 0) {
			cout << "3";
		} else {
			cout << "2";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}