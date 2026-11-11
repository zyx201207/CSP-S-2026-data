#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 10;

string c1, c2, s1, s2;
bool a, b, c, d;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) a = 1;
	if (a && s1[0] == s2[0] && s1[1] == s2[1]) b = 1;
	if (b && (s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) c = 1;
	if (c && abs(s1[2] - s2[2]) == 1) d = 1;

	cout << a << b << c << d << endl;
	return 0;
}

// 不要有压力，你去年已经拿过 J 1= 了
// 加油冲 AK
// 我相信你 Cute_zsz ！！！
// RP ++ ！！！！！

// 7min

