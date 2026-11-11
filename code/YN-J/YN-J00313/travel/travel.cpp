#include <bits/stdc++.h>
using namespace std;
string a1, a2, b1, b2;

char solve1() {
	for (int i = 0; i < 2; i++) {
		if (a1[i] != b1[i])
			return '0';
	}
	return '1';
}

char solve2() {
	char x = solve1();
	if (x == '0')
		return '0';
	if (a2[0] == b2[0] && a2[1] == b2[1])
		return '1';
	else
		return '0';
}

char solve3() {
	char x = solve2();
	if (x == '0')
		return '0';
	if (((a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C') && (b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C'))
	        || (a2[2] == 'D' || a2[2] == 'F') && (b2[2] == 'D' || b2[2] == 'F'))
		return '1';
	else
		return '0';
}

char solve4() {
	char x = solve3();
	if (x == '0')
		return '0';
	if ((a2[2] == 'A' && b2[2] == 'B') || (a2[2] == 'B' && b2[2] == 'A') || (a2[2] == 'B' && b2[2] == 'C') || (a2[2] == 'C'
	        && b2[2] == 'B')
	        || (a2[2] == 'D' && b2[2] == 'F') || (a2[2] == 'F' && b2[2] == 'D'))
		return '1';
	else
		return '0';
}

int main() {
	freopen("travel.in", "w", stdin);
	freopen("travel.out", "r", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	cout << solve1() << solve2() << solve3() << solve4();

	return 0;
}