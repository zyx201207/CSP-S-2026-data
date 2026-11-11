#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	string c1, s1, c2, s2;
	bool q1, q2, q3, q4;
	int main()
	{
		freopen("travel.in", "r", stdin);
		freopen("travel.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> c1 >> s1 >> c2 >> s2;
		q1 = (c1 == c2);
		q2 = (q1 && (s1.substr(0, 2) == s2.substr(0, 2)));
		q3 = (q2 && (s1[2] <= 'C') == (s2[2] <= 'C'));
		q4 = (q3 && (abs(s1[2] - s2[2]) == 1));
		cout << (int)q1 << (int)q2 << (int)q3 << (int)q4 << '\n';
		return 0;
	}
}
int main()
{
	return Main::main();
}