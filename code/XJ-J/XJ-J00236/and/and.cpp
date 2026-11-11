#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c,d=1;
	cin >> n >> m;
	int a[n],b[m];
	
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	for (int i=1;i<=n;i++)
	{
		c=a[i];
		while(c)
		{
			if (c%2==1)
			{
				break;
			}
		}
		b[d]=a[i];
		d++;
	}
	
	int sum=b[1];
	for (int i=2;i<=m;i++)
	{
		sum=sum&b[i];
	}
	cout << sum;
}
