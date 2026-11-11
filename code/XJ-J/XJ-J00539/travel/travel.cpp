#include <bits/stdc++.h>
#include <string>
using namespace std;

int r , x;
string ar,ax;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r >> ar >> x >> ax;
	if(r == x)
	{
		cout << 1;
		if(ar[1] == ax[1])
		{
			if(ar[2] = ar[2])
			{
				cout << 1;
				if(ax[3] == ar[3])cout << 1;
				else cout << 0;
			}
			else cout << 00;
		}
		else cout << 000;
	}
	else cout << 0000;
	return 0;
}