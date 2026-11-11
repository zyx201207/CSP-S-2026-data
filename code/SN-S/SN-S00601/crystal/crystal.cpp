#include<stdio.h>
#include<cstdio>
using namespace std;
int n,m,k;
int jie,ans=0;
int gdj;
int a[10005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	/*for(int i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1]) jie=a[i];
		else jie=a[i+1];
	}*/
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
		}
	}//for(int i=0;i<n;i++) printf("%d ",a[i]);
	while(m>0)
	{
		
		//for(int i=0;i<n-1;i++)
		//{
			int z=1;
			if(a[0]==a[1]) z++;
			for(int j=0;j<z;j++)
			{
				a[j]++;m--;
				//printf("%d ",m);
			}
		//}
		//for(int i=0;i<n;i++) printf("%d ",a[i]);
		//("\n");
	}
	for(int i=0;i<n-1;i++)
	{
		
		if(a[i]==a[1]) ans++;
	//	printf("%d ",ans);
	}
	printf("%d",ans);
	return 0;
}
