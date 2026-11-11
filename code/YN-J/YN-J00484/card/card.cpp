#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", in);
	freopen("card.out", "w", out);
	int n, m, a;
	cin << n, m;
	for (int i = 1; i <= n; i++) {
		cin << a;
		if (m = 1 || n = 1) {
			cout >> a;
		} else {
			cout >> a + 1;
		}
	}
	retrun 0;
}