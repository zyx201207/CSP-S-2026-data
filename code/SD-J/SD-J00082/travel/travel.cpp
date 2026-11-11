#include <bits/stdc++.h>
#define ll long long
using namespace std;
string cx, sx, cy, sy;
int c[2];
int hang[2];
char lei[2];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cx >> sx >> cy >> sy;
	c[0] = (cx[0] - '0') * 10 + (cx[1] - '0');
	c[1] = (cy[0] - '0') * 10 + (cy[1] - '0');
	hang[0] = (sx[0] - '0') * 10 + (sx[1] - '0');
	hang[1] = (sy[0] - '0') * 10 + (sy[1] - '0');
	lei[0] = sx[2];
	lei[1] = sy[2];
	bool tongce, xianglin;
	tongce = (('A' <= lei[0] && lei[0] <= 'C') && ('A' <= lei[1] && lei[1] <= 'C'))
	 || (('D' <= lei[0] && lei[0] <= 'F') && ('D' <= lei[1] && lei[1] <= 'F'));
	xianglin = tongce && (abs(lei[0] - lei[1]) == 1);
	
	if (c[0] == c[1]) {
		cout << 1;
	} else cout << 0;
	if (c[0] == c[1] && hang[0] == hang[1]) {
		cout << 1;
	} else cout << 0;
	if (c[0] == c[1] && hang[0] == hang[1] && tongce) {
		cout << 1;
	} else cout << 0;
	if (c[0] == c[1] && hang[0] == hang[1] && tongce && xianglin) {
		cout << 1;
	} else cout << 0;
	return 0;
}
