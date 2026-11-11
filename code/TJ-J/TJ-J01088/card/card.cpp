#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int t=a[1];
	for (int i=1;i<=n;i++)
	{
		if(a[i]!=t)
		{
			cout << i-1;
			t = a[i];
			if(i==n)
			{
				cout << i;
				break;
			}
		}
		else continue;
		
	}
	
	
	return 0;
}
