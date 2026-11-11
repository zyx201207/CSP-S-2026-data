#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> a[i] >> b[i];
	}

	if (n == 1) {
		cout << "0";
	} else if (n == 2) {
		if (b[0] == b[1])
			cout << "0";
		else
			cout << min(a[0], a[1]);

	}

	return 0;
	fclose(stdin);
	fclose(stdout);
}