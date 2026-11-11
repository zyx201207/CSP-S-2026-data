#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans[4];
	if (c1 == c2)
		ans[0] = true;
	else
	{
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1])
		ans[1] = 1;
	else
	{
		cout << "1000";
		return 0;
	}
	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))
		ans[2] = true;
	else
	{
		cout << "1100";
		return 0;
	}
	if (abs(s1[2] - s2[2]) == 1)
		cout << "1111";
	else
		cout << "1110";
	return 0;
}
