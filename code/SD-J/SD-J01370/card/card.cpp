#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int la[300005];
int S[300005];
void game(int f)
{
	memset(la,0,sizeof(la));
	int top=0;
	for(int i=f;i<=n;i++)
	{
		if(la[a[i]]==0)
		{
			la[a[i]]=top+1;
			S[++top]=a[i];
		}
		else
		{
			for(int j=la[a[i]]+1;j<=top;j++)
			{
				la[S[j]]=0;
			}
			top=la[a[i]];
		}
	}
	for(int i=1;i<=top;i++)
	{
		ans[S[i]]++;
	}
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
	for(int T=1;T<=n;T++)
	{
		game(T);
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
