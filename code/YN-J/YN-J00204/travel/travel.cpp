#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1;
string s1, c1, s2, c2, ans = "0000";
int a[1000];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	a['D'] = a['F'] = 1;
	cin >> s1 >> c1 >> s2 >> c2;
	if (s1 == s2) {
		ans[0] = '1';
		if (c1[0] * 10 + c1[1] == c2[0] * 10 + c2[1]) {
			ans[1] = '1';
			if (a[c1[2]] == a[c2[2]]) {
				ans[2] = '1';
				if (abs(c1[2] - c2[2]) == 1 || c1[2] == 'F' || c1[2] == 'F') {
					ans[3] = '1';
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}