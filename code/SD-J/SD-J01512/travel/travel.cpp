#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b;
char x,y;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int n1,n2;
	cin >> n1;
	cin >> s1;
	cin >> n2;
	cin >> s2;
	if (n1 == n2) {
		cout << 1;
	}	
	else {
		cout << "0000";
		return 0;
	}
	
	for (int i = 0; i < s1.size() - 1; i++) {
		a += s1[i];
	}
	for (int i = 0; i < s2.size() - 1; i++) {
		b += s2[i];
	}
	if (a == b) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	x = s1[2];
	y = s2[2];
	if ((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C')) {
		cout << 1;
	}
	else if ((x == 'D' || x == 'F') && (y == 'D' || y == 'F')) {
		cout << 1;
	}
	else {
		cout << "00";
		return 0;
	}
	if (x > y) {
		swap(x,y);
	}
	if (x + 1 == y && x != 'C') {
		cout << 1;
	}
	else if (x == 'D' && y == 'F') {
		cout << 1;
	}
	else {
		cout << 0;
	}
//	cout << '\n' << x << ' ' << y << '\n';
	return 0;
}


