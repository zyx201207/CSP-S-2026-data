#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string c1, s1, c2, s2;

string solve() {
	string result(4, '0');
	if (c1 != c2) {
		return result;
	}
	result[0] = '1';
	
	if (s1[0] != s2[0] || s1[1] != s2[1]) {
		return result;
	}
	result[1] = '1';
	
	if (s1[2] >= 'D' && s2[2] < 'D' || s1[2] < 'D' && s2[2] >= 'D') {
		return result;
	}
	result[2] = '1';
	
	if (abs(s1[2] - s2[2]) != 1) {
		return result;
	}
	result[3] = '1';
	return result;
}

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	cout << solve() << endl;
	
	return 0;
} 
