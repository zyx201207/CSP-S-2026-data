#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c_1, s_1, c_2, s_2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if (c_1 == c_2) {
		cout << 1;
		if (s_1[0] == s_2[0] && s_1[1] == s_2[1]) {
			cout << 1;
			ll v_1 = s_1[2] - 'A', v_2 = s_2[2] - 'A';
			if (v_1 == 5) v_1 --;
			if (v_2 == 5) v_2 --;
			if ((v_1 <= 2 && v_2 <= 2) || (v_1 > 2 && v_2 > 2)) {
				cout << 1;
				v_1 -= v_2;
				if (v_1 == -1 || v_1 == 1) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
