#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;

vector<int>a;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1])
		a.push_back(1);
	else
		a.push_back(0);
	if (c1[0] == c2[0] && c1[1] == c2[1] && s1[0] == s2[0] && s1[1] == s2[1])
		a.push_back(1);
	else
		a.push_back(0);
	if (c1[0] == c2[0] && c1[1] == c2[1] && s1[0] == s2[0] && s1[1] == s2[1] && s1[2] <= 67 && s2[2] <= 67)
		a.push_back(1);
	else if (c1[0] == c2[0] && c1[1] == c2[1] && s1[0] == s2[0] && s1[1] == s2[1] && s1[2] + s2[2] == 138)
		a.push_back(1);
	else
		a.push_back(0);
	if (c1[0] == c2[0] && c1[1] == c2[1] && s1[0] == s2[0] && s1[1] == s2[1] && s1[2] <= 67 && s2[2] <= 67
	        && s1[2] + 1 == s2[2] )
		a.push_back(1);
	else if (c1[0] == c2[0] && c1[1] == c2[1] && s1[0] == s2[0] && s1[1] == s2[1] && s1[2] <= 67 && s2[2] <= 67
	         && s1[2] == s2[2] + 1)
		a.push_back(1);
	else if (c1[0] == c2[0] && c1[1] == c2[1] && s1[0] == s2[0] && s1[1] == s2[1] && s1[2] + s2[2] == 138)
		a.push_back(1);
	else
		a.push_back(0);
	for (int i = 0; i < 4; i++) {
		cout << a[i];
	}


	return 0;
}