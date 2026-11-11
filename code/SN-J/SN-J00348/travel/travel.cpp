#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
bool nxt = true;
void check(string a, string b)
{
	for (int i = 0; i < 2; i++)
	{
		if (a[i] != b[i])
		{
			cout << "0";
			nxt = false;
			return;
		}
	}
	cout << "1";
	return;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << "1";
		
		check(s1, s2);
		if (!nxt)
		{
			cout << "00";
			return 0;
		}
		
		int flag1 = -1, flag2 = -1;
		if ((s1[2] >= 'A') && (s1[2] <= 'C')) flag1 = 1;
		else if ((s1[2] == 'D') || (s1[2] == 'F')) flag1 = 2;
		if ((s2[2] >= 'A') && (s2[2] <= 'C')) flag2 = 1;
		else if ((s2[2] == 'D') || (s2[2] == 'F')) flag2 = 2;
		if (flag1 == flag2) cout << "1";
		else
		{
			cout << "00";
			return 0;
		}
		if ((s1[2] == 'C') && (s2[2] == 'D')) cout << "0";
		else if ((s1[2] == 'D') && (s2[2] == 'C')) cout << "0";
		else if ((s1[2] == 'D') && (s2[2] == 'F')) cout << "1";
		else if ((s1[2] == 'F') && (s2[2] == 'D')) cout << "1";
		else if ((s1[2] == 'A') && (s2[2] == 'B')) cout << "1";
		else if ((s1[2] == 'B') && (s2[2] == 'A')) cout << "1";
		else if ((s1[2] == 'B') && (s2[2] == 'C')) cout << "1";
		else if ((s1[2] == 'C') && (s2[2] == 'B')) cout << "1";
		else cout << "0";
	}
	return 0;
}
