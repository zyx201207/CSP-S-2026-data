#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],ans[500005],num[500005],vis[500005],h[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	bool flag=true;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		h[a[i]]++;
		if(i!=1&&a[i]>a[i-1])flag=false;
	}
	if(flag==true)
	{
		for(int i = 1;i<=m;i++)
		{
			cout << h[i]+h[i-1] << " ";
			h[i]+=h[i-1];
		}
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		int cnt=0,w=0;
		memset(vis,0,sizeof(vis));
		for(int j = i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				vis[a[j]]=j-i-w+1;
				ans[++cnt]=a[j];
			}
			else
			{
				for(int k = vis[a[j]]+1;k<=cnt;k++)
				{
					if(vis[ans[k]]>=k&&vis[ans[k]]<=cnt)
					{
						vis[ans[k]]=0;
					}
				}
				w=w+cnt-vis[a[j]]+1;
				cnt=vis[a[j]];
			}
		}
		for(int j = 1;j<=cnt;j++)
		{
			num[ans[j]]++;
		}
	}
	for(int i = 1;i<=m;i++)cout << num[i]<<" ";
	return 0;
}
