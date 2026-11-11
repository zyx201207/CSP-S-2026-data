#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n , m , a[5005] , cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=m-1;i++)
	{
		for(int i=1;i<=m-i;i++)
		{
			if(a[j]==a[i])
			{
				cout << a[i] << " ";
			}
			if(a[j]>a[j-1])
			{
				sort(a[j],a[j-1]);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	return 0;
}
