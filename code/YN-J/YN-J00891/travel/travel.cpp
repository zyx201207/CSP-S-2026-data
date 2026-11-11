#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string A, B, C, D;
	cin >> A >> B >> C >> D;
	int z = 0;
	if (A == C) {
		cout << 1;
		z++;
		if ((B[1] + B[0]) == (D[0] + D[1])) {
			cout << 1;
			z++;
			if ((B[2] <= 'C' && D[2] <= 'c') || (B[2] > 'c' && D[2] > 'c')) {
				cout << 1;
				z++;
				if ((B[2] + 1 == D[2]) || (B[2] - 1 == D[2])) {
					cout << 1;
					z++;
				}
			}
		}
	}
	for (int q = 0; q < 4 - z; q++) {
		cout << 0;
	}
}