#include <bits/stdc++.h>
#define int long long
using namespace std;
const unsigned long long rp = 2e18;
int c1,c2;
string s1,s2;
int c(char x) {
	return x - '0';
}
pair<int,int> pos(string& s) {
	return {c(s[0]) * 10 + c(s[1]),(s[2] == 'F'?5:s[2] - 'A' + 1)};
}
signed main() { 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int flg = 1;
	bool a1 = (c1 == c2);
	pair<int,int> p1 = pos(s1),p2 = pos(s2);
	bool a2 = (p1.first == p2.first) && a1;
	bool a3 =
	    ((p1.second <= 3 && p2.second <= 3) || (p1.second >= 4 && p2.second >= 4)) && a2;
	bool a4 = (abs(p1.second - p2.second) == 1) && a3;
	cout << a1 << a2 << a3 << a4;
	return 0;
}
