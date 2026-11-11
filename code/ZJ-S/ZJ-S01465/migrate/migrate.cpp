#include <bits/stdc++.h>
using namespace std;

struct bird
{
	int b,e;
};

bird land[500005];
int a[100005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
			land[i].b = 1;
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i;j <= n;j++)
			{
				if(a[j] - a[i] <= d)
					land[i].e = j;
				else
				{
					land[j-1].b = i;
					break;
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				int x = i,y = j;
				while(a[x] + d < a[y] - d)
				{
					x++;
					y--;
				}
				if(land[x].e - land[y].b + 1 == 2)
					ans++;
			}
		}
		cout << ans + 1 << '\n';
	}
	return 0;
}
