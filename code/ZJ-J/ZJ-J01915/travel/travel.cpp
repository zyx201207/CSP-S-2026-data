#include<bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int main() { 
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> s1 >> s2 >> s3 >> s4;
	bool b1 = (s1[0] == s3[0] && s1[1] == s3[1]);
	bool b2 = (s2[0] == s4[0] && s2[1] == s4[1]);
	bool b3 = (((s2[2] == 'A' && (s4[2] == 'B' || s4[2] == 'C')) || (s2[2] == 'B' && (s4[2] == 'A' || s4[2] == 'C')) || (s2[2] == 'C' && (s4[2] == 'B' || s4[2] == 'A'))) || ((s2[2] == 'D' && s4[2] == 'F') || (s2[2] == 'F' && s4[2] == 'D')));
	bool b4 = (abs(s2[2] - s4[2]) == 1 && !(s2[2] == 'C' && s4[2] == 'D') && !(s2[2] == 'D' && s4[2] == 'C'));
	cout << b1 << (b1 && b2) << (b1 && b2 && b3) << (b1 && b2 && b3 && b4);
	return 0;
}
