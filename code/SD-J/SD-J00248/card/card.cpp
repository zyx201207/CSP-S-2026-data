#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],num[300001];
bool b[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		for(long long j = i;j <= n;j++)
		{
			if(b[a[j]] == false)
			{
				b[a[j]] = true;
			}
			else 
			{
				for(long long k = i;k <= j-1;k++)
				{
					b[k] = false;
				}
				b[a[j]] = true;
			}
		}
		for(int j = 1;j <= m;j++)
		{
			if(b[j] == true)
			{
				num[j]++;
				b[j] = false;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << num[i] << " ";
	}
	return 0;
}
