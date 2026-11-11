#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int w[300];
bool check (char x, char y){
	if (x == 'A' && y == 'B')  return 1;
	if (x == 'B' && y == 'C')  return 1;
	if (x == 'D' && y == 'F')  return 1;
}
int main(){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	w['A'] = w['B'] = w['C'] = 1;
	if (c1 != c2)  cout << "0000";
	else if (s1[0] != s2[0] || s1[1] != s2[1])  cout << "1000";
	else if (w[s1[2]] != w[s2[2]])  cout << "1100";
	else if (!check (min (s1[2], s2[2]), max (s1[2], s2[2])))  cout << "1110";
	else cout << "1111";
	return 0;
}
