#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[1000007],s[1000007],cnt[1000007],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				cnt[j] = 0;
				s[j] = -1;
			}
			cnt[i] = 1;
			s[i] = 0;
			for(int j = i;j <= n;j++)
			{
				if(cnt[j] > 2)break;
				for(int k = j+1;k <= n;k++)
				{
					if(a[k]-a[j] > m)break;
					if(s[k] == -1)s[k] = s[j]+1;
					if(s[j]+1==s[k])cnt[k] += cnt[j];
				}
			}
			for(int j = i;j <= n;j++)
			{
				if(cnt[j] == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}
