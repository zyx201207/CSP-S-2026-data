#include <bits/stdc++.h>
using namespace std;
int cx1, cx2, p1, p2;
char zm1, zm2;
bool is_cx, is_p, is_c;
string zw1, zw2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> cx1 >> zw1 >> cx2 >> zw2;
	p1 = (zw1[0]-'0')*10 + (zw1[1]-'0');
	p2 = (zw2[0]-'0')*10 + (zw2[1]-'0');
	zm1 = zw1[2];
	zm2 = zw2[2];
	is_cx = cx1 == cx2;
	is_p  = p1 == p2;
	is_c  = (zm1 <= 'C' && zm2 <= 'C') || (zm1 >= 'D' && zm2 >= 'D');
	if (is_cx) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (is_cx && is_p) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (is_cx && is_p && is_c) {
		cout << 1;	
	} else {
		cout << 0;
	}
	if (is_cx && is_p && is_c && abs(zm1-zm2) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	cout << '\n';
	return 0;
} 
