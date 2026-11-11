#include <bits/stdc++.h>
#define int long long
using namespace std;

string c1, s1, c2, s2;
int n1, n2, m1, m2, p1, p2;

signed main () {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 != c2) cout << 0 << 0 << 0 << 0;
	else {
		cout << 1;
		
		n1 = s1[0]*10+s1[1];
		n2 = s2[0]*10+s2[1];
		if (n1 != n2) cout << 0 << 0 << 0;
		else {
			cout << 1;
			
			if (s1[2] == 'A') m1 = 1;
			if (s1[2] == 'B') m1 = 2;
			if (s1[2] == 'C') m1 = 3;
			if (s1[2] == 'D') m1 = 4;
			if (s1[2] == 'F') m1 = 5;
			
			if (s2[2] == 'A') m2 = 1;
			if (s2[2] == 'B') m2 = 2;
			if (s2[2] == 'C') m2 = 3;
			if (s2[2] == 'D') m2 = 4;
			if (s2[2] == 'F') m2 = 5;
			
			if (m1 <= 3) p1 = 0;
			else p1 = 1;
			if (m2 <= 3) p2 = 0;
			else p2 = 1;
			
			if (p1 != p2) cout << 0 << 0;
			else {
				cout << 1;
				
				if (abs(m1-m2) == 1) cout << 1;
				else cout << 0;
			}
		}
	}

	return 0;
}

