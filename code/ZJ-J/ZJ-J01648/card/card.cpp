#include<bits/stdc++.h>
using namespace std;
typedef unsigned u;
u n,m,vis[500010],pos[300010],cnt=1;
int ans[300010];
bool flag[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%u%u",&n,&m);
	for(u i=1;i<=n;i++)
	{
		scanf("%u",&vis[i]);
	}
	for(u i=n;i;i--)
	{
		if(!pos[vis[i]])
		{
			ans[vis[i]]-=cnt;
			flag[vis[i]]=true;
			pos[vis[i]]=i;
			cnt++;
		}
		else if(vis[i]==vis[i+1]){cnt++;}
		else
		{
			for(u i=1;i<=m;i++)
			{
				if(flag[i])
				{
					ans[i]+=cnt;
				}
			}
			memset(flag,0,sizeof(flag));
			cnt=1;
			for(u j=i;j<=n;)
			{
				flag[vis[j]]=true;
				if(pos[vis[j]]){j=pos[vis[j]]+1;}
				else{j++;}
			}
		}
	}
	for(u i=1;i<=m;i++)
	{
		if(flag[i])
		{
			ans[i]+=cnt;
		}
	}
	for(u i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}