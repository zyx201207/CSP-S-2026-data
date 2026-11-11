#include <bits/stdc++.h>
using namespace std;
string l = "ABC", r = "DF";

bool chec(string s1, string s2) {
	int fl1 = l.find(s1[2]), fl2 = l.find(s2[2]);
	int fr1 = r.find(s1[2]), fr2 = r.find(s2[2]);
	return (fl1 != -1 && fl2 != -1) || (fr1 != -1 && fr2 != -1);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string sa, sb, ca, cb;
	cin >> ca >> sa >> cb >> sb;
	int ha = char(sa[0]) + char(sa[1]), hb = char(sb[0]) + char(sb[1]);
	bool is1 = (ca == cb);
	bool is2 = (is1 && ha == hb);
	bool is3 = (is2 && chec(sa, sb));
	bool is4 = (abs(sa[2] - sb[2]) == 1 && is3 || sa[2] == 'D' && sb[2] == 'F');
	cout << is1 << is2 << is3 << is4;
	return 0;
}