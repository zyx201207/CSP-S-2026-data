#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int SIZE = 1e5 + 5, T = 816;
string c1, s1, c2, s2;
void _main() {
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if ( (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <='C') ||
				 (s1[2] == 'D' && s2[2] == 'F') ||
				 (s1[2] == 'F' && s2[2] == 'D') ){
				cout << 1;
				if ( abs(s1[2] - s2[2]) == 1 ||
				    (s1[2] == 'D' && s2[2] == 'F') ||
				    (s1[2] == 'F' && s2[2] == 'D') ){
					cout << 1;
				}
				else {
					cout << "0";
					return;
				}
			}
			else {
				cout << "00";
				return;
			}
		}
		else {
			cout << "000";
			return;
		}
	}
	else {
		cout << "0000";
		return;
	}
	return;
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	while (t --> (T^T)){
		_main();
	}
	return 0; 
}
