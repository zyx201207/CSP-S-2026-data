#include<bits/stdc++.h>
using namespace std;
int a[500005],lt[500005],ans[300005],vis[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i;i--)
		if(!lt[a[i]])
			lt[a[i]]=i;
	for(int i=1;i<=n;i++)
		vis[i]++;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		if(vis[i])
		{
			for(int j=i;j<=n;j++)
			{
				cnt+=vis[j];
				vis[j]=0;
				ans[a[j]]+=cnt;
				j=lt[a[j]];
			}
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
}