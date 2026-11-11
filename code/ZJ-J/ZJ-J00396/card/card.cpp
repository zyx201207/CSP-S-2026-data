#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+10;
int n,m;
int st[mx],tot,a[mx];
int vis[mx],ans[mx];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			vis[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]>0)
			{
				while(tot>0 && st[tot]!=a[j])
				{
					vis[st[tot]]--;
					tot--;
				}
				vis[st[tot]]--;
				tot--;			
			}
			vis[a[j]]++;
			st[++tot]=a[j];
		}
		while(tot>0)
		{
			ans[st[tot]]++;
			tot--;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}