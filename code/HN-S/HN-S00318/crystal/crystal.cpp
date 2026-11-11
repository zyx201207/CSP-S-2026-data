#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,count=0,num=0;
	scanf("%d %d",&n,&m);
	int a[n]={0};
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i]) swap(a[i],a[j]);
		}
	}
	while(m>0)
	{	
		if(m>=(num+1)*(a[num+1]-a[num]))
		{
			m-=(num+1)*(a[num+1]-a[num]);
			a[num]=a[num+1];
			num++;
		}
		else break;
	}
	printf("%d",num+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
