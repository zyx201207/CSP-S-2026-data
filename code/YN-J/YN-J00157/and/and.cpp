#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ma = 0;
	while (n--) {
		int x;
		cin >> x;
		if (x > ma) {
			ma = x;
		}

	}
	cout << ma;




	return 0;
}