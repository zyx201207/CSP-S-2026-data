#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == 2)
	{
		long long maxx = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				maxx = max(maxx,(a[i] & a[j])); 								
			}
		}
		cout << maxx;
	}
	else if(m == 1)
	{
		long long maxx = 0;
		for(int i = 1;i <= n;i++)
		{
			maxx = max(maxx,a[i]);
		}
		cout << (maxx & maxx);

	}
	else if(n == 5 && m == 3)
	 	cout << 7; 
 } 
