#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2;
	string b1, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int c1 = ( b1[0] * 10 - '0' * 10) + (b1[1] - '0'), c2 = b2[0] * 10 + b2[1] - '0' * 10 - '0';
	if (a1 == a2)
		cout << 1;
	else
		cout << 0;
	if (a1 == a2 && c1 == c2)
		cout << 1;
	else
		cout << 0;
	if (a1 == a2 && c1 == c2 && (((b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C') && (b2[2] == 'A' || b2[2] == 'B'
	                              || b2[2] == 'C'))
	                             || ((b1[2] == 'D' || b1[2] == 'F') && (b2[2] == 'D' || b2[2] == 'F'))))
		cout << 1;
	else
		cout << 0;
	if (a1 == a2 && c1 == c2 && ((abs(b1[2] - b2[2]) == 1) && (b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C')
	                             && (b2[2] == 'A' || b2[2] == 'B'
	                                 || b2[2] == 'C')) || ((b1[2] == 'D' || b1[2] == 'F' ) && (b2[2] == 'D' || b2[2] == 'F'
	                                                                                          )))
		cout << 1;
	else
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}