#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

string s, s1, s2, s3;

int flag, a, b, mx = INT_MIN, mi = INT_MAX;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s >> s1 >> s2 >> s3;
	if (s == s2) {
		flag = 1;
		if (s1[0] + s1[1] == s3[0] + s3[1]) {
			flag = 2;
			if ((s1[2] <= 'C' && s3[2] <= 'C') || (s1[2] >= 'D' && s3[2] >= 'D')) {
				flag = 3;
				a = s1[2], b = s3[2];
				mx = max(a, b), mi = min(a, b);
				if (mx - mi == 1)
					flag = 4;
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (flag) {
			cout << 1;
			flag--;
		} else
			cout << 0;
	}
	//cout << '\n' << a << ' ' << b << ' ' << mx << ' ' << mi << ' ' << flag;

	return 0;
}
