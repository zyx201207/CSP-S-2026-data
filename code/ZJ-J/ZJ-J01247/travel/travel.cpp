#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool f1, f2, f3, f4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (s1 > s2) swap(s1, s2);
	
	if (c1 == c2) f1 = 1;
	else {
		cout << "0000\n";
		return 0;
	}
	
	if (s1[0] == s2[0] && s1[1] == s2[1]) f2 = 1;
	else {
		cout << "1000\n";
		return 0;
	}
	
	if (s1[2] >= 'D' && s2[2] >= 'D') f3 = 1, f4 = 1;
	else if (s1[2] <= 'C' && s2[2] <= 'C') f3 = 1;
	
	if (s1[2] == s2[2] - 1 && s1[2] != 'C') f4 = 1;
	
	cout << f1 << f2 << f3 << f4;
}