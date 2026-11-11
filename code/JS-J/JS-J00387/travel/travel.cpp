#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
	char s11 = s1[2], s22 = s2[2];
	int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	if(c1 == c2) f1 = 1;
	if(f1 && (s1.substr(0, 2) == s2.substr(0, 2))) f2 = 1;
	if	(f1&&f2&&((s11=='A'&&s22=='B')||(s11=='A'&&s22=='C')||(s11=='B'&&s22=='C')||(s11=='B'&&s22=='A')||
		(s11=='C'&&s22=='A')||(s11=='C'&&s22=='B')||(s11=='D'&&s22=='F')||(s11=='F'&&s22=='D'))) f3 = 1;
	if	(f1 && f2 && ((s11=='A'&&s22=='B')||(s11=='B'&&s22=='A')||(s11=='C'&&s22=='B')||
		(s11=='B'&&s22=='C')||(s11=='D'&&s22=='F')||(s11=='F'&&s22=='D'))) f4 = 1;
	cout << f1 << f2 << f3 << f4;
	return 0;
}

