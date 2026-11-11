#include <bits/stdc++.h>
using namespace std;
int a[6];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("trevele.out", "w", stdout);
	int x, y;
	string c1, s1, c2, s2;
	cin >> c1 >> x >> s1 >> c2 >> y >> s2;
	if (c1 == c2) {
		a[1] = 1;
		if (c1 == c2 && x == y) {
			a[2] = 1;
			if (c1 == c2 && x == y && s1 == "A" && s2 == "B" || s1 == "A" && s2 == "C" || s1 == "B" && s2 == "C" || s1 == "D"
			        && s2 == "F" || s1 == "B" && s2 == "A" || s1 == "C" && s2 == "A" || s1 == "C" && s2 == "B" || s1 == "F" && s2 == "D") {
				a[3] = 1;
				if (c1 == c2 && x == y && s1 == "A" && s2 == "B" || s1 == "B" && s2 == "C" || s1 == "D" && s2 == "F" || s1 == "B"
				        && s2 == "A" || s1 == "C" && s2 == "B" || s1 == "F" && s2 == "D")
					a[4] = 1;
			}
		}
	}
	for (int i = 1; i <= 4; i++)
		cout << a[i];
	return 0;
}