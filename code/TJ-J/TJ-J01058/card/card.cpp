#include <iostream>
using namespace std;

int a[200200], cnt[200200];
int b[200200];
int flag[200200];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int cur = 1;
		for (int j = i; j <= n; j++)
		{
			for(int k = 1; i <= cur; k++)
			{
				if(b[k] == a[j])
				{
					cur = k;
					break;
				}
			}
			b[cur] = a[j];
		}
		for (int j = 1; j <= cur; j++)
		{
			if(flag[b[j]] != i)cnt[b[j]]++;
			flag[b[j]] = i;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		cout << cnt[x] <<" ";
	}
	return 0; 
}
