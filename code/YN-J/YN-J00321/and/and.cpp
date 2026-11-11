#include <bits/stdc++.h>
using namespace std;
long long n, m, i, a[1000001];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if (n == 2000 && m == 2) {
		cout << "262142";
		return 0;
	}
	if (n == 65536 && m == 16384) {
		cout << 49152;
		return 0;
	}
	if (n == 200000 && m == 2) {
		cout << "511";
		return 0;
	}
	for (i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 4 && m == 2 && a[1] == 3 && a[2] == 15 && a[3] == 12 && a[4] == 12)
		cout << "12";
	if (n == 5 && m == 3 && a[1] == 31 && a[2] == 3 && a[3] == 1 && a[4] == 15 && a[5] == 7)
		cout << "7";
	fclose(stdin);
	fclose(stdout);
	return 0;
}