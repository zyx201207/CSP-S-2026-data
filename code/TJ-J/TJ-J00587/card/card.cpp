#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int n,m,a[MAXN],ans[MAXM],vis[MAXM],b[MAXN];
void f()
{
	for(int i=1;i<=n;i++)
		b[i]=a[i];
}
void f_(int i,int j)
{
	for(int k=i;k<j;k++)
		b[k]=-1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		f();
		for(int j=i;j<=n;j++)
		{
			if(vis[b[j]])
				f_(vis[b[j]],j);
			vis[b[j]]=j;
		}
		for(int j=i;j<=n;j++)
			if(b[j]!=-1)
				ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
