#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, t;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		t += "1";
	}
	else
	{
		t += "0";
	}
	if (t == "1" and s1.substr(0, 2) == s2.substr(0, 2))
	{
		t += "1";
	}
	else
	{
		t += "0";
	}
	if (t == "11" and (s1.substr(2) == "A" or s1.substr(2) == "B" or s1.substr(2) == "C") and (s2.substr(2) == "A" or s2.substr(2) == "B" or s2.substr(2) == "C"))
	{
		t += "1";
		string a = s1.substr(2), b = s2.substr(2); 
		if ((a == "A" and b == "B") or (a == "B" and b == "C") or (b == "A" and a == "B") or (b == "B" and a == "C"))
		{
			t += "1";
		}
		else
		{
			t += "0";
		}
	}
	else if (t == "11" and (s1.substr(2) == "D" or s1.substr(2) == "F") and (s2.substr(2) == "D" or s2.substr(2) == "F"))
	{
		t += "11";
	}
	else
	{
		t += "00";
	}
	cout << t;
	return 0;
}
