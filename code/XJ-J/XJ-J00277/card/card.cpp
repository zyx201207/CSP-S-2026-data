#include<cstdio>
int n,m;
int a[510000],ans[310000],p[310000];
bool flag[310000];
int main()
{
	int i,j;
    FILE *in = fopen("card.in","r");
    FILE *out = fopen("card.out","w");
	fscanf(in,"%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		fscanf(in,"%d",&a[i]);
	}
	for(i=i;i>=1;i--)
	{
		if(p[a[i]]!=0)
		{
			for(j=i+1;j<=p[a[i]];j++)
			{
				ans[a[j]]+=p[a[j]]-i;
				flag[a[j]]=false;
			}
		}
		p[a[i]]=i;
		flag[a[i]]=true;
	}
	for(i=1;i<=m;i++)
	{
		if(flag[i])
		{
			ans[i]+=p[i];
		}
	}
	for(i=1;i<=m;i++)
	{
		fprintf(out,"%d ",ans[i]);
	}
	return 0;
}
