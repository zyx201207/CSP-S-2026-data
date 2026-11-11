#include <bits/stdc++.h>
using namespace std;
char s1[5], s2[5];
int c1, c2, sum[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1;
	for (int i = 1; i <= 3; i++)
		cin >> s1[i];
	cin >> c2;
	for (int i = 1; i <= 3; i++)
		cin >> s2[i];
	if (c1 == c2) {
		sum[1] = 1;
		if (s1[1] == s2[1] && s1[2] == s2[2]) {
			sum[2] = 1;
			if (s1[3] == 'B' && s2[3] == 'A' || s1[3] == 'B' && s2[3] == 'C' || s1[3] == 'A' && s2[3] == 'B' || s1[3] == 'A'
			        && s2[3] == 'C'
			        || s1[3] == 'C' && s2[3] == 'B' || s1[3] == 'C' && s2[3] == 'A' || s1[3] == 'D' && s2[3] == 'F' || s1[3] == 'F'
			        && s2[3] == 'D') {
				sum[3] = 1;
				if (s1[3] == 'B' && s2[3] == 'A' || s1[3] == 'B' && s2[3] == 'C' || s1[3] == 'A' && s2[3] == 'B' || s1[3] == 'C'
				        && s2[3] == 'B'
				        || s1[3] == 'D' && s2[3] == 'F' || s1 [3] == 'F' && s2[3] == 'D')
					sum[4] = 1;
				else
					sum[4] = 0;
			} else {
				sum[3] = 0;
				sum[4] = 0;
			}

		} else
			for (int i = 2; i <= 4; i++)
				sum[i] = 0;
	} else
		for (int i = 1; i <= 4; i++)
			sum[i] = 0;
	for (int i = 1; i <= 4; i++)
		cout << sum[i];

	return 0;
}
