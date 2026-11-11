#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100005;
int n, a[N];
string c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] == c[i + 1])
			flag = 1;
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		cout << "0";
		return 0;
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	cout << s / 2;
	return 0;
}