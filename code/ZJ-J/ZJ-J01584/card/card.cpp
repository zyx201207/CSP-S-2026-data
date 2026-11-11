#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int cur[500010];
bool vis[500010];
int len=0;
int cnt[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		//memset(cur,0,sizeof(cur));
		for(int i=1;i<=len+1;i++)cur[i]=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				vis[a[j]]=true;
				cur[++len]=a[j];
			}
			else 
			{
				while(a[len]!=a[j])
				{
					vis[a[len]]=false;
					cur[len]=0;
					len--;
				}
				vis[a[len]]=false;
				cur[len]=0;
				len--;
				vis[a[j]]=true;
				cur[++len]=a[j];
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i])
			{
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",cnt[i]);
	}
	return 0;
}