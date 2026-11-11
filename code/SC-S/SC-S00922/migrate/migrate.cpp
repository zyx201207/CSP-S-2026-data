#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000010];
int n, d;
struct ln
{
	int l, r;
}li[2000010];
int cnt[2000010];
bool vis[2000010];
signed main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		int j = 1;
		for(int i = 1;i <= n;i++)
		{
			cnt[i] = 0;
			vis[i] = 0;
			cin >> x[i];
			if(i == 1)
			{
				li[i].l = 1;
				continue;
			}
			while(j <= i && x[i] - x[j] > d)
			{
				j++;
			}
			if(j > i)
			{
				j--;
				li[i].l = i;
			}
			else
			{
				li[i].l = j;
			}
		}
		j = n;
		for(int i = n;i;i--)
		{
			if(i == n)
			{
				li[i].r = n;
				continue;
			}
			while(j >= i && x[j] - x[i] > d)
			{
				j--;
			}
			if(j < i)
			{
				j++;
				li[i].r = i;
			}
			else
			{
				li[i].r = j;
			}
		}
//		for(int i = 1;i <= n;i++)
//		{
//			cout << li[i].l << ' ' << li[i].r << '\n';
//		}
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(li[i].l == li[j].l && li[i].r == li[j].r)
				{
					continue;
				}
				if(li[i].l + 1 == li[j].r && li[j].l < li[i].r)
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
  x   y   z
a---b---c---e
x+y<=d
y+z<=d
d+1<=x+y+z

*/