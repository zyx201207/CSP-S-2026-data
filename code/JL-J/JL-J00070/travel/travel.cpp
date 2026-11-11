#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a, b, c, d;
	char ax, bx;
	cin >> a >> c >> ax >> b >> d >> bx;
	if(a == b)
	{
		cout << '1';
		if(c == d)
		{
			cout << '1';
			if((ax - 'A' <= 2 && bx - 'A' <= 2) || 
				(ax - 'A' > 2 && bx - 'A' > 2))
				{
					cout << '1';
					if((ax - 'A' - (bx - 'A') == 1) ||
						(bx - 'A' - (ax - 'A') == 1))
						cout << '1';
					else cout << '0';
				}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
}
