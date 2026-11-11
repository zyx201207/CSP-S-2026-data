#include <bits/stdc++.h>
using namespace std;
int c1, c2, side[128];
string s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	side['A'] = side['B'] = side['C'] = 0; 
	side['D'] = side['F'] = 1;
	if (c1 != c2) cout << "0000";
	else if (s1.substr(0, 2) != s2.substr(0, 2)) cout << "1000";
	else if (side[s1[2]] != side[s2[2]]) cout << "1100";
	else if (s1[2] == 'C' && s2[2] == 'A' || s1[2] == 'A' && s2[2] == 'C') cout << "1110";
	else cout << "1111";
	return 0;
}

