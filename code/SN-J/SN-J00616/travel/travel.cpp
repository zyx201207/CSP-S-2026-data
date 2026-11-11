#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool f = 1, fa, fb;
bool f1, f2 = 1, f3, f4;
char ch1, ch2;
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	f1 = (c1 == c2);
	for (int i = 0; i < 2; i++) if (s1[i] != s2[i]) f2 = 0;
	ch1 = s1[2], ch2 = s2[2];
	if (ch1 == 'A' || ch1 == 'B' || ch1 == 'C') fa = 1;
	if (ch2 == 'A' || ch2 == 'B' || ch2 == 'C') fb = 1;
	f3 = (fa == fb);
	if (ch1 > ch2) swap(ch1, ch2);
	f4 = (ch2-ch1 == 1);
	cout << f1 << (f1 && f2) << (f1 && f2 && f3) << (f1 && f2 && f3 && f4);
	return 0;
}
