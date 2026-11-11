#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string c1, s1, c2, s2;
ll a1, a2, a3, a4;
ll rc, rsr, rsc, xc, xsr, xsc;

ll to_ll(char c);
ll to_row(char c);

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	rc = to_ll(c1[0]) * 10 + to_ll(c1[1]);
	xc = to_ll(c2[0]) * 10 + to_ll(c2[1]);
	if(rc != xc)
	{
		a1 = 0;
		a2 = 0;
		a3 = 0;
		a4 = 0;
	}
	else
	{
		a1 = 1;
		rsr = to_ll(s1[0]) * 10 + to_ll(s1[1]);
		xsr = to_ll(s2[0]) * 10 + to_ll(s2[1]);
		rsc = to_row(s1[2]);
		xsc = to_row(s2[2]);
		if(rsr != xsr)
		{
			a2 = 0;
			a3 = 0;
			a4 = 0;
		}
		else
		{
			a2 = 1;
			if(rsc / 10 != xsc / 10)
			{
				a3 = 0;
				a4 = 0;
			}
			else
			{
				a3 = 1;
				if(ll(abs(rsc - xsc) == 1)) a4 = 1;
				else a4 = 0;
			}
		}
	}
	cout << a1 << a2 << a3 << a4;
	return 0;
}

ll to_ll(char c)
{
	return ll(c) - 48;
}

ll to_row(char c)
{
	if(c == 'A') return 11;
	if(c == 'B') return 12;
	if(c == 'C') return 13;
	if(c == 'D') return 21;
	if(c == 'F') return 22;
	return 0;
}
