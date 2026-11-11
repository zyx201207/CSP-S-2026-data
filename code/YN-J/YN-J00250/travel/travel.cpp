#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "r", stdout);

	char c1[2], s1[3];
	char c2[2], s2[3];

	cin >> c1 ;
	cin >> s1 ;
	cin >> c2 ;
	cin >> s2 ;

	int a[4] = {0};
	int sum = 0;

	if (c1 == c2) {
		a[0] = 1;
		sum = 1;
	} else {
		a[0] = 0;
	}

	int b = 1;
	if (sum == 1) {

		for (int i = 1; i < 2; i++) {
			if (s1[i] == s2[i]) {
				a[b] = 1;
				b++;
				sum++;
			} else {
				a[b] = 0;
				b++;
			}
		}

	}
	if (sum == 2) {
		for (int i = 2; i < 3 ; i++) {
			if (((s1[i] == 'A') && (s2[i] == 'B')) || ((s1[i] == 'A') && (s2[i] == 'C')) || ((s1[i] == 'B') && (s2[i] == 'C'))) {
				a[b] = 1;
				b++;
				sum++;
				break;
			} else if (((s2[i] == 'A') && (s1[i] == 'B')) || ((s2[i] == 'A') && (s1[i] == 'C')) || ((s2[i] == 'B')
			           && (s1[i] == 'C'))) {
				a[b] = 1;
				b++;
				sum++;
				break;
			} else if (((s1[i] == 'D') && (s2[i] == 'F')) || ((s1[i] == 'F') && (s2[i] == 'D'))) {
				a[b] = 1;
				b++;
				sum++;
				break;
			} else {
				a[b] = 0;
				b++;
				sum++;
				break;
			}

		}

	}
	if (sum == 3) {
		for (int i = 2; i < 3 ; i++) {
			if ((s1[i] - s2[i] == 1) || (s2[i] - s1[i] == 1)) {
				if (((s1[i] == 'C') && (s2[i] == 'D')) || ((s2[i] == 'C') && (s1[i] == 'D'))) {
					a[b] = 0;
					b++;
					break;
				} else {
					a[b] = 1;
					b++;
				}
			} else {
				a[b] = 0;
				b++;
			}
		}


	}



	for (int i = 0; i < 4; i++) {
		cout << a[i];
	}


	return 0;
}