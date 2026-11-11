#include <bits/stdc++.h>
using namespace std;

bool left(char ch) {
	return 'A' <= ch && ch <= 'C';
}

bool next_to(char a, char b) {
	if (a > b) swap(a, b);
	if ((b - a == 1 && !(a == 'C' && b == 'D')) ||
		(a == 'D' && b == 'F')) return true;
	return false;
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int cx, cr; string sx, sr; 
	cin >> cx >> sx >> cr >> sr;
	
	string ans;
	if (cx == cr) ans.push_back('1');
	else ans.push_back('0');
	if (ans[0] == '1' && sx[0] == sr[0] && sx[1] == sr[1])
		ans.push_back('1');
	else ans.push_back('0');
	if (ans[1] == '1' && left(sx[2]) == left(sr[2])) 
		ans.push_back('1');
	else ans.push_back('0');
	if (ans[2] == '1' && next_to(sx[2], sr[2]))
		ans.push_back('1');
	else ans.push_back('0');
	cout << ans; return 0;
}
