#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int c1, c2;
	string s1, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	int r1, r2;
	r1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	r2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	char t1 = s1[2], t2 = s2[2];
	
	bool req = false;
	if (r1 == r2) {
		cout << 1;
		req = true;
	} else cout << 0;
	
	if (req == true && (
		(t1 >= 'A' && t1 <= 'C' && t2 >= 'A' && t2 <= 'C') || 
		(t1 >= 'D' && t1 <= 'F' && t2 >= 'D' && t2 <= 'F')
	)) {
		cout << 1;
		if ((t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'A') ||
			(t1 == 'C' && t2 == 'B') || (t1 == 'B' && t2 == 'C') || 
			(t1 == 'D' && t2 == 'F') || (t1 == 'F' && t2 == 'D')
		) cout << 1;
		else cout << 0;
	} else cout << "00";
	
	return 0;
}