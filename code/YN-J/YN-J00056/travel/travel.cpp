#include <iostream>
#include <string>
using namespace std;
string c1, c2, s1, s2;
int C1, C2, S1, S2;
int a1, a2, a3, a4;
int a[5];

bool near(int a, int b) {
	return a + 1 == b || a - 1 == b;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	C1 = (c1[0] - '0') + (c1[1] - '0');
	C2 = (c2[0] - '0') + (c2[1] - '0');
	S1 = (s1[0] - '0') + (s1[1] - '0');
	S2 = (s2[0] - '0') + (s2[1] - '0');
	if (C1 == C2)
		a[1] = 1;
	if (a[1] && S1 == S2)
		a[2] = 1;
	int seat1 = s1[2] - 'A';
	int seat2 = s2[2] - 'A';
	if (a[1] && a[2] && ((seat1 <= 2 && seat2 - 'A' <= 2) || (seat1 - 'A' > 2 && seat2 - 'A' > 2)))
		a[3] = 1;
	a4 = near(seat1, seat2);
	//cout << near(seat1, seat2) << "\n";
	if (a[1] && a[2] && a[3] && a4)
		a[4] = 1;
	for (int i = 1; i <= 4; i++) {
		cout << a[i];
	}

	return 0;
}