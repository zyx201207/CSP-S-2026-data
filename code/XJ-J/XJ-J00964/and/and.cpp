#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[100005];
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int num = a[1],sum=0;
	for (int i = 1;i <= n;i++)
	{
		if (a[i]==num)
		{
			num+=a[i];
		}
		else
		{
			num+=a[i];
			sum++;
		}
	}
	a[n+1]=num/sum;
	sort(a,a+n+2);
	for (int i = 1;i <= n+1;i++)
	{
		if (a[i]==num/sum)
		{
			if (a[i]-a[i-1]>a[i+1]-a[i])
			{
				cout << a[i+1];
				
			}
			else if (a[i]-a[i-1]<=a[i+1]-a[i])
			{
				cout << a[i-1];
				
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}