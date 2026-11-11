#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],t[500005],s,cnt[500005],ss;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] >= a[i - 1])
		{
			ss++;
		}
	}
	if(ss == n)
	{
		for(int i = 1;i <= n;i++)
		{
			b[a[i]] = i;
		}
		for(int i = 1;i <= m;i++)
		{
			cout << b[i] << " ";
		}
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		memset(t,0,sizeof t);
		s = 0;
		for(int j = i;j <= n;j++)
		{
			if(!t[a[j]])
			{
				b[++s] = a[j];
				t[a[j]] = s;
			}
			else
			{
				for(int k = t[a[j]] + 1;k <= s;k++)
				{
					t[b[k]] = 0;
				}
				s = t[a[j]];
				b[s] = a[j];
				t[a[j]] = s;
			}
		}
		for(int i = 1;i <= s;i++)
		{
			cnt[b[i]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
