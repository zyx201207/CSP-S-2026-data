#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1, s1, c2, s2;
string ans;
auto get (string s, ll idx) {
	if (idx == 1) {
		return s[0] + s[1];
	} else {
		return s[2] - 'A';
	}
}
bool check (ll a, ll b) {
	return (a <= 2 && b <= 2) || (3 <= a && 3 <= b);
}
void solve1 () {
	if (c1 == c2) ans += "1";
	else ans += "0";
}
void solve2 () {
	if (c1 == c2 &&
	    get (s1, 1) == get (s2, 1)) ans += "1";
	else ans += "0"; 
}
void solve3 () {
	if (c1 == c2 &&
	    get (s1, 1) == get (s2, 1) &&
		check (get (s1, 2), get (s2, 2))) ans += "1";
	else ans += "0"; 
}
void solve4 () {
	if (c1 == c2 &&
	    get (s1, 1) == get (s2, 1) && 
	    check (get (s1, 2), get (s2, 2)) &&
		abs (get (s1, 2) - get (s2, 2)) == 1) ans += "1";
	else ans += "0";
}
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	solve1 ();
	solve2 ();
	solve3 ();
	solve4 ();
	cout << ans;
	return 0;
}
