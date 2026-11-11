#include <bits/stdc++.h>
using namespace std;
#define IOS cin.tie(nullptr) -> sync_with_stdio(false)
string c1, s1, c2, s2;
int main() { IOS;
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000";
	} else {
		if(s1.substr(0, 2) != s2.substr(0, 2)) cout << "1000";
		else {
			if((s1.back() <= 'C' && s2.back() > 'C') || (s1.back() > 'C' && s2.back() <= 'C')) cout << "1100";
			else {
				if(s1.back() != s2.back() + 1 && s2.back() != s1.back() + 1) cout << "1110";
				else cout << "1111";
			}
		}
	}
	return 0;
}