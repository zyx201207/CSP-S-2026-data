#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2; char ch1, ch2;
	cin >> c1 >> s1 >> ch1 >> c2 >> s2 >> ch2;
	ch1 = (ch1 == 'D' ? 'E' : ch1); ch2 = (ch2 == 'D' ? 'E' : ch2);
	cout << (c1 == c2);
	cout << (c1 == c2 && s1 == s2);
	cout << (c1 == c2 && s1 == s2 && ((ch1 > 'C' && ch2 > 'C') || (ch1 <= 'C' && ch2 <= 'C')));
	cout << (c1 == c2 && s1 == s2 && ((ch1 > 'C' && ch2 > 'C') || (ch1 <= 'C' && ch2 <= 'C')) && abs(ch1 - ch2) == 1);
	return 0;
}
