#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200005];
int b[200005];

bool cmp(int x,int y)
{
	return x > y;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for(int k = 40;k >= 0;k--)
	{
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			if((a[i] >> k) & 1)
			{
				b[++cnt] = a[i];
			}
		}
		if(cnt >= m)
		{
			memset(a,0,sizeof a);
			for(int i = 1;i <= cnt;i++)
			{
				a[i] = b[i];
			}
			sort(a + 1,a + cnt + 1,cmp);
			n = cnt;
		}
	}
	int ans = a[1];
	for(int i = 1;i <= m;i++)
	{
		ans = (ans & a[i]);
	}
	cout << ans;
	return 0;
}