#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[525];
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m != 1)
	{
		for (int i = 1;i <= m;i++)
		{
			cout << "1" << " ";
		}
	}
	else
	{
		cout << n;
	}
	return 0;
}
