#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200010] = {};
	for(int i =1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int max = 0;
	int z=0;
	for(int i = 1;i <= m;i++)
	{
		int max = 0;
		for(int j = 1;j <= n;j++)
	 	{
			if(a[i] > max)
			{
				max = a[i];
				z= i;
			}
		}
	}
	a[z] = 0;
	cout << max << endl;
	num = num &max;
	cout << num;
	return 0;
}
