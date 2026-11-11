#include<bits/stdc++.h>
using namespace std;
long long a[2000222];
long long p[2000222];
long long k[2000222];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long C,T; cin >> C >> T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		long long n,m,ans = 0; cin >> n >> m;
		for(long long i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+1+n); long long id = n;
		for(long long i = n;i >= 1;i--)
		{
			while(a[id]-a[i] > m && id >= 1)
			{
				id--;
			}
			p[i] = id;
		}
		id = 1; p[n+1] = LLONG_MAX;
		for(long long i = 1;i <= n;i++)
		{
			while(p[id] <= p[i])
			{
				id++;
			}
			k[i] = id;
		}
		for(long long i = 1;i <= n-2;i++)
		{
			ans += (k[i]-i)*(p[p[i]-1]-p[p[i]-2]);
		}
		cout << ans << "\n";
	}
	return 0;
}//migrate
