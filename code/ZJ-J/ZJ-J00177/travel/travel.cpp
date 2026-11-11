//CCF ±£””Œ“ AC£°£° 
#include <bits/stdc++.h>
using namespace std;

string c1;

string s1;

string c2;

string s2;

string ans = "";

int main ()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2)
	{
		ans += "1";

		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			ans += "1";

			if (s1[2] == 'A')
			{
				if (s2[2] == 'B' || s2[2] == 'C')
				{
					ans += "1";

					if (s2[2] == 'B')
					{
						ans += "1";
					}
					else
					{
						ans += "0";
					}
				}
				else
				{
					ans += "00";
				}
			}
			else if (s1[2] == 'B')
			{
				if (s2[2] == 'A' || s2[2] == 'C')
				{
					ans += "11";
				}
				else
				{
					ans += "00";
				}
			}
			else if (s1[2] == 'C')
			{
				if (s2[2] == 'B' || s2[2] == 'A')
				{
					ans += "1";

					if (s2[2] == 'B')
					{
						ans += "1";
					}
					else
					{
						ans += "0";
					}
				}
				else
				{
					ans += "00";
				}
			}
			else if (s1[2] == 'D')
			{
				if (s2[2] == 'F')
				{
					ans += "11";
				}
				else
				{
					ans += "00";
				}
			}
			else if (s1[2] == 'F')
			{
				if (s2[2] == 'D')
				{
					ans += "11";
				}
				else
				{
					ans += "00";
				}
			}
		}
		else
		{
			ans += "000";
		}
	}
	else
	{
		ans += "0000";
	}
	
	cout << ans << "\n";

	return 0;
}
