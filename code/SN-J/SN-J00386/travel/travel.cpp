#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cx,cy;
	string sx,sy;
	cin >> cx >> sx >> cy >> sy;
	bool f1 = 0,f2 = 0,f3 = 0,f4 = 0;
	if(cx == cy) {
		cout << 1;
		f1 = 1;
	} else cout << 0;
	if(f1 == 1 && sx[0] == sy[0] && sx[1] == sy[1]) {
		cout << 1;
		f2 = 1;
	} else cout << 0;
	if(f2 == 1 && (sx[2] >= 'A' && sx[2] <= 'C' && sy[2] >= 'A' && sy[2] <= 'C') || (sx[2] >= 'D' && sx[2] <= 'F' && sy[2] >= 'D' && sy[2] <= 'F')) {
		cout << 1;
		f3 = 1;
	} else cout << 0;
	if(f3 == 1 && (sx[2] - 1 == sy[2] || sx[2] + 1 == sy[2])) cout << 1;
	else cout << 0;
	return 0;
}
