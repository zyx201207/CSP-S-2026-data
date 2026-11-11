#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[300010],sk[500010],top;
bool vis[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		memset(vis,false,sizeof(vis));
		top = 0;
		for(int j = i;j <= n;j++)
		{
			for(int k = 1;k <= top;k++)
			{
				if(sk[k] == a[j])
				{
					top = k - 1;
					break;
				}
			}
			sk[++top] = a[j];
		}
		for(int j = 1;j <= top;j++) vis[sk[j]] = true;
		for(int j = 1;j <= m;j++) cnt[j] += vis[j];
	}
	for(int i = 1;i <= m;i++) cout << cnt[i] << " ";
	return 0;
}
