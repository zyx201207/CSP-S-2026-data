#include <bits/stdc++.h>
using namespace std;
int c1, c2, line1, line2, side1, side2;
string s1, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	line1 = s1[0] * 10 + s1[1];
	line2 = s2[0] * 10 + s2[1];
	if (line1 == line2) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') side1 = 1;
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') side2 = 1;
	if (side1 == side2) cout << "1";
	else{
		cout << "00";
		return 0;
	}
	if (side1 = 1){
		if (s1[2] == 'B' || s2[2] == 'B') cout << "1";
		else cout << "0";
	}
	else cout << "1";
	return 0;
} 
