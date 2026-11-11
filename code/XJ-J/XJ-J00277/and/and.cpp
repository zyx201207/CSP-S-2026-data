#include<cstdio>
int n,m,ans;
int a[210000];
bool flag[210000];
int dg(int d,int num)
{
	int i;
	if(d>m)
	{
		if(ans<num)
		{
			ans=num;
		}
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			if(num==0)
			{
				flag[i]=true;
				dg(d+1,a[i]);
				flag[i]=false;
			}
			else
			{
				flag[i]=true;
				dg(d+1,num&a[i]);
				flag[i]=false;
			}
		} 
	}
	return 0;
}
int main()
{
	int i,j;
    FILE *in = fopen("and.in","r");
    FILE *out = fopen("and.out","w");
    fscanf(in,"%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
    	fscanf(in,"%d",&a[i]);
	}
	dg(1,0);
	fprintf(out,"%d",ans);
	return 0;
}
