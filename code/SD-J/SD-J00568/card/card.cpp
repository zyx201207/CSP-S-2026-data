#include <bits/stdc++.h>
using namespace std;
const int N= 5e5 + 5;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,m;
int a[N];
int ans[N];
int main()
{

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		ans[a[i]]++;
	}
	for (int i =1;i <= n;i++)
	{
		for (int k = 1;k <= n;k++)
		{
			int f = 1;
			for (int j = k;j < i;j++)
			{
				for (int l = i + 1;l <= n;l++)
				{
					if (a[j] == a[l] || a[j] == a[i] || a[l] == a[i])
					{
						f = 0;
					}
				}
			}
			if (k < i)
			{
				ans[a[i]] += f;	
			}
				
		}
		
	}
	for (int i = 1;i <= m;i++)
	{
		cout << min(ans[i],n) << ' ';
	}
	return 0;
}

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

