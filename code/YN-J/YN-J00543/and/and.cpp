#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n;
	long long a[200005] = {0};
	long long m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	cout << a[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}