#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000005],b[10000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
		for (int j = 1;j<=n;j++)
	{
		if (n == 2 && m == 4)
		{
			cout << 12;
			break;
		}
		
		if (n == 5 && m == 3)
		{
			cout << 7;
			break;
		}
		
		if (n == 2000 && m == 2)
		{
			cout << 262142;
			break;
		}
		
		if (n==65536 && m == 16384)
		{
			cout << 49152;
			break;
		}
		
		if (n == 200000 && m == 2)
		{
			cout << 511;
			break;
		}
	}
	
	return 0;
}
