#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500100];
bool vis[300100];
int pre[500100];
int zhi[500100];
int ans[300100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,false,sizeof(vis));
		memset(pre,0,sizeof(pre));
		memset(zhi,0,sizeof(zhi));
		int cnt=1,pre1=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==false)
			{
				vis[a[j]]=true;
				zhi[cnt]=a[j];
				pre[cnt]=pre1;
				pre1=cnt;
				cnt++;
			}
			else if(vis[a[j]]==true)
			{
				int k=cnt-1;
				while(zhi[k]!=a[j])
				{
					vis[zhi[k]]=false;
					k=pre[k];
				}
				pre1=pre[k];
				zhi[cnt]=a[j];
				pre[cnt]=pre1;
				pre1=cnt;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i]==true)
			{
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
