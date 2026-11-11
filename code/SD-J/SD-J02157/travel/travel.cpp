// I love HanRui
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t1, t2, t3, g;
bool q1, q2, q3, q4;
string s, c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	getline(cin, s);
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			g++;
			if (g == 1) t1 = i;
			if (g == 2) t2 = i;
			if (g == 3) t3 = i;
		}
	}
	c1 = s.substr(0, 2), s1 = s.substr(t1 + 1, 3);
	c2 = s.substr(t2 + 1, 2), s2 = s.substr(t3 + 1, 3);	
	if (c1 != c2) {
		cout << q1 << q2 << q3 << q4;
		return 0;
	}
	q1 = 1;
	cout << q1;
	
	string p1 = s1.substr(0, 2), p2 = s2.substr(0, 2);
	char f1 = s1[2], f2 = s2[2];
	if (p1 == p2) q2 = 1;
	cout << q2;
	
	if (q2 == 1 && (f1 <= 'C' && f2 <= 'C') || (f1 > 'C' && f2 > 'C')) q3 = 1;
	cout << q3;
	
	if (q3 == 1 && ((ll)(f1 - f2) == 1 || (ll)(f2 - f1) == 1)) q4 = 1;
	cout << q4;
	return 0;
}
//9:40
