#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a, b = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (b == a) {
			cout << a;
			return 0;
		}
		b = a;
	}
	return 0;
}