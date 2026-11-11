#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string t1, s1, t2, s2;
	cin >> t1 >> s1 >> t2 >> s2;
	int a1 = t1[1] + t1[0] * 10, a2 = t2[1] + t2[0] * 10;
	int b1 = s1[1] + s1[0] * 10, b2 = s2[1] + s2[0] * 10;
	int c1, c2;
	if (s1[2] == 'D') c1 = 5;
	else c1 = s1[2] - 64;
	if (s2[2] == 'D') c2 = 5;
	else c2 = s2[2] - 64;
	if (a1 == a2) cout << 1;
	else cout << 0;
	if (a1 == a2 && b1 == b2) cout << 1;
	else cout << 0;
	if (a1 == a2 && b1 == b2 && ((c1 <= 3 && c2 <= 3) || (c1 >= 5 && c2 >= 5))) cout << 1;
	else cout << 0;
	if (a1 == a2 && b1 == b2 && (c1 - c2 == 1 || c2 - c1 == 1)) cout << 1;
	else cout << 0;
	return 0;
}
