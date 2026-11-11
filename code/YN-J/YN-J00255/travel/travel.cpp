#include <bits/stdc++.h>
using namespace std;
#define ll long long
string c1, s1, c2, s2;
ll ans[5];

void Cout() {
	for (int i = 1; i <= 4; i++)
		cout << ans[i];
	exit(0);
}

ll pos(string s) {
	if (s == "D" || s == "F")
		return 1;
	else
		return 2;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		ans[1] = 1LL;
	else
		Cout();
	if (s1.substr(0, 2) == s2.substr(0, 2))
		ans[2] = 1LL;
	else
		Cout();
	if (pos(s1.substr(2, 1)) == pos(s2.substr(2, 1)))
		ans[3] = 1LL;
	else
		Cout();
	string sum1 = s1.substr(2, 1), sum2 = s2.substr(2, 1);
	if ((sum1 == "A" && sum2 == "B") || (sum1 == "B" && (sum2 == "A" || sum2 == "C")) || (sum1 == "C" && sum2 == "B"))
		ans[4] = 1LL;
	else if (sum1 == "D" && sum2 == "F" || sum1 == "F" && sum2 == "D")
		ans[4] = 1LL;
	Cout();
	return 0;
}