#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			int a, b;
			if (s1[2] == 'D' || s1[2] == 'F') a = 2;
			else a = 1;
			if (s2[2] == 'D' || s2[2] == 'F') b = 2;
			else b = 1;
			if (a == b) {
				cout << 1;
				if (a == 2 || !((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A'))) {
					cout << 1;
				} else printf("0");
			} else printf("00");
		} else printf("000");
	} else printf("0000");
	
	return 0;
} 
