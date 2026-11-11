#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string sa, sb, ca, cb;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> ca >> sa >> cb >> sb;
	bool ans1, ans2, ans3, ans4;
	ans1 = (ca == cb);
	ans2 = ans1 && (sa[0] == sb[0] && sa[1] == sb[1]);
	char a = sa[2], b = sb[2];
	if (a > b) swap(a, b);
	ans3 = ans2 && ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'A' && b == 'C') || (a == 'D' && b == 'F'));
	ans4 = ans2 && ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F'));
	cout << ans1 << ans2 << ans3 << ans4 << "\n";
	return 0;
}

