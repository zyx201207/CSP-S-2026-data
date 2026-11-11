#include <bits/stdc++.h>
using namespace std;
int a[500020];
int t[300020];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ts = n;
	for(int i =1; i <= n; i++)
	{
		int b[500020],tmp = 0;
		for(int j = 1; j <= ts; j++)
		{
			b[tmp+1] = a[j];
			tmp++;
			for(int k = 1; k <= tmp-1; k++)
			{
				if(a[j]==b[k])
				{
					tmp-=(tmp-k);
					break;
				}
			}
		}
		for(int j = 1; j <= ts; j++)
		{
			a[j] = a[j+1];
		}
		ts--;	
		for(int j = 1; j <= tmp; j++)
		{
			t[b[j]]++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << t[i] << " ";
	}
	return 0;
}
