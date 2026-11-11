#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string s = "";
	if(s1 == s3) s += '1';
	else {
		s += "0000";
		cout << s << '\n';
		return 0;
	}
	if(s2[0] == s4[0] && s2[1] == s4[1]) s += '1';
	else s += '0';
	if(s[1] == '1' && ('A' <= s2[2] && s2[2] <= 'C' && 'A' <= s4[2] && s4[2] <= 'C') || ('D' <= s2[2] && s2[2] <= 'F' && 'D' <= s4[2] && s4[2] <= 'F')) s += '1';
	else s += '0';
	if(s[2] == '1' && abs(s2[2] - s4[2]) == 1) s += '1';
	else s += '0';
	cout << s << '\n';
	return 0;
}