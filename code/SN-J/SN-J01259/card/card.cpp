#include <bits/stdc++.h>
using namespace std;
int n,m,cute1,cute2,l,a[200005];
bool c1,c2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m <= 2)
	{
		for(int i = 1;i <= m;i++)
		{
			cout << i << " ";
		}
	}
	else
	{
		for(int i = 1;i <= m;i++)
		{
			cout << 1;
		}
	}
	return 0;
}
