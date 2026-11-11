#include <bits/stdc++.h>
using namespace std;
map<pair<char, char>, bool> mp1;
map<pair<char, char>, bool> mp2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	mp1[{'A', 'B'}] = 1;
	mp1[{'B', 'A'}] = 1;
	mp1[{'A', 'C'}] = 1;
	mp1[{'B', 'C'}] = 1;
	mp1[{'C', 'B'}] = 1;
	mp1[{'C', 'A'}] = 1;
	mp1[{'D', 'F'}] = 1;
	mp1[{'F', 'D'}] = 1;
	mp2[{'A', 'B'}] = 1;
	mp2[{'B', 'A'}] = 1;
	mp2[{'C', 'B'}] = 1;
	mp2[{'B', 'C'}] = 1;
	mp2[{'D', 'F'}] = 1;
	mp2[{'F', 'D'}] = 1;
	bool f1, f2, f3, f4;
	if (c1 == c2) f1 = true;
	else f1 = false;
	if (f1 && s1[0] == s2[0] && s1[1] == s2[1]) f2 = true;
	else f2 = false;
	if (f2 && mp1[{s1[2], s2[2]}]) f3 = true;
	else f3 = false;
	if (f3 && mp2[{s1[2], s2[2]}]) f4 = true;
	else f4 = false;
	cout << f1 << f2 << f3 << f4;
	return 0;
}