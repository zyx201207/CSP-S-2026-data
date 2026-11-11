#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	const set <char> st1{'A', 'B', 'C'}, st2{'D', 'F'};
	const auto f1 = c1 == c2, f2 = (s1.substr(0, 2) == s2.substr(0, 2)), f3 = (st1.count(s1.back()) && st1.count(s2.back()) ||
               st2.count(s1.back()) && st2.count(s2.back())), f4 = (abs(*st1.find(s1.back()) - *st1.find(s2.back())) == 1 ||
               abs(*st2.find(s1.back()) - *st2.find(s2.back())) == 1);
	cout << f1 << (f1 && f2) << (f1 && f2 && f3) << (f1 && f2 && f3 && f4) << '\n';
	return 0;
}
