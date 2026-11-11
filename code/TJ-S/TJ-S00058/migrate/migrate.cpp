#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d,cnt = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		int m = a[2]-a[1];
		while(d%m != 0)
		{
			d--;
		}
		for(int i = 1;i <= n;i++)
		{
			int sum = 0;
			int x = d/m;
			for(int j = a[i]+d;j <= n;j++)
			{
				if(j%d == a[i])
				{
					sum++;
				}
			}
			cnt += n-x-sum;
		}
		cout << cnt << endl;
	}
	return 0;
}
