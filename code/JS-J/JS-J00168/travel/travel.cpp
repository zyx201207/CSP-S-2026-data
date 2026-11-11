#include <bits/stdc++.h>
#define int long long

using namespace std;

bool flag = true;
string s1, s2, t1, t2;

bool check1() {
	flag = (s1 == t1);
	return flag;
}

bool check2() {
	if(!flag)
		return false;
	flag = (s2[0] == t2[0] and s2[1] == t2[1]);
	return flag;
}

bool check3() {
	if(!flag)
		return false;
	char c1 = s2[2], c2 = t2[2];
	if((c1 == 'D' and c2 == 'F') or (c2 == 'D' and c1 == 'F'))
		return true;
	if((c1 == 'A' and (c2 == 'B' or c2 == 'C')) or (c1 == 'B' and (c2 == 'A' or c2 == 'C')) or (c1 == 'C' and (c2 == 'A' or c2 == 'B')))
		return true;
	flag = false;
	return flag;
}

bool check4() {
	if(!flag)
		return false;
	char c1 = s2[2], c2 = t2[2];
	if((c1 == 'D' and c2 == 'F') or (c1 == 'F' and c2 == 'D'))
		return true;
	if((c1 == 'A' and c2 == 'B') or (c1 == 'B' and c2 == 'A') or (c1 == 'B' and c2 == 'C') or (c1 == 'C' and c2 == 'B'))
		return true;
	flag = false;
	return flag;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> t1 >> t2;
	cout << (check1() ? 1 : 0);
	cout << (check2() ? 1 : 0);
	cout << (check3() ? 1 : 0);
	cout << (check4() ? 1 : 0);
	cout << '\n';
	return 0;
}