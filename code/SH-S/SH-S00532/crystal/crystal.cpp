#include<bits/stdc++.h>
using namespace std;
long long m,n,maxn=-1,ma,b[5000001],fl[1000001],cs=0;

void f( int step,int tar)
{
	if (step==0 || cs==0)
	{
		for(int i=0;i<n;i++)
		{
			if(b[i]==tar)
			{
				ma++;
			}
		} 
		if(ma>maxn)
		{
			maxn=ma;
		}
		tar=-1;
		ma=0;
		return;
	}
	for(int i=0;i<n;i++)
	{
		
		if(b[i]<tar)
		{
			b[i]++;
			f(--step,tar);
		}
	}
	
}

int main()
{
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
	scanf("%d %d",&n,&m);
	int a[n];
	cs=n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		f(m,a[i]);
		for(int i=0;i<n;i++)
		{
			b[i]=a[i];
		}
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
