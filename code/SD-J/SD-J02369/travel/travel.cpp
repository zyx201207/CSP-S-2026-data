#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
int c1, c2;
string s1, s2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2) << (c1 == c2 && (s1[0] - '0') * 10 + (s1[1] - '0') == (s2[0] - '0') * 10 + (s2[1] - '0'));
	if (c1 == c2 && (s1[0] - '0') * 10 + (s1[1] - '0') == (s2[0] - '0') * 10 + (s2[1] - '0') && (('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'E' && 'D' <= s2[2] && s2[2] <= 'E'))) cout << "1";
	else cout << "0";
	if (c1 == c2 && (s1[0] - '0') * 10 + (s1[1] - '0') == (s2[0] - '0') * 10 + (s2[1] - '0') && (('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'E' && 'D' <= s2[2] && s2[2] <= 'E')) && 
	s1[2] + 1 == s2[2] && !(s1[2] == 'C' && s2[2] == 'D')) cout << "1";
	else cout << "0";
	
	
	return 0;
}
