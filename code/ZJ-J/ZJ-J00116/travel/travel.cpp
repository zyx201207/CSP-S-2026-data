#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1 = getchar(),c2 = getchar(); getchar();
	char c3 = getchar(),c4 = getchar(),c5 = getchar();
	getchar();
	char c6 = getchar(),c7 = getchar(); getchar();
	char c8 = getchar(),c9 = getchar(),c0 = getchar();
	getchar();
	int n = (c1-'0')*10+(c2-'0'),m = (c6-'0')*10+(c7-'0');
	int x = (c3-'0')*10+(c4-'0'),y = (c8-'0')*10+(c9-'0');
	if(n == m)
	{
		cout << "1";
		if(x == y)
		{
			cout << "1";
			if((c5 == 'D' || c5 == 'F') && (c0 == 'D' || c0 == 'F'))
			{
				cout << "11\n";
			}
			else if((c5 == 'A' || c5 == 'B' || c5 == 'C') && (c0 == 'A' || c0 == 'B' || c0 == 'C'))
			{
				cout << "1";
				if((c5 == 'A' && c0 == 'C') || (c0 == 'A' && c5 == 'C'))
				{
					cout << "0\n";
				}
				else
				{
					cout << "1\n";
				}
			}
			else
			{
				cout << "00\n";
			}
		}
		else
		{
			cout << "000\n";
		}
	}
	else
	{
		cout << "0000\n";
	}
	return 0;
}//travel
