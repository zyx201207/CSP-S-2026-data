#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10000];
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]-a[5]>=a[i+10])
		{
			cout << (a[i+1]-a[i+190])%10;
		}
		else
		{
			cout << a[i]-a[i-1];
		}
	}
	return 0;
}
