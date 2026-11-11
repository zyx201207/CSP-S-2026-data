#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		int num = a[2] - a[1];
		bool f = 1;
		for(int i = 2;i <= n;i++)
			if(a[i] - a[i - 1] != num)
				f = 0;
		if(f)
		{
			int x = (a[n] - a[1]) / d;
			if((a[n] - a[1]) % d)
				x++;
			int s = a[1];
			int j = 2,ans = 0;
			for(int i = 1;i <= x;i++)
			{
				s += d;
				while(a[j] <= s)
				{
					if(((a[j] - a[1]) % d) % num == 0)
					{
						ans++;
						ans += (a[n] - a[j]) / num;
					}
					j++;
				}
			}
			cout << ans << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}
	return 0;
}
