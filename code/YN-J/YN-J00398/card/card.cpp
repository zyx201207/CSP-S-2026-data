#include <bits/stdc++.h>
using namespace std;
int c[1000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int a, b, sum = 0;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= b; i++) {
		if (i == c[a]) {
			cout << a << " ";
			continue;
		}
		if (i != c[1]) {
			sum = 0;
			for (int j = 2; j < a; j++) {
				if (i == c[j]) {
					sum++;
				}
			}
			cout << sum << " ";
			continue;
		}
		if (i == c[1]) {

			cout << b << " ";
			continue;
		}
	}
	return 0;
}