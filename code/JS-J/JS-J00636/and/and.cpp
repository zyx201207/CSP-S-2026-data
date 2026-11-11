#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[5000];
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int c = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			c = max(c,a[i] & a[j]);
		}
	}
	cout << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
