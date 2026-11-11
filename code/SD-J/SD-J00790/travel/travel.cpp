#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	string c,d;
	cin >> a >> c >> b >> d;
	if(a == b)
	{
		cout << 1;
		int cc = c[1] - '0' + (c[0] - '0') * 10;
		int dd = d[1] - '0' + (d[0] - '0') * 10;
		if(cc == dd)
		{
			cout << 1;
			if((c[2] < 'D' && d[2] < 'D') || (c[2] > 'C' && d[2] > 'C'))
			{
				cout << 1;
				if(c[2] + 1 == d[2] || d[2] + 1 == c[2])
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
