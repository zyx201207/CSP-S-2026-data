#include <bits/stdc++.h>
using namespace std;

int x, y;
string s1, s2;
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> x >> s1 >> y >> s2;
	int chexiangx = int (s1[0]) * 10 + int (s1[1]);
	int chexiangy = int (s2[0]) * 10 + int (s2[1]);
	int flaga, flagb;
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') flaga = 1;
	else flaga = 2;
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') flagb = 1;
	else flagb = 2;
	if (x == y) cout << 1;
	else cout << 0;
	if (chexiangx == chexiangy && x == y) cout << 1;
	else cout << 0;
	if (flaga == flagb && chexiangx == chexiangy && x == y) cout << 1;
	else cout << 0;
	int zuoweia = int (s1[2]), zuoweib = int (s2[2]);
	if (zuoweia < zuoweib) swap (zuoweia, zuoweib);
	if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')) {
		cout << 0;
		return 0;
	}
	// zuoweia > zuoweib
	if (zuoweia == zuoweib + 1 && chexiangx == chexiangy && x == y) cout << 1;
	else cout << 0;
	// cout << zuoweia << " " << zuoweib;
	return 0;
}
