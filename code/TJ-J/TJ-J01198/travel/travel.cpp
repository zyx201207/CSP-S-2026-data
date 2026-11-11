#include <bits/stdc++.h>

using namespace std;

char s1[5], s2[5], t1, t2;

int a, b, c, d;
 
int main (){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> a >> s1 >> b >> s2;
	for (int i = 0; i < 2; i++) {
		c *= 10; 
		c += (s1[i] - '0');
		d *= 10; 
		d += (s2[i] - '0');
	}
	t1 = s1[2];
	t2 = s2[2];
	if (a != b) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	if (c != d) {
		cout << "000";
		return 0;
	}
	cout << "1";
	if (t1 == 'A' || t1 == 'B' || t1 == 'C' && t2 == 'A' || t2 == 'B' || t2 == 'C') cout << "1";
	else if (t1 == 'D' || t1 == 'F' && t2 == 'D' || t2 == 'F') cout << "1";
	else {
		cout << "00";
		return 0;
	}
	if (t1 + 1 == t2 || t2 + 1 == t1) cout << "1";
	else cout << "0";
	fclose (stdin);
	fclose (stdout);
	return 0;
}
