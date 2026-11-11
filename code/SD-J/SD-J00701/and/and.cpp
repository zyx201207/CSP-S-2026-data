#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200001];
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (m==1)
	{
		int maxn=-1;
		for (int i=1;i<=n;i++)
		{
			if (a[i]>maxn)
			{
				maxn=a[i];
			}
		}
		cout << maxn;
	}
	else if (m==n)
	{
		for (int i=2;i<=n;i++)
		{
			a[i]=(a[i]&a[i-1]);
		}
		cout << a[n];
	}
}
