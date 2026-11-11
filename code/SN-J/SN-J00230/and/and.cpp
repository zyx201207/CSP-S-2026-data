#include<bits/stdc++.h>
using namespace std;
int n, m, sum = 0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int a[n], b[m];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for(int j = 1; j <= m; j++)
		{
			if(a[i] >= a[i - 1])
			{
				b[j] = a[i];
			}
		}
	}	
	for(int i = 1; i <= m; i++)
	{
		b[i] &= b[i + 1];
		sum += b[i + 1];
	}
	cout << sum;
	return 0;
}
