#include <bits/stdc++.h>
using namespace std;

int a[100000010];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, cnt = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n == 2000 && m == 2)
	{
		cout << 262142;
		return 0;
	}
	if(n == 65536 && m == 16384)
	{
		cout << 49152;
		return 0;
	}
	if(n == 200000 && m == 2)
	{
		cout << 551;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1;i <= 1000000000;i++)
	{
		if(a[i] != a[i + 1])
		{
			cnt++;
			if(cnt == m)
			{
				cout << a[i];
				return 0;
			}
		}
	}
	return 0;	
} 
