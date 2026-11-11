#include<bits/stdc++.h>
using namespace std;
int n,m,ma,a[200010],b[30],sum;
void dfs(int k,int ans)
{
	if(k>n)
	{
		if(ans!=m) return;
		sum=b[1];
		for(int i=2;i<=m;i++) sum=sum&b[i];
		ma=max(sum,ma);
		return;
	}
	if(ans==m) k+=20;
	b[ans+1]=a[k];
	dfs(k+1,ans+1);
	dfs(k+1,ans);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=20)
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		dfs(1,0);
		printf("%d\n",ma);
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			for(int i=1;i<=n;i++)
			{
				int x;
				scanf("%d",&x);
				ma=max(ma,x);
			} 
			printf("%d\n",ma);
		}
		else if(m==n)
		{
			scanf("%d",&sum);
			for(int i=2;i<=n;i++)
			{
				int x;
				scanf("%d",&x);
				sum=sum&x;
			} 
			printf("%d\n",sum);
		}
		else
		{
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					ma=max(ma,a[i]&a[j]);	
				} 
			} 
			printf("%d\n",ma);
		}
	}
	else
	{
		printf("0\n"); 
		return 0;
	}
}
