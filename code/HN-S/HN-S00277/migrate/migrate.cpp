#include<bits/stdc++.h>
using namespace std;
int c;
int t;
long long a[2000010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c;
	if(c == 11 || c == 12)
	{
		cin >> t;
		while(t--)
		{
			long long n , d;
			cin >> n >> d;
			for(int i = 1;i <= n;++i)
			{
				cin >> a[i];
			}
			long long cha = a[2]-a[1];
			if(d < 2*cha)
			{
				cout << 0 << '\n';
				continue;
			}
			long long duan = (d-(d%cha))/cha;
			long long x = duan+2;
			long long ans = n - x + 1;
//			cout << cha << '\n';
			if(ans < 0)ans = 0;
			cout << ans << '\n';
		}
	}
	else
	{
		cin >> t;
		while(t--)
		{
			int n;
			cin >> n;
		}
	}
	
	return 0;
}
/*
11 1
7 5
0 2 4 6 8 10 12
*/
