#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,b;
	cin >> n >> a >> m >> b;
	if (n == m)
	{
		cout << 1;
		if (a[0] == b[0] && a[1] == b[1])
		{
			cout << 1;
			if(int(a[2]) - int(b[2]) == 1 || int(b[2]) - int(a[2]) == 1 || int(a[2]) - int(b[2]) == 2 || int(b[2]) - int(a[2]) == 2 )
			{
				if (a[2] == 'C' && b[2] == 'D' || b[2] == 'C' && a[2] == 'D')
				{
					cout << 0 << 0;
				}
				else 
				{
					cout << 1;
					if (int(a[2]) - int(b[2]) == 1 || int(b[2]) - int(a[2]) == 1)
					{
						cout << 1;
					}
					else cout << 0;
				}
			}
			else cout << 0;
		}
		else cout << 0 << 0 << 0;
	}
	else cout << 0 << 0 << 0 << 0;
	return 0;
}
