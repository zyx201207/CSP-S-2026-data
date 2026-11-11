#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c3;
	char c2b,c4b;
	int c2a,c4a;
	cin >> c1 >> c2a >> c2b >> c3 >> c4a >> c4b;
//	cout << c2a << " " << c4a; 
	if (c1 == c3) cout << 1;
	else 
	{
		for (int i = 1;i <= 4;i++) cout << 0;
		return 0;
	}
	if (c2a == c4a) cout << 1;
	else 
	{
		for (int i = 1;i <= 3;i++) cout << 0;
		return 0;
	}
	if ((c2b < 'D' && c4b < 'D') || (c2b < 'F' && c2b > 'C' && c4b < 'F' && c4b > 'C'))
	{
		cout << 1;
	}
	else 
	{
		for (int i = 1;i <= 2;i++) cout << 0;
		return 0;
	}
	if (abs(c2b - c4b) == 1 && (!(c2b == 'C' && c4b == 'D') && !(c2b == 'D' && c4b == 'C')))
	{
		cout << 1;
	}
	else cout << 0;
	return 0;
}
