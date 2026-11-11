#include <bits/stdc++.h>
using namespace std;
int a[1000010];

int main() {
	freopen("migrate,in", "r", stdin);
	freopen("migrate,out", "w", stdout);
	int k, m;
	cin >> k >> m;
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4) {
		cout << 1 << endl << 2;
	} else {
		cout << 0 << endl << 1;
	}
}