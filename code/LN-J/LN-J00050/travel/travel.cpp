#include <bits/stdc++.h>
using namespace std;

string k1, k2, s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> k1 >> s1 >> k2 >> s2;
	char sub10 = s1[0], sub11 = s1[1];
	char sub20 = s2[0], sub21 = s2[1];
	if (k1 == k2)
		printf("1");
	else
		printf("0");
	//cout << sub10 << " " << sub20 << "\n";
	//cout << sub11 << " " << sub21 << "\n";
	if ((sub10 == sub20) && (sub21 == sub11) && (k1 == k2))
		printf("1");
	else
		printf("0");
	bool f1 = false, f2 = false;
	for (int i = 'A'; i <= 'C'; i++) {
		if (s1[2] == i)
			f1 = true;
		if (s2[2] == i)
			f2 = true;
	}
	if (!f1 && !f2)
		for (int i = 'D'; i <= 'F'; i++) {
			if (s1[2] == i)
				f1 = true;
			if (s2[2] == i)
				f2 = true;
		}
	if ((sub10 == sub20) && (sub21 == sub11) && f1 && f2 && (k1 == k2))
		printf("1");
	else
		printf("0");
	if ((sub10 == sub20) && (sub21 == sub11) && (s1[2] != 'C' && s2[2] != 'D') && (s1[2] != 'D' && s2[2] != 'C') &&
		((s1[2] + 1 == s2[2]) || (s2[2] + 1 == s1[2])) && (k1 == k2))
		printf("1");
	else
		printf("0");
	return 0;
}
