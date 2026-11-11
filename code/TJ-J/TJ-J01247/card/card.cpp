#include <bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n,m,e = 0;
	long long s[100000];
	long long sum[100000];
	cin >> n >> m;
	for(long long i = 0;i <= n;i++)
	{
		cin >> s[i];
		if(i != 0)
		{
			for(long long j = e;j < i;j++)
			{
				if(s[j] == s[i])
				{
					e = i;
				}
			}
			for(long long j = e;j < i;j++)
			{
				for(long long k = 1;k <= m;k++) 
				{
					if(s[j] == k)
					{
						sum[k]++;
					}
				}
			} 
		}
	}
	for(long long j = 1;j <= m;j++)
	{
		cout << sum[j] << " ";
	}
	return 0;
} 
