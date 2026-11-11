#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool t;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	t = (c1 == c2);
	cout << t;
	t = (((s1[0] - '0') * 10 + s1[1] - '0' == (s2[0] - '0') * 10 + s2[1] - '0') && t);
	cout << t;
	t = (((s1[2] - 'A' < 3) && (s2[2] - 'A' < 3)) || ((s1[2] - 'A' > 2) && (s2[2] - 'A' > 2))) && t;
	cout << t;
	t = (((max(s1[2] - 'A', s2[2] - 'A') - min(s1[2] - 'A', s2[2] - 'A'))) == 1) && t;
	cout << t;
	return 0;
}