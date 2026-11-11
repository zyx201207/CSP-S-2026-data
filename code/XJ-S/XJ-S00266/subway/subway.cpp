#include<cstdio>
int c,n,m,d,q,tb[1010],ta[1010][1010],ans,min;
void dfs(int a,int b)
{
	int f=0,i;
	if(ta[a][b]!=0||f==1) 
	{
		ans=ans+ta[a][b];
		f=1;
		if(ans<min) min=ans;
		return ;
	}
	for(i=1;i<=m;i++)
	{
		if(ta[a][i]!=0)
		{
			ans=ans+ta[a][i];
			dfs(i,b);
			ans=ans-ta[a][i];
		} 
		if(ta[i][b]!=0)
		{
			ans=ans+ta[i][b];
			dfs(a,i);
			ans=ans-ta[i][b];
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,p,a,b,l,t,s,at;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&tb[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		scanf("%d%d",&a,&b);
		l=a;t=b;
		s=a;at=b;
		for(j=1;j<=p-1;j++)
		{
			scanf("%d%d",&a,&b);
			ta[l][a]=t+b;
			at=at+b;
			l=a;t=b;
			ta[s][a]=at;
		}
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		ans=0;
		ans=ans+tb[a]+tb[b];
		if(ta[a][b]!=0) printf("%d\n",ans+ta[a][b]);
		else
		{
			min=1000000;
			dfs(a,b);
			printf("%d\n",min);
		}
	}
	return 0;
 } 
