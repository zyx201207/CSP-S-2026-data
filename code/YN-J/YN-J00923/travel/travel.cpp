#include <bits/stdc++.h>
using namespace std;

int c1, c2, sum, sum1;
string s1, s2, ans, ans1;
int st, st1;

int main() {

	freopen("travel.in","r",stdout);
	freopen("travel.out","w",stdout);

	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << "1";
	} else
		cout << " 0";

	for (int i = 1; i <= s1.size(); i++) {

		if (i <= 2) {
			sum += s1[i];
		}

		if (i == 3) {
			ans = s1[i];
		}
	}

	for (int i = 1; i <= s2.size(); i++) {

		if (i <= 2) {
			sum1 += s2[i];
		}

		if (i == 3) {
			ans = s2[i];
		}
	}

	if (sum == sum1) {
		cout << "1";
	} else
		cout << "0";

	cout << "0";
	cout << "0";

	return 0;
}
