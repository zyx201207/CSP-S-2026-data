#include<bits/stdc++.h>
using namespace std;
int n,m,T;
int a[500010];
int q[500010];
struct node{
	int s;
	bool x;
}vis[300010];
bool ansa[300010];
int ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d", &n, &m);
	T=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
	}
	for(int k=1;k<=T;k++)
	{
		memset(vis,0,sizeof(vis));
		memset(q,0,sizeof(q));
		memset(ansa,0,sizeof(ansa));
		int t=0;
		for(int i=k;i<=n;i++)
		{
			t++;
			q[t]=a[i];
			if(vis[a[i]].x==1)
			{
				t=vis[a[i]].s;
			}
			vis[a[i]].x=1;
			vis[a[i]].s=t;
		}
		for(int i=1;i<=t;i++)
		{
			ansa[q[i]]=1;
		}
		for(int i=1;i<=m;i++)
		{
			ans[i]+=ansa[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
  return 0;
}