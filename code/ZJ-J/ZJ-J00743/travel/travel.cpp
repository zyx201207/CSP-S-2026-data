#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool f(char a, char b){
	if (a <= 'C' && b <= 'C') return true;
	if (a >= 'D' && b >= 'D') return true;
	return false;
}
bool g(char a, char b){
	if (a-b == 1) return true;
	if (b-a == 1) return true;
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && f(s1[2], s2[2])) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && f(s1[2], s2[2]) && g(s1[2], s2[2])) cout << 1;
	else cout << 0;
	cout << endl;
	return 0;
}