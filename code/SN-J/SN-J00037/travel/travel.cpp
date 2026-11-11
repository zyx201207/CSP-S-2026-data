#include <bits/stdc++.h>
using namespace std;
#define int long long

string c,s,cc,ss;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c >> s >> cc >> ss;
	
	if (c == cc)
	{
		cout << 1;
		if (s.substr(0,2) == ss.substr(0,2))
		{
			cout << 1;
			if ((s.substr(2) <= "C" and ss.substr(2) <= "C") or (s.substr(2) > "C" and ss.substr(2) > "C"))	
			{
				cout << 1;
				if (abs(char(s[2]) - char(ss[2])) == 1)
					cout << 1;
				else
					cout << 0;
			}
			else
				cout << "00";
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	return 0;
} 
