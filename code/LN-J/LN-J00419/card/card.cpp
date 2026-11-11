#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],ans[500005];
bool vis[500005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int g = 1;g <= n;g++)
	{
		int card[500005] = {},p = 0;
		for (int i = g;i <= n;i++)
		{
			if (vis[a[i]])
			{
				memset(card,0,sizeof card);
				memset(vis,0,sizeof vis);
				p = 0;
			}
			vis[a[i]] = 1;
			card[++p] = a[i];
		}
		for (int i = 1;i <= p;i++) ans[card[i]]++;
		memset(vis,0,sizeof vis);
		memset(card,0,sizeof card);
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}
