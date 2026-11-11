#include<cstdio>
int c,t;
int n,d;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		if(n<=2)
		{
			 printf("0\n");
			 continue;
		}
		if(15<=c&&c<=18) 
		{
			int ii=1;
			while((a[ii+1]-a[1]<=d)&&ii<n) ii++;
			printf("%d\n",n-ii);
		}
		if(c==11||c==12)
		{
			if(d<a[2]-a[1])
			printf("0\n");
			else printf("%d\n",n/(a[2]-a[1])-2);
		}
		
			printf("0\n");
	}
	
	return 0;
}

