#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	int s1 = 0,s2 = 0;
	for (int i = 1;i<=n;i++)
	{
		if (a[i] > s1)
		{
			s1 = a[i];
		}
	}
	for (int i = 1;i<=n;i++)
	{
		if (a[i] > s2 && a[i] < s1)
		{
			s2 = a[i];
		}
	}
	cout << s2;
	return 0;
}
