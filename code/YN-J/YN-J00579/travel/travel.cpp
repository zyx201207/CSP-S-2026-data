#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;

char a[4] = {'0', '0', '0', '0'};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int e = 0;
	if (c1 == c2)
		a[0] = '1';
	e = s1[2] - s2[2];
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		a[1] = '1';
		if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C')
			a[2] = '1';
		else if (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')
			a[2] = '1';
		if (a[2] == '1') {
			if (e == 1 || e == -1)
				a[3] = '1';
		}
	}
	for (int i = 0; i <= 3; i++)
		cout << a[i];
	return 0;
}