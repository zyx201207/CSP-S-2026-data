#include <bits/stdc++.h>
#define debug puts("OK")
using namespace std;

struct ticket
{
	int t, l, p, lr;
} r, x;

string s;

int main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> r.t;
	cin >> s;
	r.l = s[0] * 10 + s[1];
	r.p = s[2] - 'A';
	r.lr = r.p <= 2;
	
	cin >> x.t;
	cin >> s;
	x.l = s[0] * 10 + s[1];
	x.p = s[2] - 'A';
	x.lr = x.p <= 2;
	
	if (r.t == x.t)
	{
		cout << 1;
		if (r.l == x.l)
		{
			cout << 1;
			if (r.lr == x.lr)
			{
				cout << 1;
				debug;
				if (abs(r.p - x.p) == 1) cout << 1;	
				else cout << 0;
			}
			else cout << "00";	
		}
		else cout << "000";	
	}
	else cout << "0000";
	return 0;
}

