#include<bits/stdc++.h>
using namespace std;
int n, m, a[5010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int b;
	b = n - 1;
	int s = 0, d = 0;
	while(b--)
	{
		for(int i = n - b; i <= n; i++)
		{
			bool flag = true;
			for(int j = i + 1; j <= n; j++)
			{
				if(a[i] != a[j])
				{
					s++;
					d++;
					flag = false;
					break;
				}
			}
			if(flag)
			{
				if(a[i] == 1)
				{
					s++;
				}
				else
				{
					d++;
				}
			}
		}
	}
	cout << s << " " << d;
	return 0;
}
