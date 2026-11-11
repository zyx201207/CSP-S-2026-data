#include <bits/stdc++.h>
using namespace std;
int n = 2, d = 3;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int k1;
	cin >> k1;
	string c1;
	cin >> c1;
	int k2;
	cin >> k2;
	string c2;
	cin >> c2;
	if (k1 == k2) {
		cout << 1;
		if (c1[0] * 10 + c1[1] == c2[0] * 10 + c2[1]) {
			cout << 1;
			if ((c1[2] >= 'A' && c1[2] <= 'C' && c2[2] >= 'A' && c2[2] <= 'C') || (c1[2] >= 'D' && c1[2] <= 'F' && c2[2] >= 'D'
			        && c2[2] <= 'F')) {
				cout << 1;
				if ((int) c1[2] + 1 == (int)c2[2] || (int) c1[2] - 1 == (int)c2[2]) {
					cout << 1;
				} else
					cout << 0;
			} else
				cout << 00;
		} else
			cout << 000;
	} else
		cout << 0000;
	return 0;
}
