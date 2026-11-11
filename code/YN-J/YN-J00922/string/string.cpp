#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, a, cnt = 0;
	char b;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> b;
	}

	for (int i = 1; i <= a; i++) {

		if (b) {
			cnt = 0;
		} else {
			cnt = 2;
		}
	}

	cout << cnt;
	return 0;
}
