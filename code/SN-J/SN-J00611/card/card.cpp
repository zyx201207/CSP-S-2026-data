#include <bits/stdc++.h>
#define int long long
#define S "card"
#define FI freopen(S".in","r",stdin);
#define FO freopen(S".out","w",stdout);
using namespace std;

const int N = 5e5+10,M = 3e5+10;
int n,m,a[N],ans[N];
signed main()
{
	FI;FO;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n <= 5000)
	{
		for (int i = 1;i <= m;i++)
		{
			deque<int> q;
			int last=0;
			vector<bool> cnt(n+3,0);
			for (int j = m;j <= n;j++)
			{
				if (cnt[a[j]]==0) 
				{
					cnt[a[j]]=1;
					q.push_back(a[j]);
					last=j;
				}
				else 
				{
					for (int k = 1;k <= j-last+1;k++) q.pop_front();
					last=j;
					cnt[a[j]] = 0;
				}
			}
			int viss[N];
			memset(viss,0,sizeof(viss));
			for (auto j : q)
			{
				if (viss[a[j]]== 0 )
				{
					ans[a[j]]++;
					viss[a[j]] =1;
				}
			}
		}
		for (int i = 1;i <= m;i++)
		{
			cout << ans[i] << " ";
		}
		
	}
	return 0;
}

