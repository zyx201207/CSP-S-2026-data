#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	bool f = true;
	for (int i = 0;i < b.size() - 1;i++)
	{
		if (b[i] != d[i])
		{
			cout << "000";
			return 0;
		}
	}
	if (f)
	{
		cout << 1;
		if ((b[b.size() - 1] <= 'C' and b[b.size() - 1] >= 'A' and d[d.size() - 1] <= 'C' and d[d.size() - 1] >= 'A') or (b[b.size() - 1] == 'D' and d[d.size() - 1] == 'F') or (b[b.size() - 1] == 'F' and d[d.size() - 1] == 'D'))
		{
			cout << 1;
		}
		else
		{
			cout << "00";
			return 0;
		}
	}
	if ((abs(b[b.size() - 1] - d[d.size() - 1]) <= 1) or ((b[b.size() - 1] == 'D' and d[d.size() - 1] == 'F') or (b[b.size() - 1] == 'F' and d[d.size() - 1] == 'D')))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
