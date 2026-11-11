#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n, m;
	cin >> n >> m;

	if (n == 0) {
		int d;
		cin >> d;
		cout << '0';
		return 0;
	}
	if (n == 1) {
		int c;
		cin >> c;
		cout << '1';
		return 0;
	}
	if (n == 2) {
		int a, b;
		cin >> a >> b;
		if (b = a + m) {
			cout << '2';
			return 0;
		} else {
			cout << '1';
			return 0;
		}
	}
}
