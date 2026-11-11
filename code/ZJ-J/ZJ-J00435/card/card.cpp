#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt[500005];
int a[500005],t;
int b[500005];
int vis[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int lu=1;lu<=n;lu++)
	{
		t=0;
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int i=lu;i<=n;i++)
		{
			if(vis[a[i]]&&vis[a[i]]<=t&&b[vis[a[i]]]==a[i])
			{
				t=vis[a[i]];
			}
			else
			{
				b[++t]=a[i];
				vis[a[i]]=t;
			}
		}
		for(int i=1;i<=t;i++)
		{
			cnt[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",cnt[i]);
	}
	return 0;
}