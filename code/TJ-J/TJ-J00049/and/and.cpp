#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0;
	cin>>n>>m;
	int a[n];
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a, a+n, cmp);
	for(int i = 1;i<=m;i++)
	{
		for(int j = n;j>=1;j--)
		{
			ans = a[j] and a[j-1];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
