#include <bits/stdc++.h>
using namespace std;
int c, c1;
string s, s1;

int main() {
//	freopen("travel.in", "r", stdin);
//	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	cin >> c >> s >> c1 >> s1;
	if (c == c1) {
		f1 = 1;
	}
	int flag = 0;
	int j = 1;
	for (char i = 'A'; j <= 5; j++) {
		char ce = s[3], ce1 = s1[3];
		if (i == ce || ce1 == i ) {
			flag++;
		}
		if (flag == 2) {
			f2 = 1;
			f3 = 1;
			f4 = 1;
			break;
		}
		i++;
	}
	cout << f1  << f2  << f3  << f4;
	return 0;
}