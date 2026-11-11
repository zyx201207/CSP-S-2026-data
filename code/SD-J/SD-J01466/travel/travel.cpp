#include<bits/stdc++.h>
#define endl '\n'
#define udmap unordered_map
#define udset unordered_set
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;

int c1, c2;
string s1, s2;

bool check1(string s) {
	return s[2] >= 'D';
}
bool check(string x, string y) {
	char xx = x[2], yy = y[2];
	if(xx > yy) {
		swap(xx, yy);
	}
	int a = abs(xx - yy);
	if(a == 1 && xx != 'C') return true;
	if(xx == 'D' && yy == 'F') return true;
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2) << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]);
	cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check1(s1) == check1(s2));
	cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check(s1, s2));
	return 0;
}

