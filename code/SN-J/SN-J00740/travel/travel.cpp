#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2, a = "", b = "";
int main()
{
	//bian bo yang 西安市第一中学 SN-J00740 
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool m, n;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	else
		cout << "1";
	for (int i = 0; i <= 1; i++)
	{
		a += s1[i];
		b += s2[i];
	}
	if (a == b)
	{
		n = true;
		cout << "1";
    }
	else
	{
		n = false;
		cout << "0";
	}
	char ss1 = s1[2];
	char ss2 = s2[2];
	m = ((s1[2] - 'C' < 0 && s2[2] - 'C' < 0) || (s1[2] - 'C' > 0 && s2[2] - 'C' > 0)) || ((s1[2] == 'C' && s2[2] < 'C') || (s2[2] == 'C' && s1[2] < 'C'));
	if (n && m)
		cout << "1";
	else
		cout << "0";
	bool o = (int)ss2 - ss1 == -1 || (int)ss2 - ss1 == 1;
	if ((n && m) && o)
		cout << "1";
	else
		cout << "0";
	return 0;
}
