#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5,L = 35;
int a[N];
int p[L];
void init()
{
	p[0] = 1;
	for(int i = 1;i < 30;i ++)
	{
		p[i] = p[i - 1] * 2;
	}
	return;
}
bool vis[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 29;i >= 0;i --)
	{
		int cnt = 0;
		for(int j = 1;j <= n;j ++)
		{
			if(vis[j]) continue;
			if((a[j] & p[i]) > 0)
			{
				cnt ++;
			}
		}
		if(cnt >= m)
		{
			ans += p[i];
			for(int j = 1;j <= n;j ++)
			{
				if(vis[j]) continue;
				if((a[j] & p[i]) == 0) vis[j] = 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
