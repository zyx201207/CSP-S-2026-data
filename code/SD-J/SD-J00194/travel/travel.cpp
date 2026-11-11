#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
bool a1, a2, a3, a4;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s1 >> s2 >> s3 >> s4;
	a1 = (s1 == s3);
	a2 = (a1 && (s2[0] == s4[0] && s2[1] == s4[1]));
	char p = s2[2], q = s4[2];
	a3 = (a2 && ((p >= 'A' && p <= 'C' && q >= 'A' && q <= 'C') || (p >= 'D' && p <= 'F' && q >= 'D' && q <= 'F')));
	if(a3 == 0) a4 = 0;
	else {
		if((p == 'A' && q == 'B') || (p == 'B' && q == 'A') || (p == 'B' && q == 'C') || (p == 'C' && q == 'B') || (p == 'D' && q == 'F') || (p == 'F' && q == 'D')) a4 = 1;
	} 
	cout << a1 << a2 << a3 << a4;
	return 0;
} 
