#include<bits/stdc++.h>
using namespace std;
int a[200005];
int cnt[35];
int vis[35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=30;j>=0;j--)
		{
			if(a[i]&(1<<j))
			{
				cnt[j]++;
				if(cnt[j]>=m)
				{
					vis[j]=1;
					mx=max(mx,j);
				}
			}
		}
	}
	if(mx==-1)
	{
		puts("0");
		return 0;
	}
	int ans=(1<<mx);
	for(int j=mx;j>=0;j--)
	{
		if(vis[j])
		{
			int nw=0;
			for(int i=1;i<=n;i++)
			{
				if((a[i]&ans)==ans)
				{
					if(a[i]&(1<<j))
					{
						nw++;
					}
				}
			}
			if(nw>=m)
			{
				ans|=(1<<j);
			}
		}
	}
	printf("%d\n",ans);
		
}