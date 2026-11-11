#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],cnt,ans,b[200005][35];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		int aa = a[i],s = 0;
		while(aa)
		{
			b[i][++s] = aa % 2;
			aa /= 2;
		}
		cnt = max(cnt,s);
	}
	for(int i = cnt;i >= 1;i--)
	{
		int s = 0;
		for(int j = 1;j <= n;j++)
		{
			s += b[j][i];
		}
		if(s >= m)
		{
			int ss = 0;
			for(int j = 1;j <= n;j++)
			{
				if(!b[j][i])
				{
					ss++;
				}
				else
				{
					for(int k = 1;k <= cnt;k++)
					{
						b[j - ss][k] = b[j][k];
					}
				}
			}
			ans += pow(2,i - 1);
			n -= ss;
		}
		if(n < m)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}
