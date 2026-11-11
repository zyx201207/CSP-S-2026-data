#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c,t;
long long d;
long long L[N];
int a[N];
bool vis[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i=1;i<=t;i++)
	{
		memset(a,0,sizeof(a));
		int n;
		cin >> n >> d;
		int now = 1;
		cin >> L[1];
		for (int i=2;i<=n;i++)
		{
			cin >> L[i];
			while(L[i] - L[now] >= d && now < i)
			{
				if (L[i] - L[now] == d)
				{
					a[i]++;
					vis[now] = 1;
				}
				else
				{
					a[i-1]++;	
				}
				now++;
			}
		}
		long long ans = 0;
		for (int i=1;i<=n;i++)
		{
			if (vis[i])
			{
				ans += a[i+1];
			}
		}
		cout << ans << endl;
	}
}
