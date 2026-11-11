#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char a[3], b[3], n[2], m[2];
	cin >> n >> a >> m >> b;
	if (n[0] == m[0] && n[1] == m[1])
	{
		cout << 1;
		if(a[0] == b[0] && a[1] == b[1])
		{
			cout << 1;
			if(a[2] == 'A' && b[2] == 'B')
			{
				cout << 11;
			} 
			else if(a[2] == 'B' && b[2] == 'A')
			{
				cout << 11;
			}
			else if(a[2] == 'B' && b[2] == 'C')
			{
				cout << 11;
			}
			else if(a[2] == 'C' && b[2] == 'B')
			{
				cout << 11;
			}
			else if(a[2] == 'D' && b[2] == 'F')
			{
				cout << 11;
			}
			else if(a[2] == 'F' && b[2] == 'D')
			{
				cout << 11;
			}
			else if(a[2] == 'A' && b[2] == 'C')
			{
				cout << 10;
			}
			else if(a[2] == 'C' && b[2] == 'A')
			{
				cout << 10;
			}
			else
			{
				cout << 0;
				cout << 0;
			}
		}
		else
		{
			cout << 0;
			cout << 0;
			cout << 0;
		}
	}
	else
	{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;		
	}
	return 0;
}
