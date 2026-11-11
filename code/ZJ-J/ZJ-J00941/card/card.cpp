#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],ans[300007];
int vis[300007],cnt[300007],la[300007],d[500007];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		la[a[i]] = i;
		cnt[a[i]]++;
	}
	for(int i = n;i >= 1;i--)
	{
		if(vis[a[i]])continue;
		d[i] += cnt[a[i]];
		vis[a[i]] = 1;
	}
	for(int i = 1;i < n;i++)
	{
		if(i != la[a[i]])d[la[a[i]]] += d[i];
		else d[i+1] += d[i];
	}
	memset(vis,0,sizeof(vis));
	for(int i = n;i >= 1;i--)
	{
		if(vis[a[i]])continue;
		ans[a[i]] = d[i];
		vis[a[i]] = 1;
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
