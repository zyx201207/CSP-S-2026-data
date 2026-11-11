#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int n1, n2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	n1 = (s2[0] - 48) * 10 + (s2[1] - 48) * 1;
	n2 = (s4[0] - 48) * 10 + (s4[1] - 48) * 1;
	if (s1 == s3) {
		printf("1");
	} else {
		printf("0000");
		return 0;
	}
	if (n1 == n2) {
		printf("1");
	} else {
		printf("0");
	}
	if (n1 == n2 and ((s2[2] <= 'C' and s4[2] <= 'C') or (s2[2] > 'C' and s4[2] > 'C'))) {
		printf("1");
	} else {
		printf("0");
	}
	if (n1 == n2 and abs(s2[2] - s4[2]) == 1 and ((s2[2] <= 'C' and s4[2] <= 'C') or (s2[2] > 'C' and s4[2] > 'C'))) {
		printf("1");
	} else {
		printf("0");
	}


	return 0;
}